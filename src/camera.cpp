#include <iostream>
#include <cstdio>
#include <QObject>
#include "camera.hpp"
#include "cassebriques.hpp"

using namespace cv;
using namespace std;

Camera::Camera(CasseBriques* casseBriques)
{
    m_casseBriques = casseBriques;
    m_active = false;
    m_translation = 0.0f;
    setFixedSize(320,240);

    initialiserCamera();

    QObject::connect(&m_timerCam,  &QTimer::timeout, [&] {
        capturerImage();
    });
    m_timerCam.setInterval(70);
}

Camera::~Camera() {}

void Camera::initialiserCamera()
{
    int frameWidth=320;
    int frameHeight=240;
    int subImageWidth=100;
    int subImageHeight=100;
    int templateWidth=25;
    int templateHeight=25;
    workingRect = Rect((frameWidth-subImageWidth)/2,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
    templateRect = Rect((workingRect.width-templateWidth)/2,(workingRect.height-templateHeight)/2,templateWidth,templateHeight);
    workingCenter = Point(workingRect.x+subImageWidth/2,workingRect.y+subImageHeight/2);

    cap = cv::VideoCapture(0); // open the default camera
    cap.set(CV_CAP_PROP_FRAME_WIDTH,frameWidth);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight);
    if(!cap.isOpened())  // check if we succeeded
    {
        cerr<<"Error openning the default camera"<<endl;
    }

    // Get frame1
    cap >> frame1;
    // Mirror effect
    cv::flip(frame1,frame1,1);
    // Extract rect1 and convert to gray
    cv::cvtColor(cv::Mat(frame1,workingRect),frameRect1,COLOR_BGR2GRAY);
    //Mat(frame1,rect).copyTo(frameRect1);

    // Create the matchTemplate image result
    //cv::Mat resultImage;    // to store the matchTemplate result
    int result_cols =  frame1.cols-templateWidth  + 1;
    int result_rows = frame1.rows-templateHeight + 1;
    resultImage.create( result_cols, result_rows, CV_32FC1 );
}

void Camera::capturerImage()
{
    if (m_active)
    {
        // Get frame2
        cap >> frame2;
        // Mirror effect
        cv::flip(frame2,frame2,1);
        // Extract working rect in frame2 and convert to gray
        cv::cvtColor(cv::Mat(frame2,workingRect),frameRect2,COLOR_BGR2GRAY);

        // Extract template image in frame1
        cv::Mat templateImage(frameRect1,templateRect);
        // Do the Matching between the working rect in frame2 and the templateImage in frame1
        matchTemplate( frameRect2, templateImage, resultImage, TM_CCORR_NORMED );
        // Localize the best match with minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);
        // Compute the translation vector between the origin and the matching rect
        Point vect(maxLoc.x-templateRect.x,maxLoc.y-templateRect.y);

        // Draw green rectangle and the translation vector
        rectangle(frame2,workingRect,Scalar( 0, 255, 0),2);
        Point p(workingCenter.x+vect.x,workingCenter.y+vect.y);
        arrowedLine(frame2,workingCenter,p,Scalar(255,255,255),2);

        // Display frame2
        //imshow("WebCam", frame2);

        // Swap matrixes
        swap(frameRect1,frameRect2);

        setPixmap(QPixmap::fromImage(QImage(frame2.data, frame2.cols, frame2.rows,frame2.step, QImage::Format_RGB888)));
        setScaledContents(true);

        if (m_buffer.size() > 20)
        {
            m_translation += vect.x;
            m_buffer.push(vect.x);
            m_translation -= m_buffer.front();
            m_buffer.pop();
        }
        else
        {
            m_translation += vect.x;
            m_buffer.push(vect.x);
        }
    }
}

void Camera::stop()
{
    m_timerCam.stop();
}

void Camera::start()
{
    m_timerCam.start();
}

void Camera::setActive(const bool active)
{
    m_active = active;
    if (m_active == true)
        start();
    else
        stop();
}

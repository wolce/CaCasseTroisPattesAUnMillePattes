#ifndef CAMERA_H
#define CAMERA_H

#include <QTimer>
#include <QLabel>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

class Camera : public QLabel
{
    Q_OBJECT
public:
    Camera();
    ~Camera();
    void initialiserCamera();
    void stop();
    void start();
    void capturerImage();
    bool getActive() const {return m_active;}
    void setActive(const bool active);

private:
    bool m_active;
    QTimer m_timerCam;
    cv::VideoCapture cap;
    cv::Mat frame1, frame2, frameRect1, frameRect2;
    cv::Mat resultImage;
    cv::Rect workingRect;
    cv::Rect templateRect;
    cv::Point workingCenter;
};

#endif // CAMERA_H

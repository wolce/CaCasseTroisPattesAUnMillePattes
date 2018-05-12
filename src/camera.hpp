#ifndef CAMERA_H
#define CAMERA_H

#include <QTimer>
#include <QLabel>
#include <queue>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

class CasseBriques;

class Camera : public QLabel
{
    Q_OBJECT
public:
    Camera(CasseBriques* casseBriques);
    ~Camera();
    void initialiserCamera();
    void stop();
    void start();
    void capturerImage();
    bool getActive() const {return m_active;}
    void setActive(const bool active);
    float getTranslation() const {return m_translation/20.0f;}

private:
    CasseBriques* m_casseBriques;
    bool m_active;
    QTimer m_timerCam;
    std::queue<float> m_buffer;
    float m_translation;

    cv::VideoCapture cap;
    cv::Mat frame1, frame2, frameRect1, frameRect2;
    cv::Mat resultImage;
    cv::Rect workingRect;
    cv::Rect templateRect;
    cv::Point workingCenter;
};

#endif // CAMERA_H

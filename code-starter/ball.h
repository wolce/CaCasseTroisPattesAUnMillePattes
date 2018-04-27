#ifndef BALL_H
#define BALL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <QtOpenGL>
#include <GL/glu.h>

class ball
{
public:
    ball();
    virtual ~ball();
    void Display(float x, float y);
private:
    GLUquadric *m_quadrique=nullptr;
};

#endif // BALL_H

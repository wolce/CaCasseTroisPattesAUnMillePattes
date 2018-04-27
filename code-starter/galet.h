#ifndef GALET_H
#define GALET_H

#include <QObject>
#include <QWidget>
#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <QtOpenGL>
#include <GL/glu.h>


class galet
{
public:
    galet();
    virtual ~galet();
    void Display(float position,float distance);
private:
    float m_position;
    float m_distance;
};

#endif // GALET_H

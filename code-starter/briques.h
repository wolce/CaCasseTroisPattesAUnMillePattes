#ifndef BRIQUES_H
#define BRIQUES_H

#include <QWidget>
#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <QtOpenGL>
#include <GL/glu.h>

class Briques
{
public:
    Briques(float x, float y, bool Zbuffer);
    // Destructeur
    virtual ~Briques();
    void Display();
private:
    int m_nombreDeBriques;
    float m_x;
    float m_y;
    bool m_Zbuffer;
};

#endif // BRIQUES_H

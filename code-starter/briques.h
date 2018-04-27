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
    Briques();
    // Destructeur
    virtual ~Briques();
    void Display(float x, float y);
private:
    int m_nombreDeBriques;
};

#endif // BRIQUES_H

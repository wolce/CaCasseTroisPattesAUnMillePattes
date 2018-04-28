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
    int getZbuffer() const{return m_Zbuffer;}
    int getX() const{return m_x;}
    int getY() const{return m_y;}
    void changeZbuffer();
private:
    bool m_Zbuffer;
    int m_nombreDeBriques;
    float m_x;
    float m_y;

};

#endif // BRIQUES_H

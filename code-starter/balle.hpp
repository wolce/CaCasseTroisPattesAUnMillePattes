#ifndef BALLE_H
#define BALLE_H

#include <GL/glu.h>

class Balle
{
public:
    Balle();
    virtual ~Balle();
    void Display(float x, float y);
private:
    GLUquadric *m_sphere;
    float m_rayon;
    float m_couleur[3];
};

#endif // BALLE_H

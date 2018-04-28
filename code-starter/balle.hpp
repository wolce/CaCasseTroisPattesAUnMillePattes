#ifndef BALLE_H
#define BALLE_H

#include <GL/glu.h>

class Balle
{
public:
    Balle();
    ~Balle();
    void Display(const float x, const float y);
private:
    GLUquadric *m_sphere;
    float m_rayon;
    float m_couleur[3];
};

#endif // BALLE_H

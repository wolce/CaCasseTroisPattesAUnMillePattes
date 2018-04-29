#ifndef BALLE_H
#define BALLE_H

#include <GL/glu.h>

class Balle
{
public:
    Balle();
    ~Balle();
    void Display();
    void setDirection(const float x, const float y) {m_direction[0]=x;m_direction[1]=y;}
    void setCentre(const float x, const float y) {m_positionCentre[0]=x;m_positionCentre[1]=y;}
private:
    GLUquadric *m_sphere;
    float m_rayon;
    float m_couleur[3];
    float m_vitesse;
    float m_direction[2]; // un vecteur de coord. x et y dont les valeurs sont entre 0 et 1
    float m_positionCentre[2];
};

#endif // BALLE_H

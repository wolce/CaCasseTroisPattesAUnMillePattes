#ifndef BALLE_H
#define BALLE_H

#include <GL/glu.h>

class Palet;

class Balle
{
public:
    Balle(float x, float y, float dirX, float dirY);
    Balle(Palet *palet);
    ~Balle();
    void Display();
    void setDirection(const float x, const float y) {m_direction[0]=x;m_direction[1]=y;}
    float getDirectionX() const {return m_direction[0];}
    float getDirectionY() const {return m_direction[1];}
    float getCentreX() const {return m_positionCentre[0];}
    float getCentreY() const {return m_positionCentre[1];}
    float getRayon() const {return m_rayon;}
    bool getEstSurPalet() const {return m_estSurPalet;}
    void setEstSurPalet(bool etat) {m_estSurPalet = etat;}
    void deplacer();
    void setCentreX(float x) {m_positionCentre[0] = x;}

private:
    GLUquadric *m_sphere;
    float m_rayon;
    float m_couleur[3];
    float m_vitesse;
    float m_direction[2]; // un vecteur de coord. x et y dont les valeurs sont entre 0 et 1
    float m_positionCentre[2];
    bool m_estSurPalet;
};

#endif // BALLE_H

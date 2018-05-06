#ifndef PALET_H
#define PALET_H

#include <GL/glu.h>
#include "bloc.hpp"

class Palet : public Bloc
{
public:
    Palet(float x, float y, float largeur, float hauteur, float xMin, float xMax);
    virtual ~Palet();
    virtual void Display();
    virtual bool collision(Balle* &balle);
    virtual void traiterCollision(Balle* &balle);
    void decaler(const float x, const float y); // Applique une translation au palet
private:
    float m_vitesse;
    float m_position[2]; // Position du centre
    float m_largeur;
    float m_hauteur;
    float m_xMin;
    float m_xMax;
    unsigned int m_angleMin; // L'angle maximal dont peut dévier la balle en touchant le palet
};

#endif // PALET_H

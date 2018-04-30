#ifndef PALET_H
#define PALET_H

#include <GL/glu.h>
#include "bloc.hpp"

class Palet : public Bloc
{
public:
    Palet(float x, float y, float largeur, float hauteur);
    virtual ~Palet();
    virtual void Display();
    virtual bool collision(Balle *balle);
    void traiterCollision(Balle *balle);
    void decaler(const float x, const float y); // Applique une translation au palet
private:
    float m_vitesse;
    float m_position[2]; // Position du centre
    float m_largeur;
    float m_hauteur;
};

#endif // PALET_H

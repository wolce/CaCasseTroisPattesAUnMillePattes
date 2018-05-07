#ifndef BRIQUE_H
#define BRIQUE_H

#include <GL/glu.h>
#include "balle.hpp"
#include "bloc.hpp"

class Brique : public Bloc
{
public:
    Brique(float x, float y, float largeur);
    virtual ~Brique();
    virtual void Display();
    virtual bool collision(Balle* &balle);
    virtual void traiterCollision(Balle* &balle);
private:
    float m_position[2]; // Position du coin supérieur gauche
    float m_largeur;
    float m_hauteur;
};

#endif // BRIQUE_H

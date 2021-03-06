#ifndef BRIQUE_H
#define BRIQUE_H

#include "bloc.hpp"

class Balle;

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

};

#endif // BRIQUE_H

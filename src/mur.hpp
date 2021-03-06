#ifndef MUR_H
#define MUR_H

#include "bloc.hpp"

class Balle;

class Mur : public Bloc
{
public:
    Mur(float p[][2], int type, float coord);
    virtual ~Mur();
    virtual void Display();
    virtual bool collision(Balle* &balle);
    virtual void traiterCollision(Balle* &balle);
private:
    int m_type; // gauche = 1 / droite = 2 / haut = 3
    float m_coord; // valeur de x ou y que la balle ne doit pas dépasser
    bool m_visible;
};

#endif // MUR_H

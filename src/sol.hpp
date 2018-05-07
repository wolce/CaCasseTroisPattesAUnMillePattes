#ifndef SOL_H
#define SOL_H

#include "bloc.hpp"
#include "balle.hpp"

class Sol : public Bloc
{
public:
    Sol(float p[][2], float coord);
    virtual ~Sol();
    virtual void Display();
    virtual bool collision(Balle* &balle);
    virtual void traiterCollision(Balle* &balle);
private:
    float m_coord; // valeur de x ou y que la balle ne doit pas dépasser
    bool m_visible;
};

#endif // SOL_H

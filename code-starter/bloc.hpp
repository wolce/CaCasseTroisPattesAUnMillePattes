#ifndef BLOC_HPP
#define BLOC_HPP

#include <GL/glu.h>
#include <vector>
#include "balle.hpp"

class Bloc
{
public:
    Bloc();
    virtual ~Bloc();
    virtual void Display() = 0;
    virtual bool collision(Balle *balle) = 0;
    virtual void traiterCollision(Balle *balle) = 0;
protected:
    float m_points[4][2]; // Contient tous les points du bloc, sous la forme x1,y1,x2,y2,x3,y3,x4,y4
    float m_couleurs[3];
};

#endif // BLOC_HPP

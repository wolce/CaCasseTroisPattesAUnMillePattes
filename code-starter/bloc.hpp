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
    virtual void Display();
    void decaler(const float x, const float y); // Applique une translation au bloc
    virtual bool collision(Balle *balle);
protected:
    float m_points[4][2]; // Contient tous les points du bloc, sous la forme x1,y1,x2,y2,x3,y3,x4,y4
    //std::vector<std::vector<int>> m_cotesSpeciaux; // Contient les numéros des points définissant les côtés du bloc qui entraînent une action lorsque la balle les touche
    float m_couleurs[3];
};

#endif // BLOC_HPP

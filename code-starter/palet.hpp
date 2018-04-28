#ifndef PALET_H
#define PALET_H

#include <GL/glu.h>


class Palet
{
public:
    Palet();
    virtual ~Palet();
    void Display();
    void decaler(const float x, const float y); // Applique une translation au palet
private:
    float m_couleur[3];
    float m_largeur;
    float m_epaisseur;
    float m_position[2]; // Position du centre du palet
};

#endif // PALET_H

#ifndef BORD_H
#define BORD_H

#include <GL/glu.h>

class Bord
{
public:
    Bord();
    virtual ~Bord();
    void Display();
    float getPosition() const {return m_position;}
    float getOrientation() const {return m_orientation;}
private:
    float m_epaisseur;
    float m_largeur;
    bool m_visible; // Le bord du bas n'est pas visible par exemple
    float m_position; // Valeur selon x (si vertical) ou y (si horizontal) du côté "efficace" du bord, ie celui le plus proche de la balle
    int m_orientation; // 0 = horizontal et 1 = vertical
    float m_couleur[3];
};

#endif // BORD_H

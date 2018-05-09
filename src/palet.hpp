#ifndef PALET_H
#define PALET_H

#include "bloc.hpp"

class Balle;

class Palet : public Bloc
{
public:
    Palet(float x, float y, float largeur, float hauteur, float xMin, float xMax);
    virtual ~Palet();
    virtual void Display();
    virtual bool collision(Balle* &balle);
    virtual void traiterCollision(Balle* &balle);
    void decaler(const float x, const float y); // Applique une translation au palet
    float getCentreX() const {return m_position[0];}
    float getCentreY() const {return m_position[1];}
    float getHauteur() const {return m_hauteur;}
    float getVitesse() const {return m_vitesse;}
    float getAngleMin() const {return m_angleMin;}
    void setLargeur(float largeur);
private:
    float m_vitesse;
    float m_position[2]; // Position du centre
    float m_largeur;
    float m_hauteur;
    float m_xMin;
    float m_xMax;
    float m_angleMin; // L'angle maximal dont peut dévier la balle en touchant le palet
};

#endif // PALET_H

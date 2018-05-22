#ifndef PALET_H
#define PALET_H

#include "bloc.hpp"

class Balle;

class Palet : public Bloc
{
public:
    /**********************************/
    /***CONSTRUCTEUR et DETRUCTEUR*****/
    /**********************************/

    Palet(float x, float y, float largeur, float hauteur, float xMin, float xMax);
    /*nous rentrons les valeur du milieu du palet x et y , la largeur du palet,
    sa hauteur, et les valeur en xMin et xMax où un contact avec la balle se produira*/

    virtual ~Palet();

    /**********************************/
    /************METHODES**************/
    /**********************************/

    virtual void Display();// on affiche dans notre OpenGL notre GL_QUADS
    virtual bool collision(Balle* &balle);//prend en entré la balle pour récupérer ca position et renvoi le booléen TRUE si il y a collision
    virtual void traiterCollision(Balle* &balle);//prend en entrée la balle pour récupérer ca position et pour changer la direction de la balle lors d'une collision
    void decaler(const float x, const float y); // Applique une translation au palet
    float getCentreX() const {return m_position[0];}
    float getCentreY() const {return m_position[1];}
    float getHauteur() const {return m_hauteur;}
    float getVitesse() const {return m_vitesse;}
    float getAngleMin() const {return m_angleMin;}
    void setLargeur(float largeur);
    void setCentreX(float positionCentreX);
    float getLargeur() const {return m_largeur;}
private:
    /**********************************/
    /************VARIABLES*************/
    /**********************************/
    float m_vitesse;//vitesse de la balle
    float m_position[2]; // Position du centre
    float m_xMin;
    float m_xMax;
    float m_angleMin; // L'angle maximal dont peut dévier la balle en touchant le palet
    int m_codeDerniereCollision; // 1 : gauche / 2 : haut / 3 : droite / 0 : pas de collision
};

#endif // PALET_H

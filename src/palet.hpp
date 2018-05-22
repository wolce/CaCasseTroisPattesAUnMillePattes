#ifndef PALET_H
#define PALET_H

#include "bloc.hpp"

class Balle;

class Palet : public Bloc
{
public:
    /*******************************/
    /* Constructeur et destructeur */
    /*******************************/

    /* Nous rentrons les valeurs du milieu du palet x et y, la largeur du palet,
    sa hauteur, et les valeurs en abscisse xMin et xMax que le palet ne doit
    pas dépasser (il ne doit pas traverser les murs) */
    Palet(float x, float y, float largeur, float hauteur, float xMin, float xMax);

    // Destructeur
    virtual ~Palet();

    /**************************************/
    /* Méthodes virtuelles pures héritées */
    /**************************************/

    /* Pour plus de détails, voir les commentaires du header de la classe Bloc */
    virtual void Display();
    virtual bool collision(Balle* &balle);
    virtual void traiterCollision(Balle* &balle);

    /*********************/
    /* Setters & Getters */
    /*********************/

    // Coordonnées du centre du palet
    float getCentreX() const {return m_position[0];}
    float getCentreY() const {return m_position[1];}
    void setCentreX(float positionCentreX);

    // Hauteur et largeur
    float getHauteur() const {return m_hauteur;}
    float getLargeur() const {return m_largeur;}
    void setLargeur(float largeur);

    // Vitesse du palet lors du déplacement (utile pour le clavier)
    float getVitesse() const {return m_vitesse;}

    // Angle minimal de rebond quand la balle atterie sur un côté extrême du palet
    float getAngleMin() const {return m_angleMin;}

    /**********************/
    /* Mouvement du palet */
    /**********************/

    /* Permet de déplacer le palet en prenant en compte les murs. On appelle
     * cette fonction via la fonction deplacerPalet() du CasseBriques à chaque
     * fois qu'on utilise le clavier, la caméra ou la souris pour déplacer le palet */
    void decaler(const float x, const float y);

private:
    /*************/
    /* Attributs */
    /*************/
    float m_vitesse;//vitesse de la balle
    float m_position[2]; // Position du centre
    float m_xMin;
    float m_xMax;
    float m_angleMin; // L'angle maximal dont peut dévier la balle en touchant le palet
    int m_codeDerniereCollision; // 1 : gauche / 2 : haut / 3 : droite / 0 : pas de collision
};

#endif // PALET_H

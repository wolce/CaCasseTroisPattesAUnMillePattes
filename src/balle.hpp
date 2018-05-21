#ifndef BALLE_H
#define BALLE_H

#include <GL/glu.h>

class Palet;

class Balle
{
public:

    /*******************************/
    /* Constructeurs & Destructeur */
    /*******************************/

    // Constructeur pouvant servir au debug (inutile actuellement)
    Balle(float x, float y, float dirX, float dirY);

    // Constructeur utilisé dans le programme
    Balle(Palet *palet, int niveau);

    // Destructeur
    ~Balle();

    /*********************/
    /* Setters & Getters */
    /*********************/

    // Direction de la balle
    void setDirection(const float x, const float y) {m_direction[0]=x;m_direction[1]=y;}
    float getDirectionX() const {return m_direction[0];}
    float getDirectionY() const {return m_direction[1];}

    // Centre de la balle
    float getCentreX() const {return m_positionCentre[0];}
    float getCentreY() const {return m_positionCentre[1];}
    void setCentreX(float x) {m_positionCentre[0] = x;}
    void setCentreY(float y) {m_positionCentre[1] = y;}

    // Rayon de la balle
    float getRayon() const {return m_rayon;}

    // Etat de la balle : est-elle sur le palet ?
    bool getEstSurPalet() const {return m_estSurPalet;}
    void setEstSurPalet(bool etat) {m_estSurPalet = etat;}

    /***************/
    /* Déplacement */
    /***************/

    void deplacer();
    void envoyerBalle();

    // Affichage de la balle
    void Display();

private:

    GLUquadric *m_sphere; // Quadrique permettant d'afficher la sphère
    float m_rayon;
    float m_couleur[3];
    float m_vitesse;
    float m_direction[2]; // un vecteur de coord. x et y dont les valeurs sont entre 0 et 1
    float m_positionCentre[2];
    bool m_estSurPalet;
};

#endif // BALLE_H

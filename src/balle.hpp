#ifndef BALLE_H
#define BALLE_H

#include <GL/glu.h>

class Palet;

/* Cette classe prend en charge la gestion de la balle. C'est-à-dire
 * son mouvement, son affichage, son envoi initial. Elle permet aussi
 * l'interaction avec toutes les autres classes, à l'aide de nombreux
 * setters et getters. */

class Balle
{
public:

    /*******************************/
    /* Constructeurs & Destructeur */
    /*******************************/

    /* Constructeur pouvant servir au debug (inutile actuellement).
     * Il permet de créer une balle à un endroit précis, et qui se
     * déplace dans une direction précise */
    Balle(float x, float y, float dirX, float dirY);

    /* Constructeur utilisé dans le programme.
     * palet : le palet sur lequel doit se situer la balle au démarrage
     * niveau : niveau en cours pour déterminer la vitesse */
    Balle(Palet *palet, int niveau);

    // Destructeur
    ~Balle();

    /*********************/
    /* Setters & Getters */
    /*********************/

    /* Il y a beaucoup de setters et de getters car cette classe est
     * celle qui est le plus en relation avec les autres classes */

    /* Direction de la balle : toutes les directions sont situées
     * entre 0 et 1. Elles sont déterminées par des cosinus/sinus */
    void setDirection(const float x, const float y) {m_direction[0]=x;m_direction[1]=y;}
    float getDirectionX() const {return m_direction[0];}
    float getDirectionY() const {return m_direction[1];}

    /* Centre de la balle : utile pour détecter les collisions (get)
     * ou pour déplacer la balle si le palet vient la percuter
     * sur le côté par exemple (set) */
    float getCentreX() const {return m_positionCentre[0];}
    float getCentreY() const {return m_positionCentre[1];}
    void setCentreX(float x) {m_positionCentre[0] = x;}
    void setCentreY(float y) {m_positionCentre[1] = y;}

    // Rayon de la balle : utile pour détecter les collisions
    float getRayon() const {return m_rayon;}

    /* Etat de la balle : est-elle sur le palet ? Sert à savoir
     * si l'on doit déplacer la balle avec le palet par exemple */
    bool getEstSurPalet() const {return m_estSurPalet;}
    void setEstSurPalet(bool etat) {m_estSurPalet = etat;}

    /***************/
    /* Déplacement */
    /***************/

    /* En appelant cette méthode, la balle se déplace automatiquement
     * en fonction de sa direction, qui est mise à jour à chaque collision */
    void deplacer();

    /* Permet d'envoyer la balle lorsqu'elle se situe encore sur le palet,
     * et qu'elle ne s'est donc jamais déplacée */
    void envoyerBalle();

    /* Affichage de la balle : on ne considère ici que l'affichage pur
     * et dur. Cette méthode est appelée par le Diplay() principal */
    void Display();

private:

    GLUquadric *m_sphere;
    float m_rayon;
    float m_couleur[3];
    float m_vitesse;
    float m_direction[2];
    float m_positionCentre[2];
    bool m_estSurPalet; // La balle se trouve-t-elle sur le palet ?
};

#endif // BALLE_H

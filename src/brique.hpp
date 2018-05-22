#ifndef BRIQUE_H
#define BRIQUE_H

#include "bloc.hpp"

class Balle;

/* Cette classe hérite de Bloc et permet de gérer la création,
 * l'affichage et le traitement des collisions avec une balle */

class Brique : public Bloc
{

public:

    /*******************************/
    /* Constructeur et destructeur */
    /*******************************/

    /* Ce constructeur permet de créer une brique très simplement !
     * On n'a en effet besoin que de la position de son coin, et de
     * sa largeur. */
    Brique(float x, float y, float largeur);

    // Destructeur
    virtual ~Brique();

    /**************************************/
    /* Méthodes virtuelles pures héritées */
    /**************************************/

    /* Pour plus de détails, voir les commentaires du header de la classe Bloc */

    virtual void Display();
    virtual bool collision(Balle* &balle);

    /* Les collisions sont détaillées : on s'intéresse au rebond sur les
     * bords, mais aussi à la réaction de la balle en fonction de son angle
     * d'arrivée sur chaque coin. */
    virtual void traiterCollision(Balle* &balle);

private:

    /*************/
    /* Attributs */
    /*************/

    float m_position[2]; // Position du coin supérieur gauche de la brique

};

#endif // BRIQUE_H

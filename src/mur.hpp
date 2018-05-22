#ifndef MUR_H
#define MUR_H

#include "bloc.hpp"

class Balle;

class Mur : public Bloc
{
public:
    /*******************************/
    /* Constructeur et destructeur */
    /*******************************/

    /* Le constructeur prend en paramètres les coordonnées des coins du mur,
     * le type de mur (gauche, haut, droite) ainsi que les coordonnées limites
     * pour la balle (celle qu'elle ne doit pas dépasser). */
    Mur(float p[][2], int type, float coord);

    // Destructeur
    virtual ~Mur();

    /**************************************/
    /* Méthodes virtuelles pures héritées */
    /**************************************/

    /* Pour plus de détails, voir les commentaires du header de la classe Bloc */

    virtual void Display();
    virtual bool collision(Balle* &balle);
    virtual void traiterCollision(Balle* &balle);

private:

    /*************/
    /* Attributs */
    /*************/

    /* Représente le type de mur : 1 pour le mur de gauche, 2 pour
     * le mur de droite, et 3 pour le mur du haut. Cela est utile pour
     * gérer les collisions. */
    int m_type;

    float m_coord; // valeur de x ou y que la balle ne doit pas dépasser
    bool m_visible; //
};

#endif // MUR_H

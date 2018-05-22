#ifndef MUR_H
#define MUR_H

#include "bloc.hpp"

class Balle;

class Mur : public Bloc
{
public:
    /**********************************/
    /****CONSTRUCTEUR et DESTRUCTEUR***/
    /**********************************/
    Mur(float p[][2], int type, float coord);
    // notre constructeur prend en entrées les coordonnées
    //des angles de la brique, si c'est le mur de droite gauche
    //ou en haut (avec l'entier type) et le float coord pour spécifier les limites pour la balle
    virtual ~Mur();
    /**********************************/
    /************METHODES*************/
    /**********************************/
    virtual void Display();// affiche dans OpenGl notre mur

    virtual bool collision(Balle* &balle);//vérifie qu'il n'y ai pas de collision
    //en prenant en entrée les balles pour savoir leur position

    virtual void traiterCollision(Balle* &balle);// modifie la direction de la balle en collision avec le mur
private:

    /**********************************/
    /************VARIABLES*************/
    /**********************************/
    int m_type; // gauche = 1 / droite = 2 / haut = 3
    float m_coord; // valeur de x ou y que la balle ne doit pas dépasser
    bool m_visible;
};

#endif // MUR_H

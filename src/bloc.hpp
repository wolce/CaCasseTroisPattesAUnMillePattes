#ifndef BLOC_HPP
#define BLOC_HPP

class Balle;

/* Classe abstraite permettant d'implémenter le contexte du jeu :
 * palet, murs et briques, de manière plus simple (tous ces objets
 * peuvent subir des collisions et doivent être affichés).
 * Cette classe n'est pas essentielle mais permet d'attribuer une
 * cohérence au code, notamment dans le cadre de futures évolutions */

class Bloc
{

public:

    /*******************************/
    /* Constructeur et destructeur */
    /*******************************/

    // Ne sert qu'à fixer la couleur sur blanc
    Bloc();

    /* Le destructeur n'est pas implémenté mais peut être à
     * considérer dans le cas de futures évolutions */
    virtual ~Bloc();

    /*****************************/
    /* Méthodes virtuelles pures */
    /*****************************/

    /* Permet l'affichage de l'objet héritant. Il ne s'agit ici que des
     * fonctions d'OpenGL permettant l'affichage */
    virtual void Display() = 0;

    /* Méthode qui indique si une balle (passée en paramètre) est actuellement
     * en collision avec l'objet. Un booléen est renvoyé comme réponse */
    virtual bool collision(Balle* &balle) = 0;

    /* S'il y a collision (cf la méthode précédente), il s'agit ici de repérer
     * son type, puis de la traiter ! C'est-à-dire qu'en fonction de l'objet
     * héritant (mur, brique ou palet), on va modifier la trajectoire d'une
     * façon particulière. Cette méthode ne se trouve pas dans la classe Balle,
     * justement car on traite les collisions de manière différente en fonction des
     * objets considérés. */
    virtual void traiterCollision(Balle* &balle) = 0;

protected:

    float m_points[4][2]; // Contient tous les points du bloc, sous la forme x1,y1,x2,y2,x3,y3,x4,y4.
    float m_couleurs[3];
    float m_largeur; // Largeur du bloc, ie son côté le plus grand
    float m_hauteur; // Hauteur du bloc, ie son côté le plus petit

};

#endif // BLOC_HPP

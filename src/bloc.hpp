#ifndef BLOC_HPP
#define BLOC_HPP

class Balle;

// Classe virtuelle permettant d'implémenter le contexte du jeu (palet, murs, sol, briques)
class Bloc
{

public:

    Bloc();
    virtual ~Bloc();

    // Les objets héritant de cette classe doivent s'afficher, et gérer des collisions avec des balles
    virtual void Display() = 0;
    virtual bool collision(Balle* &balle) = 0;
    virtual void traiterCollision(Balle* &balle) = 0;

protected:

    float m_points[4][2]; // Contient tous les points du bloc, sous la forme x1,y1,x2,y2,x3,y3,x4,y4.
    float m_couleurs[3];
    float m_largeur;
    float m_hauteur;

};

#endif // BLOC_HPP

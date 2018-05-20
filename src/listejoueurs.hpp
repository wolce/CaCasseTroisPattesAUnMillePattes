#ifndef LISTEJOUEURS_HPP
#define LISTEJOUEURS_HPP

#include <list>
#include "joueur.hpp"

class ListeJoueurs : public std::list<Joueur>
{

public:

    ListeJoueurs();
    ~ListeJoueurs();
    void setJoueurCourant(std::string nom);
    void setScore(long score);
    void charger();
    void sauver();
    void nouveauJoueur(std::string nom);

private:
    std::string m_cheminFichierJoueurs;
    Joueur *m_joueurCourant;

};

#endif // LISTEJOUEURS_HPP

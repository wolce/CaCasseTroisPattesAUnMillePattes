#ifndef LISTEJOUEURS_HPP
#define LISTEJOUEURS_HPP

#include <list>
#include "joueur.hpp"

class ListeJoueurs : public std::list<Joueur>
{

public:

    ListeJoueurs();
    ~ListeJoueurs();
    void setJoueurCourant() {m_joueurCourant = NULL;}
    void setJoueurCourant(Joueur &j);
    void setScore(long score);
    Joueur *getJoueurCourant() {return m_joueurCourant;}
    void charger(std::ifstream &is);
    void sauver(std::ofstream &os);
    //void nouveauJoueur(std::string nom);

private:
    std::string m_cheminFichierJoueurs;
    Joueur *m_joueurCourant;

};

#endif // LISTEJOUEURS_HPP

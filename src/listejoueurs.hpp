#ifndef LISTEJOUEURS_HPP
#define LISTEJOUEURS_HPP

#include <list>
#include <map>
#include "joueur.hpp"

class ListeJoueurs : public std::list<Joueur>
{

public:

    ListeJoueurs();
    ~ListeJoueurs();
    void setJoueurCourant() {m_joueurCourant = NULL;}
    void setJoueurCourant(Joueur &j);
    void setScore(long score);
    void updateMeilleursScores();
    void getMeilleursScores(std::map<long, std::string> & meilleursScores);
    Joueur *getJoueurCourant() {return m_joueurCourant;}
    void charger(std::ifstream &is);
    void sauver(std::ofstream &os);

private:
    std::map<long, std::string> m_meilleursScores;
    Joueur *m_joueurCourant;

};

#endif // LISTEJOUEURS_HPP

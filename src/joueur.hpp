#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <fstream>

class Joueur
{

public:

    Joueur();
    Joueur(std::string nom);
    void charger(std::ifstream &is);
    void sauver(std::ofstream &os);
    std::string getNom() const {return m_nom;}
    void setScore(long score);

private:

    std::string m_nom;
    long m_meilleursScores[10];
    long m_dernierScore;

};

#endif // JOUEUR_H

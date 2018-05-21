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
    //void setNom(const std::string nom) {m_nom = nom;}
    std::string getNom() const {return m_nom;}
    void setScore(long score);
    long getMeilleursScores(int i) const {return m_meilleursScores[i];}

private:

    std::string m_nom;
    long m_meilleursScores[10];

};

#endif // JOUEUR_H

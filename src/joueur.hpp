#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur
{
public:
    Joueur();

private:
    std::string m_nom;
    long m_meilleursScores[10];

};

#endif // JOUEUR_H

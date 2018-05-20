#include <fstream>
#include "joueur.hpp"

using namespace std;

Joueur::Joueur()
{
    m_nom = "";

    for (int i=0 ; i<10 ; ++i)
        m_meilleursScores[i] = 0;
}

Joueur::Joueur(std::string nom)
{
    m_nom = nom;

    for (int i=0 ; i<10 ; ++i)
        m_meilleursScores[i] = 0;
}

void Joueur::charger(std::ifstream &is)
{
    string ligne;

    getline(is,m_nom,';');

    for (int i=0 ; i<10 ; ++i)
    {
        getline(is,ligne,';');
        m_meilleursScores[i] = stol(ligne);
    }
}

void Joueur::sauver(std::ofstream &os)
{
    os << m_nom << ";";
    for (int i=0 ; i<10 ; ++i)
        os << m_meilleursScores[i] << ";";
    os << endl;
}

void Joueur::setScore(long score)
{
    int indicePlusPetitScore = 0;

    for (int i=1 ; i<10 ; ++i)
    {
        if (m_meilleursScores[indicePlusPetitScore] < m_meilleursScores[i])
            indicePlusPetitScore = i;
    }

    m_meilleursScores[indicePlusPetitScore] = score;
}

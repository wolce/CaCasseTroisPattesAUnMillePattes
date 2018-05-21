#include <fstream>
#include <algorithm>
#include "joueur.hpp"

#include <iostream>

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
    char a;

    getline(is,m_nom,';');

    for (int i=0 ; i<10 ; ++i)
    {
        getline(is,ligne,';');
        m_meilleursScores[i] = stol(ligne);
    }
    is.get(a);
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
    sort(begin(m_meilleursScores), end(m_meilleursScores));

    int i=0;
    while (score > m_meilleursScores[i] && i<10)
    {
        i++;
    }

    if (i>0)
    {
        for (int j=0 ; j<i ;++j)
            m_meilleursScores[j]=m_meilleursScores[j+1];

        m_meilleursScores[i-1] = score;
    }
}

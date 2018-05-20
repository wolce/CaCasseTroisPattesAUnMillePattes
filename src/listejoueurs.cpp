#include <fstream>
#include "listejoueurs.hpp"

using namespace std;

ListeJoueurs::ListeJoueurs()
{
    m_joueurCourant = NULL;
}

ListeJoueurs::~ListeJoueurs()
{
    delete m_joueurCourant;
}

void ListeJoueurs::setJoueurCourant(string nom)
{
    for (iterator it=begin() ; it!=end() ; it++)
    {
        if (it->getNom() == nom)
        {
            m_joueurCourant = &(*it);
            break;
        }
    }
}

void ListeJoueurs::setScore(long score)
{
    if (m_joueurCourant != NULL)
        m_joueurCourant->setScore(score);
}

void ListeJoueurs::charger()
{
    ifstream fichier(m_cheminFichierJoueurs.c_str());
    string ligne;

    while (! fichier.eof())
    {
        Joueur j;
        j.charger(fichier);
        push_back(j);
    }
}

void ListeJoueurs::sauver()
{
    ofstream fichier(m_cheminFichierJoueurs.c_str(), ios::out | ios::app);
    for (iterator it=begin() ; it!=end() ; it++) it->sauver(fichier);
}

void ListeJoueurs::nouveauJoueur(string nom)
{
    push_back(Joueur(nom));

    ofstream fichier(m_cheminFichierJoueurs.c_str(), ios::out | ios::app);

    if (fichier)
    {
        fichier << nom << ';' << endl;
        fichier.close();
    }
}

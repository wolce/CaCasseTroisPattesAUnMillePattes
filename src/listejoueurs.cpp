#include <fstream>
#include "listejoueurs.hpp"

#include <iostream>

using namespace std;

ListeJoueurs::ListeJoueurs()
{
    m_joueurCourant = NULL;
    m_cheminFichierJoueurs = "debug/niveaux.txt";
}

ListeJoueurs::~ListeJoueurs()
{
    delete m_joueurCourant;
}

void ListeJoueurs::setJoueurCourant(Joueur& j)
{
    m_joueurCourant = &j;
}

void ListeJoueurs::setScore(long score)
{
    if (m_joueurCourant != NULL)
        m_joueurCourant->setScore(score);
}

void ListeJoueurs::charger(std::ifstream &is)
{
    string ligne;
    int n;

    clear();

    is >> n;
    is.ignore();

    for (int i=0;i<n;i++)
    {
        Joueur j;
        j.charger(is);
        push_back(j);
    }
}

void ListeJoueurs::sauver(ofstream &os)
{
    os << size() << endl;
    for (iterator it=begin() ; it!=end() ; it++) it->sauver(os);
}

/*
void ListeJoueurs::nouveauJoueur(string nom)
{
    push_back(Joueur(nom));

    ofstream fichier(m_cheminFichierJoueurs.c_str(), ios::out | ios::app);

    if (fichier)
    {
        fichier << nom << ';' << endl;
        fichier.close();
    }
}*/

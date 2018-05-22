#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <fstream>

class Joueur
{

public:

    /*******************************/
    /* Constructeur et destructeur */
    /*******************************/

    /* On peut choisir de créer un joueur avec ou sans nom ! Ici, il n'y
     * a pas besoin de destructeur. */
    Joueur();
    Joueur(std::string nom);

    /***********************/
    /* Gestion des données */
    /***********************/

    /* Le chargement des joueurs et de leurs scores se déroule à l'ouverture du jeu,
     * dans le constructeur de la fenêtre principale. On récupère en paramètre
     * l'emplacement du fichier de sauvegarde, déterminé dans MainWindow. */
    void charger(std::ifstream &is);

    /* Le programme sauvegarde les joueurs quand on quitte le jeu. La méthode prend
     * en paramètre un flux d'écriture déterminé dans MainWindow */
    void sauver(std::ofstream &os);

    /*********************/
    /* Setters & Getters */
    /*********************/

    std::string getNom() const {return m_nom;}

    /* Ici on utilise un algorithme de tri par insertion dans un tableau trié dans
     * l'ordre croissant. Cette méthode est appelée à chaque fois qu'on souhaite
     * enregistrer le score d'un joueur (donc à chaque fois que le joueur perd). */
    void setScore(long score);

    /* Renvoie le i-ème score du tableau des meilleurs scores, qui est classé
     * dans l'ordre croissant. Le meilleur score du joueur est donc le dixième
     * élément. */
    long getMeilleursScores(int i) const {return m_meilleursScores[i];}

private:

    /*************/
    /* Attributs */
    /*************/

    std::string m_nom; // Nom du joueur
    long m_meilleursScores[10]; // Ses dix meilleurs scores

};

#endif // JOUEUR_H

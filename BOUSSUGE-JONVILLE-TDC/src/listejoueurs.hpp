#ifndef LISTEJOUEURS_HPP
#define LISTEJOUEURS_HPP

#include <list>
#include <map>
#include "joueur.hpp"

class ListeJoueurs : public std::list<Joueur>
{

public:

    /*******************************/
    /* Constructeur et destructeur */
    /*******************************/

    ListeJoueurs();
    ~ListeJoueurs();

    /*********************/
    /* Setters & Getters */
    /*********************/

    /* Lorsque l'on sélectionne un joueur sur la fenêtre des joueurs,
     * ces méthodes sont appelées. Si on précise un joueur en paramètre, c'est qu'un
     * joueur a été sélectionné, et si on ne précise rien, c'est qu'on ne définit
     * aucun joueur comme étant le joueur courant. */
    void setJoueurCourant() {m_joueurCourant = NULL;}
    void setJoueurCourant(Joueur &j);

    /* Permet d'attribuer un nouveau score au joueur sélectionné (ie au joueur courant).
     * Le tri des scores de ce joueur est automatique à l'aide de la méthode setScore() de
     * la classe Joueur. */
    void setScore(long score);

    /* Cette méthode prend en paramètre une std::map regroupant des paires P telles que
     * P[i] = (score[i], nomJoueur) pour tous les joueurs. La fonction s'occupe de rentrer
     * dans cet objet tous les scores existant. On utilise une std::map car à l'ajout d'une
     * paire en son sein, la map est automatiquement triée selon une clé (qui est ici le score).
     * L'affichage des scores tous joueurs confondus est donc très simplifié et le tri n'a pas
     * a être implémenté. */
    void getMeilleursScores(std::map<long, std::string> & meilleursScores);

    /* Permet de récupérer le joueur courant. Utile pour récupérer son nom par exemple. */
    Joueur *getJoueurCourant() {return m_joueurCourant;}

    /***********************/
    /* Gestion des données */
    /***********************/

    /* Ces fonctions permettent de sauver ou charger les données des joueurs (ie noms + scores).
     * Elles font appel aux méthodes charger() et sauver() de la classe Joueur. L'enregistrement
     * et la lecture des scores dans le fichier se fait à l'ouverture et à la fermeture du
     * programme. */
    void charger(std::ifstream &is);
    void sauver(std::ofstream &os);

private:

    /*************/
    /* Attributs */
    /*************/

    Joueur *m_joueurCourant; // Le joueur sélectionné, sur lequel enregistrer les scores

};

#endif // LISTEJOUEURS_HPP

#ifndef JOUEURSDIALOG_H
#define JOUEURSDIALOG_H

#include <QDialog>

class ListeJoueurs;

namespace Ui {
class JoueursDialog;
}

class JoueursDialog : public QDialog
{
    Q_OBJECT

public:

    /*******************************/
    /* Constructeur et destructeur */
    /*******************************/

    /* Pour agir sur les joueurs, la fenêtre doit récupérer l'adresse d'une
     * liste de joueurs (ListeJoueurs). Le contructeur crée la fenêtre, remplie
     * le QTableWidget avec le nom des joueurs, et remplie la liste des dix
     * meilleurs scores tous joueurs confondus */
    explicit JoueursDialog(ListeJoueurs* joueurs, QWidget *parent = 0);

    // Destructeur
    ~JoueursDialog();

private slots:

    /****************/
    /* Slots privés */
    /****************/

    /* Permet de mettre à jour l'affichage des meilleurs scores du joueur
     * lorsqu'on le sélectionne dans la liste */
    void selectionChanged();

    /* Gèrent l'ajout et la suppression d'un joueur en intéragissant directement
     * avec la liste des joueurs passée en paramètre */
    void on_boutonSupprimerJoueur_clicked();
    void on_boutonAjouterJoueur_clicked();

    /* Pour enregistrer le score pour un joueur particulier, il faut préalablement le
     * sélectionner, en cliquant sur le bouton "Sélectionner le joueur". Ce slot
     * s'occupe de fixer le joueur sélectionné comme étant le joueur courant, c'est-à-dire
     * celui pour lequel les scores viendront s'ajouter. */
    void on_boutonSelectionnerJoueur_clicked();

private:

    /*************/
    /* Attributs */
    /*************/

    Ui::JoueursDialog *ui; // Fenêtre en elle-même
    ListeJoueurs *m_joueurs; // Liste des joueurs
};

#endif // JOUEURSDIALOG_H

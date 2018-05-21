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
    explicit JoueursDialog(ListeJoueurs* joueurs, QWidget *parent = 0);
    ~JoueursDialog();

private slots:
    void selectionChanged();
    void on_boutonSupprimerJoueur_clicked();
    void on_boutonAjouterJoueur_clicked();
    void on_boutonSelectionnerJoueur_clicked();

private:
    Ui::JoueursDialog *ui;
    ListeJoueurs *m_joueurs;
};

#endif // JOUEURSDIALOG_H

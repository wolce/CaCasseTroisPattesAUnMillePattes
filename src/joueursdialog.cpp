#include <QInputDialog>
#include <QMessageBox>
#include <map>
#include "joueursdialog.hpp"
#include "listejoueurs.hpp"
#include "ui_joueursdialog.h"

#include <iostream>

JoueursDialog::JoueursDialog(ListeJoueurs* joueurs, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoueursDialog)
{
    ui->setupUi(this);

    m_joueurs = joueurs;

    for (ListeJoueurs::iterator it=m_joueurs->begin() ; it!=m_joueurs->end() ; it++)
    {
        ui->m_joueurs->addItem(QString::fromStdString(it->getNom()));
    }
    ui->m_joueurs->setCurrentRow(0);

    if (m_joueurs->getJoueurCourant() != NULL)
    {
        QString nom=QString::fromStdString(m_joueurs->getJoueurCourant()->getNom());
        ui->labelJoueurCourant->setText("Joueur sélectionné : " + nom);
    }

    // On affiche les meilleurs scores
    int i=0;
    std::map<long,std::string> meilleursScores;
    m_joueurs->getMeilleursScores(meilleursScores);
    for (std::map<long,std::string>::const_iterator it=meilleursScores.end() ; it!=meilleursScores.begin() ; it--)
    {
        ui->tableWidgetMeilleursJoueurs->setItem(i, 0, new QTableWidgetItem(QString("%1").arg((it->second).c_str())));
        ui->tableWidgetMeilleursJoueurs->setItem(i, 1, new QTableWidgetItem(QString("%1").arg(it->first)));
        i++;
    }

    // On retire la première ligne qui contient la somme des lignes
    ui->tableWidgetMeilleursJoueurs->removeRow(0);
    ui->tableWidgetMeilleursJoueurs->insertRow(9);

}

JoueursDialog::~JoueursDialog()
{
    delete ui;
}

void JoueursDialog::selectionChanged()
{
    int item=ui->m_joueurs->currentRow();
    ListeJoueurs::iterator it=m_joueurs->begin();

    std::advance(it,item);

    if (item >= 0)
    {
        QString nom=QString::fromStdString("Meilleurs scores de " + it->getNom());
        ui->labelJoueur->setText(nom);

        for (int i=0 ; i<10 ; ++i)
            ui->tableWidgetScoreJoueur->setItem(9-i, 0, new QTableWidgetItem(QString("%1").arg(it->getMeilleursScores(i))));
    }
    else
        ui->labelJoueur->setText("");
}

void JoueursDialog::on_boutonSupprimerJoueur_clicked()
{
    int item=ui->m_joueurs->currentRow();
    delete ui->m_joueurs->takeItem(item);
    ListeJoueurs::iterator it = m_joueurs->begin();
    std::advance(it,item);

    m_joueurs->erase(it);
}

void JoueursDialog::on_boutonAjouterJoueur_clicked()
{
    bool ok = false;
    QString nom = QInputDialog::getText(this, "Nouveau joueur", "Quel est le nom du joueur ?", QLineEdit::Normal, QString(), &ok);

    if (ok && !nom.isEmpty())
    {
        //m_joueurs->nouveauJoueur(nom.toStdString());
        m_joueurs->push_back(Joueur(nom.toStdString()));
        ui->m_joueurs->addItem(nom);
    }

    else if (nom.isEmpty() && ok)
    {
        QMessageBox::critical(this, "Pseudo", "Pas de nom de joueur");
    }
}

void JoueursDialog::on_boutonSelectionnerJoueur_clicked()
{
    int item=ui->m_joueurs->currentRow();
    ListeJoueurs::iterator it = m_joueurs->begin();
    std::advance(it,item);
    m_joueurs->setJoueurCourant(*it);

    QString nom=QString::fromStdString(it->getNom());
    ui->labelJoueurCourant->setText("Joueur sélectionné : " + nom);
}

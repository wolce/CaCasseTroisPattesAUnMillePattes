#include <QMenuBar>
#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(600,850);

    casseBriques = new CasseBriques(this);
    setCentralWidget(casseBriques);

    QMenu* menuJeu = menuBar()->addMenu(tr("&Jeu"));

    QAction* actionNouvellePartie = new QAction(tr("&Nouvelle partie"));
    connect(actionNouvellePartie, SIGNAL(triggered(bool)), this, SLOT(slotNouvellePartie()));
    menuJeu->addAction(actionNouvellePartie);

    QAction* actionQuitter = new QAction(tr("&Quitter"));
    connect(actionQuitter, SIGNAL(triggered(bool)), this, SLOT(slotQuitter()));
    menuJeu->addAction(actionQuitter);
}

void MainWindow::slotNouvellePartie()
{
    delete casseBriques;
    casseBriques = new CasseBriques(this);
    setCentralWidget(casseBriques);
}

void MainWindow::slotQuitter()
{
    close();
}

MainWindow::~MainWindow()
{
    delete casseBriques;
}

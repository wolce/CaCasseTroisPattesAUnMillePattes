#include <QMenuBar>
#include <QtWidgets>
#include <QSizePolicy>
#include "parametresdialog.hpp"
#include "camera.hpp"
#include "cassebriques.hpp"
#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_casseBriques = new CasseBriques(this);
    m_camera = new Camera();

    m_layoutCentral = new QHBoxLayout();
    m_layoutCentral->addWidget(m_casseBriques);
    if (m_camera->getActive() == true)
        m_layoutCentral->addWidget(m_camera);

    m_widgetCentral = new QWidget();

    m_layoutCentral->setSizeConstraint(QLayout::SetFixedSize); // Permet d'éviter l'effet "flash" de la fenêtre qui se met à jour quand on désactive la caméra

    m_widgetCentral->setLayout(m_layoutCentral);
    setCentralWidget(m_widgetCentral);

    QMenu* menuJeu = menuBar()->addMenu(tr("&Jeu"));

    QAction* actionNouvellePartie = new QAction(tr("&Nouvelle partie"));
    connect(actionNouvellePartie, SIGNAL(triggered(bool)), this, SLOT(slotNouvellePartie()));
    menuJeu->addAction(actionNouvellePartie);

    QAction* actionParametres = new QAction(tr("&Paramètres"));
    connect(actionParametres, SIGNAL(triggered(bool)), this, SLOT(slotParametres()));
    menuJeu->addAction(actionParametres);

    QAction* actionQuitter = new QAction(tr("&Quitter"));
    connect(actionQuitter, SIGNAL(triggered(bool)), this, SLOT(slotQuitter()));
    menuJeu->addAction(actionQuitter);
}

void MainWindow::updateWidgetCentral()
{
    QLayoutItem* child = m_layoutCentral->takeAt(1);

    if (child == 00 && m_camera->getActive() == true)
    {
        m_layoutCentral->addWidget(m_camera);
        m_camera->show();
    }
    else if (child->widget() && m_camera->getActive() == false)
    {
        m_layoutCentral->removeWidget(m_camera);
        m_camera->hide();
        m_layoutCentral->activate();
        this->adjustSize();
    }

    delete child;
}

void MainWindow::slotNouvellePartie()
{
    m_casseBriques->nouvellePartie();
}

void MainWindow::slotQuitter()
{
    close();
}

void MainWindow::slotParametres()
{
    ParametresDialog dial(m_casseBriques, m_camera, this);
    dial.exec();
}

MainWindow::~MainWindow()
{
    delete m_casseBriques;
    delete m_camera;
}

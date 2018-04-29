#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include "briques.h"
#include <cmath>
#include <random>
#include <QDebug>

#include "balle.hpp"
#include "mur.hpp"
#include "palet.hpp"
#include "bloc.hpp"

// Declarations des constantes
#define WIN_WIDTH   600
#define WIN_HEIGHT  800
#define MAX_DIMENSION   50.0f

MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Timer de rafraîchissement
    connect(&m_timerFPS,  &QTimer::timeout, [&] {
        updateGL();
    });

    m_timerFPS.setInterval(10);
    m_timerFPS.start();
}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

    // Création des murs
    float pG[4][2] = {{0.0f, 0.0f},
                      {0.0f, 125.0f},
                      {2.0f, 125.0f},
                      {2.0f, 0.0f}};
    float pH[4][2] = {{2.0f, 125.0f},
                      {2.0f, 123.0f},
                      {98.0f, 123.0f},
                      {98.0f, 125.0f}};
    float pD[4][2] = {{98.0f, 0.0f},
                      {98.0f, 125.0f},
                      {100.0f, 125.0f},
                      {100.0f, 0.0f}};

    m_murs.push_back(new Mur(pG, 1, 2.0f));
    m_murs.push_back(new Mur(pD, 2, 98.0f));
    m_murs.push_back(new Mur(pH, 3, 123.0f));


/*
    XDIR=10;
    YDIR=10;
    m_vitesse=0.1;
    */
}

// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition et reinitialisation de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        gluOrtho2D(0.0, 2*MAX_DIMENSION, 0.0, 2*MAX_DIMENSION * height / static_cast<float>(width));

    // Definition et réinitialisation de la matrice de modelisation / visualisation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation du tampon de couleur et du Z-Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 2*MAX_DIMENSION, 0.0, 2*MAX_DIMENSION * WIN_HEIGHT / WIN_WIDTH);

    // Reinitialisation de la matrice courante
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Affichage du palet
    m_palet.Display();

    // Affichage des murs
    for(Mur * mur : m_murs)
    {
        if (mur->collision(&m_balle) == true)
            mur->traiterCollision(&m_balle);
        mur->Display();
    }

    // Affichage de la balle
    m_balle.Display();



// Interactions avec les briques
        // Brique 1

Briques B1(-15,0,true);
float x1=-15;//probleme manipulation valeur des classes
float y1=0;
if ((X>x1 && X<(x1+3) && m_Zbuffer1==true) && (Y>y1-1 && Y<y1 && m_Zbuffer1==true))
{
    m_Zbuffer1=false;
    if (X>x1-0.5 && X<x1-2.5)
         {YDIR=-YDIR;}
    else if (Y>y1-0.9 && Y<y1-0.1)
        {XDIR=-XDIR;}
    else
    {
        XDIR=-XDIR;
        YDIR=-YDIR;
    }
}
else if (m_Zbuffer1==true && (X<x1 || X>(x1-3) || Y<y1-1 || Y>y1))
{
    B1.Display();
}
else if (m_Zbuffer1==false)
{
    B1.~Briques();
}



}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Le palet va a gauche
        case Qt::Key_Left:
        {
            m_palet.decaler(-0.5f, 0.0f);
            break;
        }

        // Le palet va a droite
        case Qt::Key_Right:
        {
            m_palet.decaler(0.5f, 0.0f);
            break;
        }

        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}

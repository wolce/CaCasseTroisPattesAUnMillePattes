#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include "briques.h"
#include "mur.hpp"
#include "balle.hpp"
#include "palet.hpp"
#include <cmath>
#include <random>
#include <QDebug>

#include "balle.hpp"
#include "mur.hpp"
#include "palet.hpp"
#include "bloc.hpp"

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float MAX_DIMENSION     = 50.0f;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    _Forme=GL_TRIANGLES;

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 60.0f;
        updateGL();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();
}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);




    XDIR=1;
    YDIR=1;
    m_vitesse=0.01;
    condition=false;
    masquage=false;
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
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);

    // Definition et réinitialisation de la matrice de modelisation / visualisation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation du tampon de couleur et du Z-Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reinitialisation de la matrice courante
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // on place la camera en 0, -3, 10 et on regarde en 0, 0, 0

    // Affichage du palet
    m_palet.Display();
    m_mur.Display();





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
// Brique 2
Briques B2(-11,0,true);
float x2=-11;
float y2=0;
if ((X>x2 && X<(x2+3) && m_Zbuffer2==true) && (Y>y2-1 && Y<y2 && m_Zbuffer2==true))
{
    m_Zbuffer2=false;
    if (X>x2-0.5 && X<x2-2.5)
         {YDIR=-YDIR;}
    else if (Y>y2-0.9 && Y<y2-0.1)
        {XDIR=-XDIR;}
    else
    {
        XDIR=-XDIR;
        YDIR=-YDIR;
    }
}
else if (m_Zbuffer2==true && (X<x2 || X>(x2-3) || Y<y2-1 || Y>y2))
{
    B2.Display();
}
else if (m_Zbuffer2==false)
{
    B2.~Briques();
}





X+=XDIR*m_vitesse;
Y+=YDIR*m_vitesse;

if (X>8||X<(-15))//droite et gauche mur
{
    m_TimeElapsed=0;
    XDIR*=-1;

}
if (Y>5)// mur du haut
{
    m_TimeElapsed=0;
    YDIR*=-1;

}
else if (Y<-5)//dessous
{
    close();//je détruit la balle car le joueur a perdu
}

else
{
    m_balle.setCentre(X,Y);
    m_balle.Display();
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

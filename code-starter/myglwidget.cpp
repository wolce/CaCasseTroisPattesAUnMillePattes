#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include "briques.h"
#include "wall.h"
#include "ball.h"
#include "galet.h"
#include <cmath>
#include <random>
#include <QDebug>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 20.0f;


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
    r=255;
    v=255;
    b=255;
    XDIR=1;
    YDIR=1;
    m_vitesse=1;
    condition=false;
    masquage=false;
    glClearColor(0.0, 0.0, 0.0, 1.0); // Couleur à utiliser lorsqu’on va nettoyer la fenetre ( = le fond)

}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0,0,width,height);
    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ORTHO_DIM * ASPECT_RATIO, ORTHO_DIM * ASPECT_RATIO, -ORTHO_DIM, ORTHO_DIM, -2.0f * ORTHO_DIM, 2.0f * ORTHO_DIM);

    // Definition de la matrice de modele

}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation du tampon de couleur
    glClear(GL_COLOR_BUFFER_BIT); // Effacer le buffer de couleur

    // Reinitialisation de la matrice courante

    // Reglage de la couleur
 glColor3ub(r, v, b);

// Ligne 1
        // Brique 1
Briques *B1;
B1->Display(-15,0);

        // Brique 2
Briques *B2;
B2->Display(-11,0);

        // Brique 3
Briques *B3;
B3->Display(-7,0);

        // Brique 4
Briques *B4;
B4->Display(-3,0);

        // Brique 5
Briques *B5;
B5->Display(1,0);

        // Brique 6
Briques *B6;
B6->Display(5,0);


// Ligne 2
// Brique 1
Briques *B7;
B7->Display(-15,4);

// Brique 2
Briques *B8;
B8->Display(-11,4);

// Brique 3
Briques *B9;
B9->Display(-7,4);

// Brique 4
Briques *B10;
B10->Display(-3,4);

// Brique 5
Briques *B11;
B11->Display(1,4);

// Brique 6
Briques *B12;
B12->Display(5,4);

// Les murs
wall *Mur;
Mur->Construc();


 // Galet
galet*GOGO;
GOGO->Display(-7,7);

// Boule

ball *balle;

m_vitesse=0.06;

X+=XDIR*m_vitesse;
Y+=YDIR*m_vitesse;

if (X>8||X<(-15))
{
    m_TimeElapsed=0;
    XDIR*=-1;

}
if (Y>5||Y<(-4))
{
    m_TimeElapsed=0;
    YDIR*=-1;

}


else
{
    balle->Display(X,Y);
}


}






// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Changement de couleur du fond
        case Qt::Key_B:
        {
            glClearColor(double(rand()%256)/255.0, double(rand()%256)/255.0, double(rand()%256)/255.0, 1.0);
        break;
        }

        // Changement de couleur de l'objet
        case Qt::Key_C:
        {
        r=rand()%255;
        v=rand()%255;
        b=rand()%255;
        }

        // Affichage/Masquage de l'objet
        case Qt::Key_H:
        {
            masquage=!masquage;
            break;
        }

        // Changement de l'objet a afficher
        case Qt::Key_Space:
        {
            if(_Forme==GL_TRIANGLES) {_Forme=GL_QUADS;}
            else if(_Forme==GL_QUADS){ _Forme=GL_TRIANGLES;}
            break;
        }

        // Sortie de l'application
        case Qt::Key_Escape:
        {
        close();
            break;
        }

        // Cas par defaut
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

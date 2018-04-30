#include "myglwidget.hpp"
#include <QApplication>
#include <QDesktopWidget>
#include <cmath>
#include <random>
#include <QDebug>

#include "balle.hpp"
#include "mur.hpp"
#include "palet.hpp"
#include "bloc.hpp"
#include "brique.hpp"
#include <vector>

// Declarations des constantes
#define WIN_WIDTH   600
#define WIN_HEIGHT  800
#define MAX_DIMENSION   50.0f
float WIDTH = 2*MAX_DIMENSION;
float HEIGHT = 2*MAX_DIMENSION * WIN_HEIGHT / WIN_WIDTH;

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

    m_briquesParLigne = 10;
    m_briquesParColonne = 12;
    m_espaceEntreBriquesLigne = 1.0f;
    m_espaceEntreBriquesColonne = 1.0f;
    m_largeurBrique = (WIDTH-m_espaceEntreBriquesLigne - 4.0f)/m_briquesParLigne - m_espaceEntreBriquesLigne;
    m_collision = false;
}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    // Création du palet
    m_palet = new Palet(WIDTH/2.0f, 2.0f, 20.0f, 2.0f);

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
    float pB[4][2] = {{2.0f, 0.0f},
                      {2.0f, 2.0f},
                      {98.0f, 2.0f},
                      {98.0f, 0.0f}};

    m_murs.push_back(new Mur(pG, 1, 2.0f));
    m_murs.push_back(new Mur(pD, 2, 98.0f));
    m_murs.push_back(new Mur(pH, 3, 123.0f));
    m_murs.push_back(new Mur(pB, 4, 2.0f));

    // Création des balles
    for (int i = 0 ; i < 3 ; ++i)
        m_balles.push_back(new Balle(10.0f*(i+1), 10.0f*(i+1), 1.0f, 1.0f));

    // Création des briques
    for (int i = 0 ; i < m_briquesParLigne ; ++i)
    {
        for (int j = 0 ; j < m_briquesParColonne ; ++j)
        {
            m_briques.push_back(new Brique((i+1)*m_espaceEntreBriquesLigne + 2.0f + i*m_largeurBrique, 123.0f-(j+1)*m_espaceEntreBriquesColonne - j*m_largeurBrique/3.0f, m_largeurBrique));
        }
    }
}

// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition et reinitialisation de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0) {
        HEIGHT = 2*MAX_DIMENSION * height / static_cast<float>(width);
        gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
    }

    // Definition et réinitialisation de la matrice de modelisation / visualisation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation du tampon de couleur
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);

    // Reinitialisation de la matrice courante
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Gestion des collisions pour chaque balle
    for(Balle * balle : m_balles)
    {
        // Collision avec le palet ?
        if (m_palet->collision(balle) == true)
            m_palet->traiterCollision(balle);

        // Collision avec un des murs ?
        for(Mur * mur : m_murs)
        {
            if (mur->collision(balle) == true)
                mur->traiterCollision(balle);
        }

        // Collision avec une des briques ?
        for(std::vector<Brique *>::iterator it=m_briques.begin() ; it!=m_briques.end() ; )
        {
            if ((*it)->collision(balle) == true)
            {
                if (m_collision == false) // Pour éviter qu'il y ait un double inversement de direction de la balle
                {
                    (*it)->traiterCollision(balle);
                    m_collision = true;
                }
                it = m_briques.erase(it); // Si on supprime la brique on redéfinit l'itérateur à la position courante
            }
            else
                ++it; // Si la brique n'est pas supprimée on incrémente l'itérateur
        }
        m_collision = false;
    }

    // Affichage du palet
    m_palet->Display();

    // Affichage des murs
    for(Mur * mur : m_murs)
        mur->Display();

    // Affichage des briques
    for(Brique * brique : m_briques)
        brique->Display();

    // Affichage des balles
    for(Balle * balle : m_balles)
        balle->Display();
}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Le palet va a gauche
        case Qt::Key_Left:
        {
            m_palet->decaler(-0.5f, 0.0f);
            break;
        }

        // Le palet va a droite
        case Qt::Key_Right:
        {
            m_palet->decaler(0.5f, 0.0f);
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

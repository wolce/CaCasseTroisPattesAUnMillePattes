#include <QApplication>
#include <QDesktopWidget>
#include <QTimer>
#include <QKeyEvent>
#include <fstream>
#include "mur.hpp"
#include "sol.hpp"
#include "palet.hpp"
#include "balle.hpp"
#include "brique.hpp"
#include "cassebriques.hpp"

#include <iostream>

// Declarations des constantes
#define WIN_WIDTH   600
#define WIN_HEIGHT  800
#define MAX_DIMENSION   50.0f
float WIDTH = 2*MAX_DIMENSION;
float HEIGHT = 2*MAX_DIMENSION * WIN_HEIGHT / WIN_WIDTH;

CasseBriques::CasseBriques(QWidget * parent) : QGLWidget(parent)
{
    // Permet à OpenGL de récupérer les évènements clavier quand il est utilisé avec Qt
    this->setFocusPolicy(Qt::StrongFocus);

    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Timer de rafraîchissement de l'affichage
    connect(&m_timerGL,  &QTimer::timeout, [&] {
        updateGL();
    });
    m_timerGL.setInterval(5);
    m_timerGL.start();

    // Timer de rafraîchissement du jeu
    connect(&m_timerGame, &QTimer::timeout, [&] {
        updateGame();
    });
    m_timerGame.setInterval(5);
    m_timerGame.start();

    // Configuration de l'espace
    m_espaceEntreBriquesLigne = 1.0f;
    m_espaceEntreBriquesColonne = 1.0f;
    m_largeurPalet = 20.0f;

    // Configuration du jeu
    m_nombreBallesInitial = 3;
    m_nombreBallesRestantes = m_nombreBallesInitial;
    m_score = 0;
    m_niveau = 1;

    // Initialisation des booléens utiles à la réalisations de certains événements
    m_collision = false;
    m_balleSurPalet = false;
    m_perdu = false;
    m_gagne = false;
}

// Fonction d'initialisation
void CasseBriques::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

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
    m_sol = new Sol(pB, 2.0f);

    // Création du palet
    m_palet = new Palet(WIDTH/2.0f, 2.0f, m_largeurPalet, 2.5f, 2.0f, 98.0f);

    // Création de la balle
    m_balles.push_back(new Balle(m_palet));
    m_balleSurPalet = true;

    // On dessine les briques (chargement du niveau)
    chargerNiveau();
}

// Fonction de redimensionnement
void CasseBriques::resizeGL(int width, int height)
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
void CasseBriques::paintGL()
{
    // Reinitialisation du tampon de couleur
    glClear(GL_COLOR_BUFFER_BIT);

    // Affichage de l'espace de jeu
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);

    // Affichage des éléments du jeu
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

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

    // Affichage du texte
    renderText(10.0f, 33.0f, "Balles : ", QFont("Comic Sans MS", 14));
    renderText(220.0f, 33.0f, "Score : " + QString::number(m_score), QFont("Comic Sans MS", 14));
    renderText(455.0f, 33.0f, "Niveau : " + QString::number(m_niveau), QFont("Comic Sans MS", 14));

    // Affichage des balles restantes
    GLUquadric* tmp=gluNewQuadric();
    for (unsigned int i = 0 ; i < m_nombreBallesRestantes ; ++i)
    {
        glPushMatrix();
        glTranslatef(13.0f+(i+1)*4, 129.0f, 0.0f);
        gluSphere(tmp, 1.0, 16, 16);
        glPopMatrix();
    }
    gluDeleteQuadric(tmp);

    if (m_perdu)
        renderText(247.5f, 500.0f, "PERDU", QFont("Comic Sans MS", 20));
}

// Fonction de gestion d'interactions clavier
void CasseBriques::keyPressEvent(QKeyEvent * event)
{
    if (!m_perdu && !m_gagne)
    {
        switch(event->key())
        {
            // Le palet va à gauche
            case Qt::Key_Left:
            {
                m_palet->decaler(-0.5f, 0.0f);
                for (Balle * balle : m_balles)
                {
                    if (balle->getEstSurPalet() == true)
                        balle->setCentreX(m_palet->getCentreX());
                }
                break;
            }

            // Le palet va à droite
            case Qt::Key_Right:
            {
                m_palet->decaler(0.5f, 0.0f);
                for (Balle * balle : m_balles)
                {
                    if (balle->getEstSurPalet() == true)
                        balle->setCentreX(m_palet->getCentreX());
                }
                break;
            }

            case Qt::Key_Space:
            {
                for (Balle * balle : m_balles)
                {
                    if (balle->getEstSurPalet() == true)
                    {
                        balle->deplacer();
                        balle->setEstSurPalet(false);
                        m_nombreBallesRestantes--;
                    }
                }
                if (m_balleSurPalet == false && m_nombreBallesRestantes > 0)
                {
                    m_balles.push_back(new Balle(m_palet));
                    m_balleSurPalet = true;
                }
                else
                    m_balleSurPalet = false;
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
    else
    {
        event->ignore();
        return;
    }
}

CasseBriques::~CasseBriques()
{
    for (Mur * mur : m_murs)
        delete mur;
    m_murs.clear();

    for (Balle * balle : m_balles)
        delete balle;
    m_balles.clear();

    for (Brique * brique : m_briques)
        delete brique;
    m_briques.clear();

    delete m_sol;
    delete m_palet;
}

void CasseBriques::updateGame()
{
    testJeuEnCours();
    if (!m_gagne && !m_perdu)
    {
        for(Balle * balle : m_balles)
        {
            if (balle->getEstSurPalet() == false)
                balle->deplacer();
        }

        traitementCollisions();
    }
    else
        finDuJeu();
}

void CasseBriques::traitementCollisions()
{
    // Gestion des collisions pour chaque balle
    std::vector<Balle *>::iterator itBalle=m_balles.begin();
    std::vector<Brique *>::iterator itBrique;
    while (itBalle != m_balles.end())
    {
        if (m_sol->collision(*itBalle) == true)
        {
            delete *itBalle;
            itBalle = m_balles.erase(itBalle);
            m_score -= 200;
        }
        else
        {
            // Collision avec le palet ?
            if ((*itBalle)->getEstSurPalet() == false && m_palet->collision(*itBalle) == true)
                m_palet->traiterCollision(*itBalle);

            // Collision avec un des murs ?
            for(Mur * mur : m_murs)
            {
                if (mur->collision(*itBalle) == true)
                    mur->traiterCollision(*itBalle);
            }

            // Collision avec une des briques ?
            itBrique = m_briques.begin();
            while(itBrique != m_briques.end())
            {
                if ((*itBrique)->collision(*itBalle) == true)
                {
                    if (m_collision == false) // Pour éviter qu'il y ait un double inversement de direction de la balle
                    {
                        (*itBrique)->traiterCollision(*itBalle);
                        m_collision = true;
                    }
                    delete *itBrique;
                    itBrique = m_briques.erase(itBrique); // On supprime la brique donc on redéfinit l'itérateur à la position courante
                    m_score += 10;
                }
                else
                    ++itBrique; // Si la brique n'est pas supprimée on incrémente l'itérateur
            }
            m_collision = false;
            itBalle++;
        }
    }
}

void CasseBriques::finDuJeu()
{
    m_timerGL.stop();
    m_timerGame.stop();
    updateGL(); // Permet d'effacer la dernière balle si l'affichage n'a pas été mis à jour (décalage entre les timers)

    if (m_perdu)
    {
        // On rentre les scores
    }

    else if (m_gagne)
    {
        m_niveau++;
        initialiserJeu();
    }
}

void CasseBriques::initialiserJeu()
{
    for (Mur * mur : m_murs)
        delete mur;
    m_murs.clear();

    for (Balle * balle : m_balles)
        delete balle;
    m_balles.clear();

    for (Brique * brique : m_briques)
        delete brique;
    m_briques.clear();

    delete m_sol;
    delete m_palet;

    m_nombreBallesRestantes = m_nombreBallesInitial;

    initializeGL();

    m_gagne = false;
    m_timerGame.start();
    m_timerGL.start();
}

void CasseBriques::testJeuEnCours()
{
    if (m_balles.empty())
    {
        m_perdu = true;
    }
    else if (m_briques.empty())
    {
        m_gagne = true;
    }
}

void CasseBriques::setLargeurPalet(float largeur)
{
    m_largeurPalet = largeur;
    m_palet->setLargeur(m_largeurPalet);
}

void CasseBriques::chargerNiveau()
{
    std::ifstream fichier("niveaux.txt");

    std::string ligne;
    char a;
    int nombreNiveaux = 0;
    int choixNiveau;
    int i = 0;

    if(fichier) // Si l'ouverture du fichier s'est bien déroulée, alors on peut effectuer le traitement suivant
    {
        while (std::getline(fichier, ligne))
        {
            if (ligne == "*")
                nombreNiveaux++;
        }

        fichier.clear();
        fichier.seekg(0, std::ios::beg);

        choixNiveau = rand()%(nombreNiveaux)+1;

        while(i < choixNiveau)
        {
            std::getline(fichier, ligne);
            if (ligne == "*")
                ++i;
        }
        std::cout << nombreNiveaux << std::endl;
        std::cout << choixNiveau << std::endl;

        fichier >> m_briquesParLigne;
        fichier >> m_briquesParColonne;
        fichier.get(a);

        m_largeurBrique = (WIDTH-m_espaceEntreBriquesLigne - 4.0f)/m_briquesParLigne - m_espaceEntreBriquesLigne;

        for (int i = 0 ; i < m_briquesParLigne ; ++i)
        {
            for (int j = 0 ; j < m_briquesParColonne ; ++j)
            {
                fichier.get(a);
                if (a == '1')
                {
                    m_briques.push_back(new Brique((i+1)*m_espaceEntreBriquesLigne + 2.0f + i*m_largeurBrique, 123.0f-(j+1)*m_espaceEntreBriquesColonne - j*m_largeurBrique/3.0f, m_largeurBrique));
                }
            }
            fichier.get(a);
        }
    }
}

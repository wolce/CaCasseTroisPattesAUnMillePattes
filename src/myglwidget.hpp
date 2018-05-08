#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include "balle.hpp"
#include "palet.hpp"
#include "mur.hpp"
#include <vector>
#include "brique.hpp"
#include "sol.hpp"

#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <QtOpenGL>
#include <GL/glu.h>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QTimer>

// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);

    // Destructeur
    ~MyGLWidget();

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);

    void appliquerCollisions();

private:
    QTimer m_timerFPS;
    Palet *m_palet;
    std::vector<Mur *> m_murs;
    std::vector<Balle *> m_balles;
    Sol *m_sol;

    std::vector<Brique *> m_briques;
    int m_briquesParLigne;
    int m_briquesParColonne;
    float m_largeurBrique;
    float m_espaceEntreBriquesLigne;
    float m_espaceEntreBriquesColonne;
    bool m_collision; // Indique s'il y a déjà eu une collision sur une brique dans une exécution paintGL. Permet d'éviter un double inversement de direction de la balle.
};

#endif // MYGLWIDGET_H

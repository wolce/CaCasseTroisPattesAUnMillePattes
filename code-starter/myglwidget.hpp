#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include "balle.hpp"
#include "palet.hpp"
#include "mur.hpp"
#include <vector>
#include <brique.hpp>

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

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);

private:
    QTimer m_timerFPS;
    Balle m_balle;
    Palet m_palet;
    std::vector<Mur *> m_murs;

    std::vector<Brique *> m_briques;
    int m_briquesParLigne;
    int m_briquesParColonne;
    float m_largeurBrique;
    float m_espaceEntreBriquesLigne;
    float m_espaceEntreBriquesColonne;
};

#endif // MYGLWIDGET_H
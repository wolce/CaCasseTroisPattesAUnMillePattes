#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

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
    GLenum _Forme;
    bool primitive;
    bool condition;
    bool masquage;
    int r;
    int v;
    int b;
    int XDIR;//X direction
    int YDIR;//Y direction
    float m_vitesse;
    // Timer d'animation
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;


};

#endif // MYGLWIDGET_H

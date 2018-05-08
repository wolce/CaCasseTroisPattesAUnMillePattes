#ifndef CASSEBRIQUES_H
#define CASSEBRIQUES_H

#include <QGLWidget>
#include <QTimer>

class QKeyEvent;
class Palet;
class Mur;
class Balle;
class Brique;
class Sol;

// Classe dediee a l'affichage d'une scene OpenGL
class CasseBriques : public QGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    CasseBriques(QWidget * parent = nullptr);

    // Destructeur
    ~CasseBriques();

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
    bool m_balleSurPalet;
    std::vector<Brique *> m_briques;
    int m_briquesParLigne;
    int m_briquesParColonne;
    float m_largeurBrique;
    float m_espaceEntreBriquesLigne;
    float m_espaceEntreBriquesColonne;
    bool m_collision; // Indique s'il y a déjà eu une collision sur une brique dans une exécution paintGL. Permet d'éviter un double inversement de direction de la balle.
};

#endif // CASSEBRIQUES_H

#ifndef CASSEBRIQUES_H
#define CASSEBRIQUES_H

#include <QGLWidget>
#include <QTimer>
#include <QFont>

class QKeyEvent;
class Palet;
class Mur;
class Balle;
class Brique;
class Camera;
class ListeJoueurs;

// Classe dediee a l'affichage d'une scene OpenGL
class CasseBriques : public QGLWidget
{
    Q_OBJECT

public:

    /******************************/
    /* Constructeur & Destructeur */
    /******************************/

    CasseBriques(Camera* camera, ListeJoueurs *joueurs, QWidget * parent = nullptr);
    ~CasseBriques();

    /***************/
    /* Etat du jeu */
    /***************/

    // Initialisation du jeu
    void initialiserJeu();

    // Stoppe la partie
    void stopJeu();

    // Recommencer une partie depuis le début
    void nouvellePartie();

    /************************/
    /* Actions sur le palet */
    /************************/

    void setLargeurPalet(float largeur);
    float getLargeurPalet() const {return m_largeurPalet;}
    void deplacerPalet(float x);

protected:

    // Fonction d'initialisation de l'affichage
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonctions de gestion des interactions
    void keyPressEvent(QKeyEvent * event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:

    // Mise à jour des variables du jeu (lié au timer de mise à jour du jeu : m_timerGame)
    void updateGame();

private:

    /************/
    /* Méthodes */
    /************/

    // Charger une configuration de briques à partir d'un fichier
    void chargerNiveau();

    // Traitement des collisions pendant une partie
    void traitementCollisions();

    // Teste si la partie doit continuer ou non
    void testJeuEnCours();

    /*************/
    /* Attributs */
    /*************/

    // Joueurs
    ListeJoueurs* m_joueurs;

    // Caméra
    Camera* m_camera;

    // Timers pour la mise à jour
    QTimer m_timerGL;
    QTimer m_timerGame;

    // Eléments du jeu
    Palet *m_palet;
    std::vector<Mur *> m_murs;
    std::vector<Balle *> m_balles;
    std::vector<Brique *> m_briques;

    // Attributs de configuration d'une partie
    unsigned int m_nombreBallesInitial;
    unsigned int m_nombreBallesRestantes;
    unsigned int m_nombreBallesEnCours;
    double m_score;
    int m_niveau;

    // Attributs de configuration de l'espace de jeu
    int m_briquesParLigne;
    int m_briquesParColonne;
    float m_largeurBrique;
    float m_espaceEntreBriquesLigne;
    float m_espaceEntreBriquesColonne;
    float m_largeurPalet;

    // Attributs pour la condition de certaines réalisations
    bool m_collision; // Indique s'il y a déjà eu une collision sur une brique dans une exécution paintGL. Permet d'éviter un double inversement de direction de la balle.
    bool m_balleSurPalet; // Indique si une des balles présentes en jeu est sur le palet (ie n'a pas encore été lancée)
    bool m_perdu; // Indique si le joueur a perdu
    bool m_gagne; //Indique si le joueur a gagné

};

#endif // CASSEBRIQUES_H

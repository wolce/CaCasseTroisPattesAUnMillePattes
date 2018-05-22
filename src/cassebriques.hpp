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

    /* Le jeu utilise éventuellement une caméra pour diriger le palet, et attribue
     * des scores aux joueurs. Initialisation des variables d'état et des timers
     * pour le module de jeu et pour le module d'affichage. */
    CasseBriques(Camera* camera, ListeJoueurs *joueurs, QWidget * parent = nullptr);

    // Destructeur
    ~CasseBriques();

    /************************/
    /* Actions sur le palet */
    /************************/

    /* Permet de recupérer ou de fixer la largeur de palet. Ce setter/getter est utile
     * pour permettre à l'utilisateur de fixer lui-même la donnée, via le menu. */
    void setLargeurPalet(float largeur);
    float getLargeurPalet() const {return m_largeurPalet;}

    /* Déplacer le palet sur l'axe des abscisse, en le plaçant au point x. Cette méthode
     * prend en compte la présence du éventuelle balle sur le palet, et la déplace en
     * conséquence. */
    void deplacerPalet(float x);

    /*****************/
    /* Module de jeu */
    /*****************/

    /* Initialisation du jeu, c'est-à-dire des variables qui vont influencer
     * l'expérience de jeu (nombre de balles, réinitialisation des éléments du jeu, ...) */
    void initialiserJeu();

    /* Stoppe la partie. Sert à mettre sur pause par exemple, mais est aussi utile
     * lorsqu'il s'agit de relancer une partie (on arrête le jeu avant de relancer le jeu) */
    void stopJeu();

    /* Lance la partie. Sert par exemple à sortir du mode de pause, ou bien pour démarrer
     * la partie après avoir initialisé les différents paramètres du jeu */
    void startJeu();

    /* Recommencer une partie depuis le début (utile lorsque l'on clique sur "Nouvelle partie"
     * dans le menu en particulier */
    void nouvellePartie();

private slots:

    /* Mise à jour des variables du jeu. C'est le coeur du module de jeu : cette méthode est appelée
     * à chaque débordement du compteur m_timerJeu. */
    void updateGame();

    /**********************/
    /* Module d'affichage */
    /**********************/

protected:

    /* Fonction d'initialisation de l'affichage, et donc des variables permettant le bon
     * fonctionnement du module d'affichage. Il s'agit de l'équivalent de "initialiserJeu()"
     * pour le module d'affichage. */
    void initializeGL();

    /* Fonction de redimensionnement, qui n'est pas utilisée ici. Nous avons décidé
     * d'attribuer à la fenêtre de jeu une taille fixe. */
    void resizeGL(int width, int height);

    /* Fonction d'affichage qui appelle les fonctions Display() de tous les élements du jeu,
     * c'est-à-dire les briques, les balles, les murs et le palet. Cette méthode est le coeur
     * du module d'affichage, puisqu'elle est appelée à chaque débordement du compteur m_timerGL */
    void paintGL();

    /****************************/
    /* Gestion des interactions */
    /****************************/

    /* Fonctions de gestion des interactions : elles permettent ainsi à l'utilisateur d'intéragir
     * avec le jeu. Par exemple le déplacement du palet, l'envoi des balles, le mode pause, ... */
    void keyPressEvent(QKeyEvent * event);
    void mouseMoveEvent(QMouseEvent *event);

private:

    /********************/
    /* Méthodes privées */
    /********************/

    /* Permet de charger une configuration de briques à partir d'un fichier. Elle est appelée à
     * chaque changement de niveaux. Le fichier utilisé peut être modifié par l'utilisateur pour
     * créer ses propres niveaux (cf Readme.txt pour plus de détails) */
    void chargerNiveau();

    /* Traitement des collisions pendant une partie, et fait appel à toutes les méthodes de gestion
     * des collisions des autres classes du jeu. */
    void traitementCollisions();

    /* Teste si la partie doit continuer ou non. Utile pour vérifier si le jeu est en pause,
     * et si le joueur a gagné ou perdu. */
    void testJeuEnCours();

    /*************/
    /* Attributs */
    /*************/

    // Liste des joueurs : nécessaire pour rentrer les scores
    ListeJoueurs* m_joueurs;

    // Caméra permettant le déplacement du palet à l'aide des mouvements de la main
    Camera* m_camera;

    // Timers des modules de jeu et d'affichage.
    QTimer m_timerGL;
    QTimer m_timerGame;

    // Eléments du jeu (les murs, le palet et les briques héritent de la classe Bloc)
    Palet *m_palet;
    std::vector<Mur *> m_murs;
    std::vector<Balle *> m_balles; // On peut gérer plusieurs balles en même temps
    std::vector<Brique *> m_briques;

    /* Attributs de configuration d'une partie : ces paramètres sont déterminant
     * pour savoir si un joueur a gagné ou perdu (nombre de balle), et permettent
     * la gestion des scores (qui dépend aussi du nombre de balles en jeu) */
    unsigned int m_nombreBallesInitial;
    unsigned int m_nombreBallesRestantes;
    unsigned int m_nombreBallesEnCours;
    double m_score;
    int m_niveau;

    /* Attributs de configuration de l'espace de jeu : ils sont utilisés par le module
     * de jeu pour configurer une partie à partir du fichier des niveaux (celui permettant
     * de créer ses propres configurations) */
    int m_briquesParLigne;
    int m_briquesParColonne;
    float m_largeurBrique;
    float m_espaceEntreBriquesLigne;
    float m_espaceEntreBriquesColonne;
    float m_largeurPalet; // Est modifié directement p ar l'utilisateur dans le menu

    /* Ces attributs sont utiles en interne pour vérifier la condition de certaines réalisations */
    bool m_collision; // Indique s'il y a déjà eu une collision sur une brique dans une exécution paintGL. Permet d'éviter un double inversement de direction de la balle.
    bool m_balleSurPalet; // Indique si une des balles présentes en jeu est sur le palet (ie n'a pas encore été lancée)
    bool m_perdu; // Indique si le joueur a perdu
    bool m_gagne; //Indique si le joueur a gagné
    bool m_pause; // Le jeu est-il en pause ?

};

#endif // CASSEBRIQUES_H

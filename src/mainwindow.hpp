#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Camera;
class CasseBriques;
class ListeJoueurs;
class QHBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /*******************************/
    /* Constructeur et Destructeur */
    /*******************************/

    /* Construit la fenêtre principale et la configure en insérant le widget
     * OpenGL et le menu. */
    explicit MainWindow(QWidget *parent = nullptr);

    // Destructeur
    ~MainWindow();

    /***************************/
    /* Slots privés et publics */
    /***************************/

public slots:

    /* Est appelé par la fenêtre des Paramètres lorsque l'on coche "Activer la caméra".
     * Cette méthode permet d'agrandir la fenêtre principale pour laisser apparaître la
     * webcam juste à droite du widget OpenGL. Elle permet aussi de diminuer la fenêtre à
     * nouveau lorsque l'on désactive l'option Webcam */
    void updateWidgetCentral();

private slots:

    void slotNouvellePartie(); // Commencer une nouvelle partie quand nous appuyons sur l'option dans le menu
    void slotQuitter(); // Quitter la partie quand nous appuyons sur l'option dans le menu
    void slotParametres(); // Afficher la fenetre Paramètres en appuyant dans le menu
    void slotJoueurs(); // Renvoie au menu des joueurs

private:

    /*************/
    /* Attributs */
    /*************/

    /* Les trois attributs suivants constituent le jeu en lui-même : des joueurs,
     * un casse-briques, et un contrôle (la caméra). */
    CasseBriques* m_casseBriques;
    Camera* m_camera;
    ListeJoueurs* m_joueurs;

    /* Ces deux attributs permettent de gérer l'organisation de l'espace central
     * de la fenêtre principale, qui peut contenir éventuellement l'aperçu de la
     * webcam en plus du casse-briques. */
    QHBoxLayout* m_layoutCentral;
    QWidget* m_widgetCentral;
};

#endif // MAINWINDOW_H

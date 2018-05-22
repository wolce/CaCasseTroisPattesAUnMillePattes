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
    /**********************************/
    /***CONSTRUCTEUR ET DESTRUCTEUR****/
    /**********************************/
    explicit MainWindow(QWidget *parent = nullptr); //construit notre fenetre principale enn rentrant chaque partie dedans
    ~MainWindow();//destructeur

signals:

public slots:
    void updateWidgetCentral();// slot pour mettre a jour notre widget

private slots:
    void slotNouvellePartie();// slot pour commencer une nouvelle partie quand nous appuyons sur l'option dans le menu
    void slotQuitter();// slot pour quitter la partie quand nous appuyons sur l'option dans le menu
    void slotParametres();// slot pour afficher la fenetre parametre en appuyant dans le menu
    void slotJoueurs();// slot qui renvoi au menu des joueurs

private:
    /**********************************/
    /************VARIABLES*************/
    /**********************************/
    CasseBriques* m_casseBriques;
    Camera* m_camera;
    ListeJoueurs* m_joueurs;
    QHBoxLayout* m_layoutCentral;
    QWidget* m_widgetCentral;
};

#endif // MAINWINDOW_H

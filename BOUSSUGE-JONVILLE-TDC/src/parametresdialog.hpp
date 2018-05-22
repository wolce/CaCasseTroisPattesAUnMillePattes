#ifndef PARAMETRESDIALOG_H
#define PARAMETRESDIALOG_H

#include <QDialog>

class CasseBriques;
class Camera;

namespace Ui {
class ParametresDialog;
}

class ParametresDialog : public QDialog
{
    Q_OBJECT

public:

    /*******************************/
    /* Constructeur et destructeur */
    /*******************************/

    /* La fenêtre des paramètres doit récupérer des instances de Camera et CasseBriques
     * pour modifier des paramètres étant rattachés à ces classes. */
    explicit ParametresDialog(CasseBriques* casseBriques, Camera* camera, QWidget *parent = 0);

    // Destructeur
    ~ParametresDialog();

    /****************/
    /* Slots privés */
    /****************/

private slots:

    void slotLargeurPalet(); // Slot pour modifier la valeur de la largeur du palet
    void slotActiverCamera(); // Activer ou non la caméra

    /***********/
    /* Signaux */
    /***********/

signals:

    /* Ce signal est appelé lorsque l'on coche ou décoche "Activer la caméra".
     * Celui-ci indique qu'il faut modifier la fenêtre principale pour inclure
     * l'aperçu de la webcam, ou bien le supprimer. */
    void updateWidgetCentral();

private:

    /*************/
    /* Attributs */
    /*************/

    Ui::ParametresDialog *ui; // Interface graphique
    CasseBriques* m_casseBriques; // Utilisé pour modifier la longueur du palet
    Camera* m_camera; // Utiliser ou non la caméra
};

#endif // PARAMETRESDIALOG_H

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
     //Constructeur de notre boite de dialogue paramêtres. ces paramêtres sont l'inclusion de la caméra et la gtaille du palet
    explicit ParametresDialog(CasseBriques* casseBriques, Camera* camera, QWidget *parent = 0);
    ~ParametresDialog();//destructeur de la classe

private:
    Ui::ParametresDialog *ui;//interface graphique parametre
    CasseBriques* m_casseBriques;// utiliser pour modifier la longueur du palet
    Camera* m_camera;//Utiliser ou non la caméra

private slots:
    void slotLargeurPalet();//slot pour modifier la valeur de la largeur du palet
    void slotActiverCamera();//activer ou non la caméra

signals:
    void updateWidgetCentral();//fonction pour rafraichir notre widget
};

#endif // PARAMETRESDIALOG_H

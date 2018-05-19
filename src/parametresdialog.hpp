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
    explicit ParametresDialog(CasseBriques* casseBriques, Camera* camera, QWidget *parent = 0);
    ~ParametresDialog();

private:
    Ui::ParametresDialog *ui;
    CasseBriques* m_casseBriques;
    Camera* m_camera;

private slots:
    void slotLargeurPalet();
    void slotActiverCamera();

signals:
    void updateWidgetCentral();
};

#endif // PARAMETRESDIALOG_H

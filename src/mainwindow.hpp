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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

public slots:
    void updateWidgetCentral();

private slots:
    void slotNouvellePartie();
    void slotQuitter();
    void slotParametres();
    void slotJoueurs();

private:
    CasseBriques* m_casseBriques;
    Camera* m_camera;
    ListeJoueurs* m_joueurs;
    QHBoxLayout* m_layoutCentral;
    QWidget* m_widgetCentral;
};

#endif // MAINWINDOW_H

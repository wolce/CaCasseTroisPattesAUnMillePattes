#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cassebriques.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

public slots:
    void slotNouvellePartie();
    void slotQuitter();

private:
    CasseBriques* casseBriques;
};

#endif // MAINWINDOW_H

#ifndef PARAMETRESDIALOG_H
#define PARAMETRESDIALOG_H

#include <QDialog>

class CasseBriques;

namespace Ui {
class ParametresDialog;
}

class ParametresDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParametresDialog( CasseBriques* casseBriques, QWidget *parent = 0);
    ~ParametresDialog();

private:
    Ui::ParametresDialog *ui;
    CasseBriques* m_casseBriques;

public slots:
    void slotLargeurPalet();
};

#endif // PARAMETRESDIALOG_H

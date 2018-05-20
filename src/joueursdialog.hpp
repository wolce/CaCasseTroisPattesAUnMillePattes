#ifndef JOUEURSDIALOG_H
#define JOUEURSDIALOG_H

#include <QDialog>

namespace Ui {
class JoueursDialog;
}

class JoueursDialog : public QDialog
{
    Q_OBJECT

public:
    explicit JoueursDialog(QWidget *parent = 0);
    ~JoueursDialog();

private:
    Ui::JoueursDialog *ui;
};

#endif // JOUEURSDIALOG_H

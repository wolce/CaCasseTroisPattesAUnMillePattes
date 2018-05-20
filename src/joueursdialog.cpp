#include "joueursdialog.h"
#include "ui_joueursdialog.h"

JoueursDialog::JoueursDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoueursDialog)
{
    ui->setupUi(this);
}

JoueursDialog::~JoueursDialog()
{
    delete ui;
}

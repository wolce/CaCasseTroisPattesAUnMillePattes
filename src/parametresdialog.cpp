#include "cassebriques.hpp"
#include "parametresdialog.hpp"
#include "ui_parametresdialog.h"

ParametresDialog::ParametresDialog(CasseBriques *casseBriques, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParametresDialog)
{
    ui->setupUi(this);
    m_casseBriques = casseBriques;
    ui->spinBox->setValue(m_casseBriques->getLargeurPalet());

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(slotLargeurPalet()));
}

ParametresDialog::~ParametresDialog()
{
    delete ui;
}

void ParametresDialog::slotLargeurPalet()
{
    m_casseBriques->setLargeurPalet(ui->spinBox->value());
}

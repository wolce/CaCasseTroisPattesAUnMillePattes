#include "cassebriques.hpp"
#include "camera.hpp"
#include "parametresdialog.hpp"
#include "ui_parametresdialog.h"

ParametresDialog::ParametresDialog(CasseBriques* casseBriques, Camera* camera, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParametresDialog)
{
    ui->setupUi(this);
    m_casseBriques = casseBriques;
    m_camera = camera;

    ui->spinBox->setValue(m_casseBriques->getLargeurPalet());
    ui->checkBox->setChecked(m_camera->getActive());

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(slotLargeurPalet()));
    connect(ui->checkBox, SIGNAL(clicked(bool)), this, SLOT(slotActiverCamera()));

    connect(this, SIGNAL(updateWidgetCentral()), parent, SLOT(updateWidgetCentral()));
}

ParametresDialog::~ParametresDialog()
{
    delete ui;
}

void ParametresDialog::slotLargeurPalet()
{
    m_casseBriques->setLargeurPalet(ui->spinBox->value());
}

void ParametresDialog::slotActiverCamera()
{
    m_camera->setActive(ui->checkBox->checkState());
    emit updateWidgetCentral();
}

/********************************************************************************
** Form generated from reading UI file 'parametresdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETRESDIALOG_H
#define UI_PARAMETRESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ParametresDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QCheckBox *checkBox;
    QPushButton *pushButton;

    void setupUi(QDialog *ParametresDialog)
    {
        if (ParametresDialog->objectName().isEmpty())
            ParametresDialog->setObjectName(QStringLiteral("ParametresDialog"));
        ParametresDialog->resize(176, 110);
        verticalLayout_2 = new QVBoxLayout(ParametresDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ParametresDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(ParametresDialog);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        checkBox = new QCheckBox(ParametresDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        pushButton = new QPushButton(ParametresDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ParametresDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), ParametresDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(ParametresDialog);
    } // setupUi

    void retranslateUi(QDialog *ParametresDialog)
    {
        ParametresDialog->setWindowTitle(QApplication::translate("ParametresDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ParametresDialog", "Largeur du palet :", nullptr));
        checkBox->setText(QApplication::translate("ParametresDialog", "Activation cam\303\251ra", nullptr));
        pushButton->setText(QApplication::translate("ParametresDialog", "Fermer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParametresDialog: public Ui_ParametresDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETRESDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'joueursdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOUEURSDIALOG_H
#define UI_JOUEURSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_JoueursDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTableWidget *tableWidget_3;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_5;

    void setupUi(QDialog *JoueursDialog)
    {
        if (JoueursDialog->objectName().isEmpty())
            JoueursDialog->setObjectName(QStringLiteral("JoueursDialog"));
        JoueursDialog->resize(747, 390);
        verticalLayout_5 = new QVBoxLayout(JoueursDialog);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(JoueursDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        listWidget = new QListWidget(JoueursDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setSortingEnabled(false);

        verticalLayout_2->addWidget(listWidget);

        pushButton_3 = new QPushButton(JoueursDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton = new QPushButton(JoueursDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(JoueursDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(JoueursDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        tableWidget_3 = new QTableWidget(JoueursDialog);
        if (tableWidget_3->columnCount() < 1)
            tableWidget_3->setColumnCount(1);
        if (tableWidget_3->rowCount() < 10)
            tableWidget_3->setRowCount(10);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget_3->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_3->setShowGrid(false);
        tableWidget_3->setCornerButtonEnabled(false);
        tableWidget_3->setRowCount(10);
        tableWidget_3->setColumnCount(1);
        tableWidget_3->horizontalHeader()->setVisible(false);
        tableWidget_3->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_3->horizontalHeader()->setHighlightSections(false);
        tableWidget_3->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_3->verticalHeader()->setVisible(true);
        tableWidget_3->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget_3->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_3->verticalHeader()->setHighlightSections(false);
        tableWidget_3->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_3->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget_3);


        horizontalLayout->addLayout(verticalLayout);

        line = new QFrame(JoueursDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(JoueursDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        tableWidget = new QTableWidget(JoueursDialog);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setShowGrid(false);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->setRowCount(10);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(tableWidget);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_5 = new QPushButton(JoueursDialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_2->addWidget(pushButton_5);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(JoueursDialog);

        QMetaObject::connectSlotsByName(JoueursDialog);
    } // setupUi

    void retranslateUi(QDialog *JoueursDialog)
    {
        JoueursDialog->setWindowTitle(QApplication::translate("JoueursDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("JoueursDialog", "Joueurs", nullptr));
        pushButton_3->setText(QApplication::translate("JoueursDialog", "S\303\251lectionner le joueur", nullptr));
        pushButton->setText(QApplication::translate("JoueursDialog", "Ajouter un joueur", nullptr));
        pushButton_2->setText(QApplication::translate("JoueursDialog", "Supprimer le joueur", nullptr));
        label_3->setText(QApplication::translate("JoueursDialog", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("JoueursDialog", "Meilleurs joueurs", nullptr));
        pushButton_5->setText(QApplication::translate("JoueursDialog", "Fermer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JoueursDialog: public Ui_JoueursDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOUEURSDIALOG_H

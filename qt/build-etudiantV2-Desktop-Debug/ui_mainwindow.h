/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuiter;
    QAction *actionAbout;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEditNom;
    QLineEdit *lineEditPrenom;
    QComboBox *comboBoxOption;
    QPushButton *pushButtonAbandonner;
    QPushButton *pushButtonSupprimer;
    QPushButton *pushButtonModifier;
    QPushButton *pushButtonAjouter;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 1066);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(1500, 1066));
        QIcon icon;
        icon.addFile(QStringLiteral("../../etudiant.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionQuiter = new QAction(MainWindow);
        actionQuiter->setObjectName(QStringLiteral("actionQuiter"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1000, 1000));
        centralWidget->setMaximumSize(QSize(2000, 2000));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 10, 461, 541));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(470, 10, 531, 541));
        lineEditNom = new QLineEdit(groupBox);
        lineEditNom->setObjectName(QStringLiteral("lineEditNom"));
        lineEditNom->setGeometry(QRect(252, 70, 151, 33));
        lineEditPrenom = new QLineEdit(groupBox);
        lineEditPrenom->setObjectName(QStringLiteral("lineEditPrenom"));
        lineEditPrenom->setGeometry(QRect(242, 160, 171, 33));
        comboBoxOption = new QComboBox(groupBox);
        comboBoxOption->setObjectName(QStringLiteral("comboBoxOption"));
        comboBoxOption->setGeometry(QRect(262, 290, 151, 29));
        pushButtonAbandonner = new QPushButton(groupBox);
        pushButtonAbandonner->setObjectName(QStringLiteral("pushButtonAbandonner"));
        pushButtonAbandonner->setGeometry(QRect(400, 390, 95, 31));
        pushButtonSupprimer = new QPushButton(groupBox);
        pushButtonSupprimer->setObjectName(QStringLiteral("pushButtonSupprimer"));
        pushButtonSupprimer->setGeometry(QRect(290, 390, 95, 31));
        pushButtonModifier = new QPushButton(groupBox);
        pushButtonModifier->setObjectName(QStringLiteral("pushButtonModifier"));
        pushButtonModifier->setGeometry(QRect(170, 390, 95, 31));
        pushButtonAjouter = new QPushButton(groupBox);
        pushButtonAjouter->setObjectName(QStringLiteral("pushButtonAjouter"));
        pushButtonAjouter->setGeometry(QRect(50, 390, 95, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 60, 66, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 170, 66, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 290, 51, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 27));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(tableWidget, lineEditNom);
        QWidget::setTabOrder(lineEditNom, lineEditPrenom);
        QWidget::setTabOrder(lineEditPrenom, comboBoxOption);
        QWidget::setTabOrder(comboBoxOption, pushButtonAjouter);
        QWidget::setTabOrder(pushButtonAjouter, pushButtonModifier);
        QWidget::setTabOrder(pushButtonModifier, pushButtonSupprimer);
        QWidget::setTabOrder(pushButtonSupprimer, pushButtonAbandonner);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuiter);
        menu->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des \303\251tudiants", 0));
        actionQuiter->setText(QApplication::translate("MainWindow", "&quitter", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        pushButtonAbandonner->setText(QApplication::translate("MainWindow", "Abandonner", 0));
        pushButtonSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", 0));
        pushButtonModifier->setText(QApplication::translate("MainWindow", "Modifier", 0));
        pushButtonAjouter->setText(QApplication::translate("MainWindow", "Ajouter", 0));
        label->setText(QApplication::translate("MainWindow", "Nom", 0));
        label_2->setText(QApplication::translate("MainWindow", "Pr\303\251nom", 0));
        label_3->setText(QApplication::translate("MainWindow", "Option", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "fichier", 0));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

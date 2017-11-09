/********************************************************************************
** Form generated from reading UI file 'aproposde.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APROPOSDE_H
#define UI_APROPOSDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_aProposDe
{
public:
    QLabel *label_5;
    QPushButton *PushButtonFermer;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *aProposDe)
    {
        if (aProposDe->objectName().isEmpty())
            aProposDe->setObjectName(QStringLiteral("aProposDe"));
        aProposDe->resize(500, 500);
        aProposDe->setMinimumSize(QSize(500, 500));
        aProposDe->setMaximumSize(QSize(500, 500));
        label_5 = new QLabel(aProposDe);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 30, 241, 21));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        PushButtonFermer = new QPushButton(aProposDe);
        PushButtonFermer->setObjectName(QStringLiteral("PushButtonFermer"));
        PushButtonFermer->setGeometry(QRect(350, 300, 85, 31));
        label = new QLabel(aProposDe);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 60, 261, 221));
        label->setWordWrap(true);
        label_2 = new QLabel(aProposDe);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 181, 211));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../etudiant.png")));
        label_2->setScaledContents(true);

        retranslateUi(aProposDe);

        QMetaObject::connectSlotsByName(aProposDe);
    } // setupUi

    void retranslateUi(QDialog *aProposDe)
    {
        aProposDe->setWindowTitle(QApplication::translate("aProposDe", "Dialog", 0));
        label_5->setText(QApplication::translate("aProposDe", "Gestion des \303\251tudiants", 0));
        PushButtonFermer->setText(QApplication::translate("aProposDe", "&Fermer", 0));
        label->setText(QApplication::translate("aProposDe", "Application de gestion des \303\251tudiants,\n"
" inscription dans sectiopn BTS SIO.\n"
" \n"
" Cette application a \303\251t\303\251 d\303\251velopp\303\251 par les \303\251tudiants du SIO de Gap,\n"
" avec Qt Creator 4.4, sous Qr5.9 \n"
" \n"
" \n"
" CopyLeft 2017", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class aProposDe: public Ui_aProposDe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APROPOSDE_H

/********************************************************************************
** Form generated from reading UI file 'gameon.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEON_H
#define UI_GAMEON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gameon
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *Gameon)
    {
        if (Gameon->objectName().isEmpty())
            Gameon->setObjectName(QString::fromUtf8("Gameon"));
        Gameon->resize(800, 600);
        centralwidget = new QWidget(Gameon);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Gameon->setCentralWidget(centralwidget);

        retranslateUi(Gameon);

        QMetaObject::connectSlotsByName(Gameon);
    } // setupUi

    void retranslateUi(QMainWindow *Gameon)
    {
        Gameon->setWindowTitle(QCoreApplication::translate("Gameon", "Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gameon: public Ui_Gameon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEON_H

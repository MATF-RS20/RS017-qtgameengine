/********************************************************************************
** Form generated from reading UI file 'gamestart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESTART_H
#define UI_GAMESTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameStart
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *GameStart)
    {
        if (GameStart->objectName().isEmpty())
            GameStart->setObjectName(QString::fromUtf8("GameStart"));
        GameStart->resize(1600, 100);
        verticalLayout = new QVBoxLayout(GameStart);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(GameStart);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setBaseSize(QSize(1600, 1000));

        verticalLayout->addWidget(graphicsView);


        retranslateUi(GameStart);

        QMetaObject::connectSlotsByName(GameStart);
    } // setupUi

    void retranslateUi(QWidget *GameStart)
    {
        GameStart->setWindowTitle(QApplication::translate("GameStart", "Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameStart: public Ui_GameStart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESTART_H

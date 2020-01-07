/********************************************************************************
** Form generated from reading UI file 'gamestart.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESTART_H
#define UI_GAMESTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameStart
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *GameStart)
    {
        if (GameStart->objectName().isEmpty())
            GameStart->setObjectName(QString::fromUtf8("GameStart"));
        GameStart->resize(1200, 800);
        gridLayout = new QGridLayout(GameStart);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(GameStart);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setBaseSize(QSize(0, 0));
        graphicsView->setLineWidth(0);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(GameStart);

        QMetaObject::connectSlotsByName(GameStart);
    } // setupUi

    void retranslateUi(QWidget *GameStart)
    {
        GameStart->setWindowTitle(QCoreApplication::translate("GameStart", "Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameStart: public Ui_GameStart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESTART_H

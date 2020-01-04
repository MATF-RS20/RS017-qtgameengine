/********************************************************************************
** Form generated from reading UI file 'playerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERDIALOG_H
#define UI_PLAYERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *dpX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *dpY;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *dpWidth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *dpHeight;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pApplyBtn;
    QPushButton *pCancelBtn;

    void setupUi(QDialog *PlayerDialog)
    {
        if (PlayerDialog->objectName().isEmpty())
            PlayerDialog->setObjectName(QString::fromUtf8("PlayerDialog"));
        PlayerDialog->resize(216, 181);
        PlayerDialog->setMinimumSize(QSize(216, 181));
        PlayerDialog->setMaximumSize(QSize(216, 181));
        widget = new QWidget(PlayerDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 202, 161));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(44, 0));

        horizontalLayout->addWidget(label);

        dpX = new QLineEdit(widget);
        dpX->setObjectName(QString::fromUtf8("dpX"));

        horizontalLayout->addWidget(dpX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(44, 0));

        horizontalLayout_2->addWidget(label_2);

        dpY = new QLineEdit(widget);
        dpY->setObjectName(QString::fromUtf8("dpY"));

        horizontalLayout_2->addWidget(dpY);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(44, 0));

        horizontalLayout_3->addWidget(label_3);

        dpWidth = new QLineEdit(widget);
        dpWidth->setObjectName(QString::fromUtf8("dpWidth"));

        horizontalLayout_3->addWidget(dpWidth);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(44, 0));

        horizontalLayout_4->addWidget(label_4);

        dpHeight = new QLineEdit(widget);
        dpHeight->setObjectName(QString::fromUtf8("dpHeight"));

        horizontalLayout_4->addWidget(dpHeight);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pApplyBtn = new QPushButton(widget);
        pApplyBtn->setObjectName(QString::fromUtf8("pApplyBtn"));

        horizontalLayout_5->addWidget(pApplyBtn);

        pCancelBtn = new QPushButton(widget);
        pCancelBtn->setObjectName(QString::fromUtf8("pCancelBtn"));

        horizontalLayout_5->addWidget(pCancelBtn);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(PlayerDialog);

        QMetaObject::connectSlotsByName(PlayerDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayerDialog)
    {
        PlayerDialog->setWindowTitle(QApplication::translate("PlayerDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("PlayerDialog", "X:", nullptr));
        label_2->setText(QApplication::translate("PlayerDialog", "Y:", nullptr));
        label_3->setText(QApplication::translate("PlayerDialog", "Width:", nullptr));
        label_4->setText(QApplication::translate("PlayerDialog", "Height:", nullptr));
        pApplyBtn->setText(QApplication::translate("PlayerDialog", "Apply", nullptr));
        pCancelBtn->setText(QApplication::translate("PlayerDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerDialog: public Ui_PlayerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERDIALOG_H

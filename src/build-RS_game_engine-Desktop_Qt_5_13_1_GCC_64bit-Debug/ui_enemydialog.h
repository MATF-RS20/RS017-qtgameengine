/********************************************************************************
** Form generated from reading UI file 'enemydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENEMYDIALOG_H
#define UI_ENEMYDIALOG_H

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

class Ui_EnemyDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *eX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *eY;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *eWidth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *eHeight;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *eRange;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *epbApply;
    QPushButton *epbCancel;

    void setupUi(QDialog *EnemyDialog)
    {
        if (EnemyDialog->objectName().isEmpty())
            EnemyDialog->setObjectName(QString::fromUtf8("EnemyDialog"));
        EnemyDialog->resize(210, 212);
        EnemyDialog->setMinimumSize(QSize(210, 212));
        EnemyDialog->setMaximumSize(QSize(210, 212));
        widget = new QWidget(EnemyDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 196, 194));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(44, 0));
        label->setMaximumSize(QSize(44, 16777215));

        horizontalLayout->addWidget(label);

        eX = new QLineEdit(widget);
        eX->setObjectName(QString::fromUtf8("eX"));

        horizontalLayout->addWidget(eX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(44, 0));
        label_2->setMaximumSize(QSize(44, 16777215));

        horizontalLayout_2->addWidget(label_2);

        eY = new QLineEdit(widget);
        eY->setObjectName(QString::fromUtf8("eY"));

        horizontalLayout_2->addWidget(eY);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(44, 0));
        label_4->setMaximumSize(QSize(44, 16777215));

        horizontalLayout_3->addWidget(label_4);

        eWidth = new QLineEdit(widget);
        eWidth->setObjectName(QString::fromUtf8("eWidth"));

        horizontalLayout_3->addWidget(eWidth);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(44, 0));
        label_3->setMaximumSize(QSize(44, 16777215));

        horizontalLayout_4->addWidget(label_3);

        eHeight = new QLineEdit(widget);
        eHeight->setObjectName(QString::fromUtf8("eHeight"));

        horizontalLayout_4->addWidget(eHeight);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(44, 0));
        label_5->setMaximumSize(QSize(44, 16777215));

        horizontalLayout_5->addWidget(label_5);

        eRange = new QLineEdit(widget);
        eRange->setObjectName(QString::fromUtf8("eRange"));

        horizontalLayout_5->addWidget(eRange);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        epbApply = new QPushButton(widget);
        epbApply->setObjectName(QString::fromUtf8("epbApply"));

        horizontalLayout_6->addWidget(epbApply);

        epbCancel = new QPushButton(widget);
        epbCancel->setObjectName(QString::fromUtf8("epbCancel"));

        horizontalLayout_6->addWidget(epbCancel);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(EnemyDialog);

        QMetaObject::connectSlotsByName(EnemyDialog);
    } // setupUi

    void retranslateUi(QDialog *EnemyDialog)
    {
        EnemyDialog->setWindowTitle(QCoreApplication::translate("EnemyDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EnemyDialog", "X:", nullptr));
        label_2->setText(QCoreApplication::translate("EnemyDialog", "Y:", nullptr));
        label_4->setText(QCoreApplication::translate("EnemyDialog", "Width:", nullptr));
        label_3->setText(QCoreApplication::translate("EnemyDialog", "Height:", nullptr));
        label_5->setText(QCoreApplication::translate("EnemyDialog", "Range:", nullptr));
        epbApply->setText(QCoreApplication::translate("EnemyDialog", "Apply", nullptr));
        epbCancel->setText(QCoreApplication::translate("EnemyDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnemyDialog: public Ui_EnemyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENEMYDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'positiveobstacledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIVEOBSTACLEDIALOG_H
#define UI_POSITIVEOBSTACLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PositiveObstacleDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *dPOX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *dPOY;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *dPOWidth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *dPOHeight;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *dApplyBtn;
    QPushButton *dCancelBtn;

    void setupUi(QDialog *PositiveObstacleDialog)
    {
        if (PositiveObstacleDialog->objectName().isEmpty())
            PositiveObstacleDialog->setObjectName(QString::fromUtf8("PositiveObstacleDialog"));
        PositiveObstacleDialog->resize(216, 181);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PositiveObstacleDialog->sizePolicy().hasHeightForWidth());
        PositiveObstacleDialog->setSizePolicy(sizePolicy);
        PositiveObstacleDialog->setMinimumSize(QSize(216, 181));
        PositiveObstacleDialog->setMaximumSize(QSize(216, 181));
        verticalLayout_2 = new QVBoxLayout(PositiveObstacleDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(PositiveObstacleDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(44, 0));

        horizontalLayout->addWidget(label_2);

        dPOX = new QLineEdit(PositiveObstacleDialog);
        dPOX->setObjectName(QString::fromUtf8("dPOX"));

        horizontalLayout->addWidget(dPOX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(PositiveObstacleDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(44, 0));

        horizontalLayout_2->addWidget(label_3);

        dPOY = new QLineEdit(PositiveObstacleDialog);
        dPOY->setObjectName(QString::fromUtf8("dPOY"));

        horizontalLayout_2->addWidget(dPOY);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(PositiveObstacleDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(44, 0));

        horizontalLayout_3->addWidget(label_4);

        dPOWidth = new QLineEdit(PositiveObstacleDialog);
        dPOWidth->setObjectName(QString::fromUtf8("dPOWidth"));

        horizontalLayout_3->addWidget(dPOWidth);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(PositiveObstacleDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(44, 0));

        horizontalLayout_4->addWidget(label_5);

        dPOHeight = new QLineEdit(PositiveObstacleDialog);
        dPOHeight->setObjectName(QString::fromUtf8("dPOHeight"));

        horizontalLayout_4->addWidget(dPOHeight);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        dApplyBtn = new QPushButton(PositiveObstacleDialog);
        dApplyBtn->setObjectName(QString::fromUtf8("dApplyBtn"));

        horizontalLayout_5->addWidget(dApplyBtn);

        dCancelBtn = new QPushButton(PositiveObstacleDialog);
        dCancelBtn->setObjectName(QString::fromUtf8("dCancelBtn"));

        horizontalLayout_5->addWidget(dCancelBtn);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PositiveObstacleDialog);

        QMetaObject::connectSlotsByName(PositiveObstacleDialog);
    } // setupUi

    void retranslateUi(QDialog *PositiveObstacleDialog)
    {
        PositiveObstacleDialog->setWindowTitle(QCoreApplication::translate("PositiveObstacleDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("PositiveObstacleDialog", "X:", nullptr));
        label_3->setText(QCoreApplication::translate("PositiveObstacleDialog", "Y:", nullptr));
        label_4->setText(QCoreApplication::translate("PositiveObstacleDialog", "Width", nullptr));
        label_5->setText(QCoreApplication::translate("PositiveObstacleDialog", "Height:", nullptr));
        dApplyBtn->setText(QCoreApplication::translate("PositiveObstacleDialog", "Apply", nullptr));
        dCancelBtn->setText(QCoreApplication::translate("PositiveObstacleDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PositiveObstacleDialog: public Ui_PositiveObstacleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIVEOBSTACLEDIALOG_H

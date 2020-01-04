/********************************************************************************
** Form generated from reading UI file 'componentinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPONENTINFODIALOG_H
#define UI_COMPONENTINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ComponentInfoDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *dX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *dY;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *dWidth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *dHeight;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *dApplyBtn;
    QPushButton *dCancelBtn;

    void setupUi(QDialog *ComponentInfoDialog)
    {
        if (ComponentInfoDialog->objectName().isEmpty())
            ComponentInfoDialog->setObjectName(QString::fromUtf8("ComponentInfoDialog"));
        ComponentInfoDialog->resize(216, 181);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ComponentInfoDialog->sizePolicy().hasHeightForWidth());
        ComponentInfoDialog->setSizePolicy(sizePolicy);
        ComponentInfoDialog->setMaximumSize(QSize(216, 181));
        verticalLayout_3 = new QVBoxLayout(ComponentInfoDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ComponentInfoDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(44, 0));
        label->setMaximumSize(QSize(44, 16777215));

        horizontalLayout->addWidget(label);

        dX = new QLineEdit(ComponentInfoDialog);
        dX->setObjectName(QString::fromUtf8("dX"));
        sizePolicy.setHeightForWidth(dX->sizePolicy().hasHeightForWidth());
        dX->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(dX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ComponentInfoDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(44, 0));
        label_2->setMaximumSize(QSize(44, 16777215));

        horizontalLayout_2->addWidget(label_2);

        dY = new QLineEdit(ComponentInfoDialog);
        dY->setObjectName(QString::fromUtf8("dY"));
        sizePolicy.setHeightForWidth(dY->sizePolicy().hasHeightForWidth());
        dY->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(dY);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(ComponentInfoDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMaximumSize(QSize(16777215, 44));

        horizontalLayout_3->addWidget(label_3);

        dWidth = new QLineEdit(ComponentInfoDialog);
        dWidth->setObjectName(QString::fromUtf8("dWidth"));
        sizePolicy.setHeightForWidth(dWidth->sizePolicy().hasHeightForWidth());
        dWidth->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(dWidth);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(ComponentInfoDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMaximumSize(QSize(16777215, 44));

        horizontalLayout_4->addWidget(label_4);

        dHeight = new QLineEdit(ComponentInfoDialog);
        dHeight->setObjectName(QString::fromUtf8("dHeight"));
        sizePolicy.setHeightForWidth(dHeight->sizePolicy().hasHeightForWidth());
        dHeight->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(dHeight);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        dApplyBtn = new QPushButton(ComponentInfoDialog);
        dApplyBtn->setObjectName(QString::fromUtf8("dApplyBtn"));

        horizontalLayout_5->addWidget(dApplyBtn);

        dCancelBtn = new QPushButton(ComponentInfoDialog);
        dCancelBtn->setObjectName(QString::fromUtf8("dCancelBtn"));

        horizontalLayout_5->addWidget(dCancelBtn);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(ComponentInfoDialog);

        QMetaObject::connectSlotsByName(ComponentInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *ComponentInfoDialog)
    {
        ComponentInfoDialog->setWindowTitle(QApplication::translate("ComponentInfoDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ComponentInfoDialog", "x:", nullptr));
        label_2->setText(QApplication::translate("ComponentInfoDialog", "y:", nullptr));
        label_3->setText(QApplication::translate("ComponentInfoDialog", "width:", nullptr));
        label_4->setText(QApplication::translate("ComponentInfoDialog", "height", nullptr));
        dApplyBtn->setText(QApplication::translate("ComponentInfoDialog", "Apply", nullptr));
        dCancelBtn->setText(QApplication::translate("ComponentInfoDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComponentInfoDialog: public Ui_ComponentInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPONENTINFODIALOG_H

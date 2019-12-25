/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionClear;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QToolBox *tbConfigure;
    QWidget *page;
    QPushButton *pbChooseFromDefault;
    QWidget *page_3;
    QPushButton *pbRectangle;
    QWidget *page_2;
    QPushButton *pbEnemyOne;
    QWidget *page_6;
    QPushButton *pbAddPlayer;
    QGroupBox *groupBox;
    QGraphicsView *gvMainScene;
    QPushButton *startBt;
    QToolBox *tbComponentInfo;
    QWidget *page_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *leRectangleX;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *leRectangleY;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *leRectangleWidth;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *leRectangleHeight;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbRectangleApply;
    QWidget *page_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *leEnemyX;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *leEnemyY;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *leEnemyWidth;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *leEnemyHeight;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QLineEdit *leEnemyRange;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbEnemyApply;
    QWidget *page_7;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_10;
    QLineEdit *lePlayerX;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_11;
    QLineEdit *lePlayerY;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_12;
    QLineEdit *lePlayerWidth;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_13;
    QLineEdit *lePlayerHeight;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pbPlayerApply;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1084, 690);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tbConfigure = new QToolBox(centralwidget);
        tbConfigure->setObjectName(QString::fromUtf8("tbConfigure"));
        tbConfigure->setMaximumSize(QSize(250, 16777215));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 250, 526));
        pbChooseFromDefault = new QPushButton(page);
        pbChooseFromDefault->setObjectName(QString::fromUtf8("pbChooseFromDefault"));
        pbChooseFromDefault->setGeometry(QRect(0, 0, 201, 25));
        tbConfigure->addItem(page, QString::fromUtf8("Background"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 250, 526));
        pbRectangle = new QPushButton(page_3);
        pbRectangle->setObjectName(QString::fromUtf8("pbRectangle"));
        pbRectangle->setGeometry(QRect(0, 10, 89, 25));
        tbConfigure->addItem(page_3, QString::fromUtf8("Add Components"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 250, 526));
        pbEnemyOne = new QPushButton(page_2);
        pbEnemyOne->setObjectName(QString::fromUtf8("pbEnemyOne"));
        pbEnemyOne->setGeometry(QRect(10, 10, 89, 25));
        tbConfigure->addItem(page_2, QString::fromUtf8("Add Enemy"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        page_6->setGeometry(QRect(0, 0, 250, 526));
        pbAddPlayer = new QPushButton(page_6);
        pbAddPlayer->setObjectName(QString::fromUtf8("pbAddPlayer"));
        pbAddPlayer->setGeometry(QRect(10, 10, 89, 25));
        tbConfigure->addItem(page_6, QString::fromUtf8("Player"));

        horizontalLayout->addWidget(tbConfigure);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        gvMainScene = new QGraphicsView(groupBox);
        gvMainScene->setObjectName(QString::fromUtf8("gvMainScene"));
        gvMainScene->setEnabled(true);
        gvMainScene->setGeometry(QRect(0, 19, 554, 600));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gvMainScene->sizePolicy().hasHeightForWidth());
        gvMainScene->setSizePolicy(sizePolicy);
        gvMainScene->setAutoFillBackground(false);
        startBt = new QPushButton(groupBox);
        startBt->setObjectName(QString::fromUtf8("startBt"));
        startBt->setGeometry(QRect(0, 0, 21, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        startBt->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/play-button-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8("icons/play-button-arrow.png"), QSize(), QIcon::Normal, QIcon::On);
        startBt->setIcon(icon);

        horizontalLayout->addWidget(groupBox);

        tbComponentInfo = new QToolBox(centralwidget);
        tbComponentInfo->setObjectName(QString::fromUtf8("tbComponentInfo"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tbComponentInfo->sizePolicy().hasHeightForWidth());
        tbComponentInfo->setSizePolicy(sizePolicy1);
        tbComponentInfo->setMaximumSize(QSize(250, 16777215));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 250, 557));
        layoutWidget = new QWidget(page_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 199, 163));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(45, 0));
        label->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_2->addWidget(label);

        leRectangleX = new QLineEdit(layoutWidget);
        leRectangleX->setObjectName(QString::fromUtf8("leRectangleX"));

        horizontalLayout_2->addWidget(leRectangleX);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(45, 0));
        label_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_3);

        leRectangleY = new QLineEdit(layoutWidget);
        leRectangleY->setObjectName(QString::fromUtf8("leRectangleY"));

        horizontalLayout_3->addWidget(leRectangleY);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(45, 0));
        label_4->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_4->addWidget(label_4);

        leRectangleWidth = new QLineEdit(layoutWidget);
        leRectangleWidth->setObjectName(QString::fromUtf8("leRectangleWidth"));

        horizontalLayout_4->addWidget(leRectangleWidth);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(45, 0));
        label_2->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_5->addWidget(label_2);

        leRectangleHeight = new QLineEdit(layoutWidget);
        leRectangleHeight->setObjectName(QString::fromUtf8("leRectangleHeight"));

        horizontalLayout_5->addWidget(leRectangleHeight);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pbRectangleApply = new QPushButton(layoutWidget);
        pbRectangleApply->setObjectName(QString::fromUtf8("pbRectangleApply"));

        horizontalLayout_6->addWidget(pbRectangleApply);


        verticalLayout_2->addLayout(horizontalLayout_6);

        tbComponentInfo->addItem(page_4, QString::fromUtf8("Obstacles"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 250, 557));
        layoutWidget1 = new QWidget(page_5);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 202, 194));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(44, 0));
        label_5->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_7->addWidget(label_5);

        leEnemyX = new QLineEdit(layoutWidget1);
        leEnemyX->setObjectName(QString::fromUtf8("leEnemyX"));

        horizontalLayout_7->addWidget(leEnemyX);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(44, 0));

        horizontalLayout_8->addWidget(label_6);

        leEnemyY = new QLineEdit(layoutWidget1);
        leEnemyY->setObjectName(QString::fromUtf8("leEnemyY"));

        horizontalLayout_8->addWidget(leEnemyY);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        leEnemyWidth = new QLineEdit(layoutWidget1);
        leEnemyWidth->setObjectName(QString::fromUtf8("leEnemyWidth"));

        horizontalLayout_9->addWidget(leEnemyWidth);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        leEnemyHeight = new QLineEdit(layoutWidget1);
        leEnemyHeight->setObjectName(QString::fromUtf8("leEnemyHeight"));

        horizontalLayout_10->addWidget(leEnemyHeight);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_11->addWidget(label_7);

        leEnemyRange = new QLineEdit(layoutWidget1);
        leEnemyRange->setObjectName(QString::fromUtf8("leEnemyRange"));

        horizontalLayout_11->addWidget(leEnemyRange);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_2 = new QSpacerItem(100, 18, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);

        pbEnemyApply = new QPushButton(layoutWidget1);
        pbEnemyApply->setObjectName(QString::fromUtf8("pbEnemyApply"));

        horizontalLayout_12->addWidget(pbEnemyApply);


        verticalLayout_3->addLayout(horizontalLayout_12);

        tbComponentInfo->addItem(page_5, QString::fromUtf8("Enemy"));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        page_7->setGeometry(QRect(0, 0, 250, 557));
        layoutWidget2 = new QWidget(page_7);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 202, 161));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(44, 0));

        horizontalLayout_13->addWidget(label_10);

        lePlayerX = new QLineEdit(layoutWidget2);
        lePlayerX->setObjectName(QString::fromUtf8("lePlayerX"));

        horizontalLayout_13->addWidget(lePlayerX);


        verticalLayout_4->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(44, 0));

        horizontalLayout_14->addWidget(label_11);

        lePlayerY = new QLineEdit(layoutWidget2);
        lePlayerY->setObjectName(QString::fromUtf8("lePlayerY"));

        horizontalLayout_14->addWidget(lePlayerY);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(44, 0));

        horizontalLayout_15->addWidget(label_12);

        lePlayerWidth = new QLineEdit(layoutWidget2);
        lePlayerWidth->setObjectName(QString::fromUtf8("lePlayerWidth"));

        horizontalLayout_15->addWidget(lePlayerWidth);


        verticalLayout_4->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(44, 0));

        horizontalLayout_16->addWidget(label_13);

        lePlayerHeight = new QLineEdit(layoutWidget2);
        lePlayerHeight->setObjectName(QString::fromUtf8("lePlayerHeight"));

        horizontalLayout_16->addWidget(lePlayerHeight);


        verticalLayout_4->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_3 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_3);

        pbPlayerApply = new QPushButton(layoutWidget2);
        pbPlayerApply->setObjectName(QString::fromUtf8("pbPlayerApply"));

        horizontalLayout_17->addWidget(pbPlayerApply);


        verticalLayout_4->addLayout(horizontalLayout_17);

        tbComponentInfo->addItem(page_7, QString::fromUtf8("Player"));

        horizontalLayout->addWidget(tbComponentInfo);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1084, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionClear);

        retranslateUi(MainWindow);

        tbConfigure->setCurrentIndex(3);
        startBt->setDefault(false);
        tbComponentInfo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pbChooseFromDefault->setText(QCoreApplication::translate("MainWindow", "Choose formDefault", nullptr));
        tbConfigure->setItemText(tbConfigure->indexOf(page), QCoreApplication::translate("MainWindow", "Background", nullptr));
        pbRectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        tbConfigure->setItemText(tbConfigure->indexOf(page_3), QCoreApplication::translate("MainWindow", "Add Components", nullptr));
        pbEnemyOne->setText(QCoreApplication::translate("MainWindow", "Emeny one", nullptr));
        tbConfigure->setItemText(tbConfigure->indexOf(page_2), QCoreApplication::translate("MainWindow", "Add Enemy", nullptr));
        pbAddPlayer->setText(QCoreApplication::translate("MainWindow", "Add Player", nullptr));
        tbConfigure->setItemText(tbConfigure->indexOf(page_6), QCoreApplication::translate("MainWindow", "Player", nullptr));
        startBt->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "width:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "height", nullptr));
        pbRectangleApply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        tbComponentInfo->setItemText(tbComponentInfo->indexOf(page_4), QCoreApplication::translate("MainWindow", "Obstacles", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Width:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Height:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Range:", nullptr));
        pbEnemyApply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        tbComponentInfo->setItemText(tbComponentInfo->indexOf(page_5), QCoreApplication::translate("MainWindow", "Enemy", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Width:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Height:", nullptr));
        pbPlayerApply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        tbComponentInfo->setItemText(tbComponentInfo->indexOf(page_7), QCoreApplication::translate("MainWindow", "Player", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

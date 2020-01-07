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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
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
    QFormLayout *formLayout_5;
    QPushButton *pbChooseFromDefault;
    QWidget *page_3;
    QFormLayout *formLayout_6;
    QPushButton *pbRectangle;
    QWidget *page_2;
    QFormLayout *formLayout_7;
    QPushButton *pbEnemyOne;
    QWidget *page_6;
    QFormLayout *formLayout_8;
    QPushButton *pbAddPlayer;
    QWidget *page_9;
    QPushButton *pbAddPO;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QGraphicsView *gvMainScene;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *startBt;
    QToolBox *tbComponentInfo;
    QWidget *page_4;
    QFormLayout *formLayout_2;
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
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
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
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_17;
    QLineEdit *leSpeedValue;
    QCheckBox *cbCollision;
    QHBoxLayout *horizontalLayout_18;
    QCheckBox *cbGravity;
    QLabel *label_14;
    QLineEdit *leGravityValue;
    QCheckBox *cbMoveUpDown;
    QHBoxLayout *horizontalLayout_19;
    QCheckBox *cbJump;
    QLabel *label_15;
    QLineEdit *leJumpValue;
    QHBoxLayout *horizontalLayout_20;
    QCheckBox *cbSpeedBoost;
    QLabel *label_16;
    QLineEdit *leBoostValue;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pbPlayerApply;
    QWidget *page_8;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_18;
    QLineEdit *lePOX;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_19;
    QLineEdit *lePOY;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_21;
    QLineEdit *lePOWidth;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_20;
    QLineEdit *lePOHeight;
    QHBoxLayout *horizontalLayout_26;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pbPOApply;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
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
        sizePolicy.setHeightForWidth(tbConfigure->sizePolicy().hasHeightForWidth());
        tbConfigure->setSizePolicy(sizePolicy);
        tbConfigure->setMinimumSize(QSize(250, 0));
        tbConfigure->setMaximumSize(QSize(250, 16777215));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 250, 405));
        formLayout_5 = new QFormLayout(page);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        pbChooseFromDefault = new QPushButton(page);
        pbChooseFromDefault->setObjectName(QString::fromUtf8("pbChooseFromDefault"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, pbChooseFromDefault);

        tbConfigure->addItem(page, QString::fromUtf8("Background"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 250, 405));
        formLayout_6 = new QFormLayout(page_3);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        pbRectangle = new QPushButton(page_3);
        pbRectangle->setObjectName(QString::fromUtf8("pbRectangle"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, pbRectangle);

        tbConfigure->addItem(page_3, QString::fromUtf8("Add Components"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 250, 405));
        formLayout_7 = new QFormLayout(page_2);
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        pbEnemyOne = new QPushButton(page_2);
        pbEnemyOne->setObjectName(QString::fromUtf8("pbEnemyOne"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, pbEnemyOne);

        tbConfigure->addItem(page_2, QString::fromUtf8("Add Enemy"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        page_6->setGeometry(QRect(0, 0, 250, 405));
        formLayout_8 = new QFormLayout(page_6);
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        pbAddPlayer = new QPushButton(page_6);
        pbAddPlayer->setObjectName(QString::fromUtf8("pbAddPlayer"));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, pbAddPlayer);

        tbConfigure->addItem(page_6, QString::fromUtf8("Player"));
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        pbAddPO = new QPushButton(page_9);
        pbAddPO->setObjectName(QString::fromUtf8("pbAddPO"));
        pbAddPO->setGeometry(QRect(10, 10, 151, 25));
        tbConfigure->addItem(page_9, QString::fromUtf8("Add Positive Obstacle"));

        horizontalLayout->addWidget(tbConfigure);

        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gvMainScene = new QGraphicsView(gridWidget);
        gvMainScene->setObjectName(QString::fromUtf8("gvMainScene"));
        gvMainScene->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gvMainScene->sizePolicy().hasHeightForWidth());
        gvMainScene->setSizePolicy(sizePolicy1);
        gvMainScene->setAutoFillBackground(false);

        gridLayout->addWidget(gvMainScene, 1, 0, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        startBt = new QPushButton(gridWidget);
        startBt->setObjectName(QString::fromUtf8("startBt"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        startBt->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/play-button-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8("icons/play-button-arrow.png"), QSize(), QIcon::Normal, QIcon::On);
        startBt->setIcon(icon);

        gridLayout->addWidget(startBt, 0, 0, 1, 1);


        horizontalLayout->addWidget(gridWidget);

        tbComponentInfo = new QToolBox(centralwidget);
        tbComponentInfo->setObjectName(QString::fromUtf8("tbComponentInfo"));
        sizePolicy.setHeightForWidth(tbComponentInfo->sizePolicy().hasHeightForWidth());
        tbComponentInfo->setSizePolicy(sizePolicy);
        tbComponentInfo->setMinimumSize(QSize(250, 0));
        tbComponentInfo->setMaximumSize(QSize(250, 16777215));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 250, 436));
        formLayout_2 = new QFormLayout(page_4);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(page_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(45, 0));
        label->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_2->addWidget(label);

        leRectangleX = new QLineEdit(page_4);
        leRectangleX->setObjectName(QString::fromUtf8("leRectangleX"));

        horizontalLayout_2->addWidget(leRectangleX);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(page_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(45, 0));
        label_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_3);

        leRectangleY = new QLineEdit(page_4);
        leRectangleY->setObjectName(QString::fromUtf8("leRectangleY"));

        horizontalLayout_3->addWidget(leRectangleY);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(page_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(45, 0));
        label_4->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_4->addWidget(label_4);

        leRectangleWidth = new QLineEdit(page_4);
        leRectangleWidth->setObjectName(QString::fromUtf8("leRectangleWidth"));

        horizontalLayout_4->addWidget(leRectangleWidth);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(45, 0));
        label_2->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_5->addWidget(label_2);

        leRectangleHeight = new QLineEdit(page_4);
        leRectangleHeight->setObjectName(QString::fromUtf8("leRectangleHeight"));

        horizontalLayout_5->addWidget(leRectangleHeight);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pbRectangleApply = new QPushButton(page_4);
        pbRectangleApply->setObjectName(QString::fromUtf8("pbRectangleApply"));

        horizontalLayout_6->addWidget(pbRectangleApply);


        verticalLayout_2->addLayout(horizontalLayout_6);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, verticalLayout_2);

        tbComponentInfo->addItem(page_4, QString::fromUtf8("Obstacles"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 250, 436));
        widget = new QWidget(page_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 202, 194));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(44, 0));
        label_5->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_7->addWidget(label_5);

        leEnemyX = new QLineEdit(widget);
        leEnemyX->setObjectName(QString::fromUtf8("leEnemyX"));

        horizontalLayout_7->addWidget(leEnemyX);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(44, 0));

        horizontalLayout_8->addWidget(label_6);

        leEnemyY = new QLineEdit(widget);
        leEnemyY->setObjectName(QString::fromUtf8("leEnemyY"));

        horizontalLayout_8->addWidget(leEnemyY);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        leEnemyWidth = new QLineEdit(widget);
        leEnemyWidth->setObjectName(QString::fromUtf8("leEnemyWidth"));

        horizontalLayout_9->addWidget(leEnemyWidth);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        leEnemyHeight = new QLineEdit(widget);
        leEnemyHeight->setObjectName(QString::fromUtf8("leEnemyHeight"));

        horizontalLayout_10->addWidget(leEnemyHeight);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_11->addWidget(label_7);

        leEnemyRange = new QLineEdit(widget);
        leEnemyRange->setObjectName(QString::fromUtf8("leEnemyRange"));

        horizontalLayout_11->addWidget(leEnemyRange);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_2 = new QSpacerItem(97, 15, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);

        pbEnemyApply = new QPushButton(widget);
        pbEnemyApply->setObjectName(QString::fromUtf8("pbEnemyApply"));

        horizontalLayout_12->addWidget(pbEnemyApply);


        verticalLayout_4->addLayout(horizontalLayout_12);

        tbComponentInfo->addItem(page_5, QString::fromUtf8("Enemy"));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        page_7->setGeometry(QRect(0, 0, 250, 436));
        layoutWidget = new QWidget(page_7);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 230, 351));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(44, 0));

        horizontalLayout_13->addWidget(label_10);

        lePlayerX = new QLineEdit(layoutWidget);
        lePlayerX->setObjectName(QString::fromUtf8("lePlayerX"));

        horizontalLayout_13->addWidget(lePlayerX);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(44, 0));

        horizontalLayout_14->addWidget(label_11);

        lePlayerY = new QLineEdit(layoutWidget);
        lePlayerY->setObjectName(QString::fromUtf8("lePlayerY"));

        horizontalLayout_14->addWidget(lePlayerY);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(44, 0));

        horizontalLayout_15->addWidget(label_12);

        lePlayerWidth = new QLineEdit(layoutWidget);
        lePlayerWidth->setObjectName(QString::fromUtf8("lePlayerWidth"));

        horizontalLayout_15->addWidget(lePlayerWidth);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(44, 0));

        horizontalLayout_16->addWidget(label_13);

        lePlayerHeight = new QLineEdit(layoutWidget);
        lePlayerHeight->setObjectName(QString::fromUtf8("lePlayerHeight"));

        horizontalLayout_16->addWidget(lePlayerHeight);


        verticalLayout_3->addLayout(horizontalLayout_16);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(44, 0));

        horizontalLayout_21->addWidget(label_17);

        leSpeedValue = new QLineEdit(layoutWidget);
        leSpeedValue->setObjectName(QString::fromUtf8("leSpeedValue"));

        horizontalLayout_21->addWidget(leSpeedValue);


        verticalLayout_3->addLayout(horizontalLayout_21);

        cbCollision = new QCheckBox(layoutWidget);
        cbCollision->setObjectName(QString::fromUtf8("cbCollision"));
        cbCollision->setChecked(true);

        verticalLayout_3->addWidget(cbCollision);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        cbGravity = new QCheckBox(layoutWidget);
        cbGravity->setObjectName(QString::fromUtf8("cbGravity"));
        cbGravity->setChecked(true);

        horizontalLayout_18->addWidget(cbGravity);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_18->addWidget(label_14);

        leGravityValue = new QLineEdit(layoutWidget);
        leGravityValue->setObjectName(QString::fromUtf8("leGravityValue"));
        leGravityValue->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_18->addWidget(leGravityValue);


        verticalLayout_3->addLayout(horizontalLayout_18);

        cbMoveUpDown = new QCheckBox(layoutWidget);
        cbMoveUpDown->setObjectName(QString::fromUtf8("cbMoveUpDown"));
        cbMoveUpDown->setChecked(true);

        verticalLayout_3->addWidget(cbMoveUpDown);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        cbJump = new QCheckBox(layoutWidget);
        cbJump->setObjectName(QString::fromUtf8("cbJump"));
        cbJump->setChecked(true);

        horizontalLayout_19->addWidget(cbJump);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_19->addWidget(label_15);

        leJumpValue = new QLineEdit(layoutWidget);
        leJumpValue->setObjectName(QString::fromUtf8("leJumpValue"));
        leJumpValue->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_19->addWidget(leJumpValue);


        verticalLayout_3->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        cbSpeedBoost = new QCheckBox(layoutWidget);
        cbSpeedBoost->setObjectName(QString::fromUtf8("cbSpeedBoost"));
        cbSpeedBoost->setChecked(true);

        horizontalLayout_20->addWidget(cbSpeedBoost);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_20->addWidget(label_16);

        leBoostValue = new QLineEdit(layoutWidget);
        leBoostValue->setObjectName(QString::fromUtf8("leBoostValue"));
        leBoostValue->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_20->addWidget(leBoostValue);


        verticalLayout_3->addLayout(horizontalLayout_20);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_3 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_3);

        pbPlayerApply = new QPushButton(layoutWidget);
        pbPlayerApply->setObjectName(QString::fromUtf8("pbPlayerApply"));

        horizontalLayout_17->addWidget(pbPlayerApply);


        verticalLayout_3->addLayout(horizontalLayout_17);

        tbComponentInfo->addItem(page_7, QString::fromUtf8("Player"));
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        widget1 = new QWidget(page_8);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(0, 20, 202, 161));
        verticalLayout_5 = new QVBoxLayout(widget1);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_18 = new QLabel(widget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(44, 0));

        horizontalLayout_22->addWidget(label_18);

        lePOX = new QLineEdit(widget1);
        lePOX->setObjectName(QString::fromUtf8("lePOX"));

        horizontalLayout_22->addWidget(lePOX);


        verticalLayout_5->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_19 = new QLabel(widget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(44, 0));

        horizontalLayout_23->addWidget(label_19);

        lePOY = new QLineEdit(widget1);
        lePOY->setObjectName(QString::fromUtf8("lePOY"));

        horizontalLayout_23->addWidget(lePOY);


        verticalLayout_5->addLayout(horizontalLayout_23);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_21 = new QLabel(widget1);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(44, 0));

        horizontalLayout_25->addWidget(label_21);

        lePOWidth = new QLineEdit(widget1);
        lePOWidth->setObjectName(QString::fromUtf8("lePOWidth"));

        horizontalLayout_25->addWidget(lePOWidth);


        verticalLayout_5->addLayout(horizontalLayout_25);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_20 = new QLabel(widget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(44, 0));

        horizontalLayout_24->addWidget(label_20);

        lePOHeight = new QLineEdit(widget1);
        lePOHeight->setObjectName(QString::fromUtf8("lePOHeight"));

        horizontalLayout_24->addWidget(lePOHeight);


        verticalLayout_5->addLayout(horizontalLayout_24);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_5);

        pbPOApply = new QPushButton(widget1);
        pbPOApply->setObjectName(QString::fromUtf8("pbPOApply"));

        horizontalLayout_26->addWidget(pbPOApply);


        verticalLayout_5->addLayout(horizontalLayout_26);

        tbComponentInfo->addItem(page_8, QString::fromUtf8("Positive Obstacle"));

        horizontalLayout->addWidget(tbComponentInfo);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionClear);

        retranslateUi(MainWindow);

        tbConfigure->setCurrentIndex(4);
        startBt->setDefault(false);
        tbComponentInfo->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pbChooseFromDefault->setText(QCoreApplication::translate("MainWindow", "Choose fromDefault", nullptr));
        tbConfigure->setItemText(tbConfigure->indexOf(page), QCoreApplication::translate("MainWindow", "Background", nullptr));
        pbRectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        tbConfigure->setItemText(tbConfigure->indexOf(page_3), QCoreApplication::translate("MainWindow", "Add Components", nullptr));
        pbEnemyOne->setText(QCoreApplication::translate("MainWindow", "Enemy one", nullptr));
        tbConfigure->setItemText(tbConfigure->indexOf(page_2), QCoreApplication::translate("MainWindow", "Add Enemy", nullptr));
        pbAddPlayer->setText(QCoreApplication::translate("MainWindow", "Add Player", nullptr));
        tbConfigure->setItemText(tbConfigure->indexOf(page_6), QCoreApplication::translate("MainWindow", "Player", nullptr));
        pbAddPO->setText(QCoreApplication::translate("MainWindow", "Add Positive Obstacle", nullptr));
        tbConfigure->setItemText(tbConfigure->indexOf(page_9), QCoreApplication::translate("MainWindow", "Add Positive Obstacle", nullptr));
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
        label_17->setText(QCoreApplication::translate("MainWindow", "Speed:", nullptr));
        cbCollision->setText(QCoreApplication::translate("MainWindow", "collision", nullptr));
        cbGravity->setText(QCoreApplication::translate("MainWindow", "gravity", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "value:", nullptr));
        cbMoveUpDown->setText(QCoreApplication::translate("MainWindow", "movee up/down", nullptr));
        cbJump->setText(QCoreApplication::translate("MainWindow", "jump", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "value:", nullptr));
        cbSpeedBoost->setText(QCoreApplication::translate("MainWindow", "boost", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "value:", nullptr));
        pbPlayerApply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        tbComponentInfo->setItemText(tbComponentInfo->indexOf(page_7), QCoreApplication::translate("MainWindow", "Player", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Width:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Height:", nullptr));
        pbPOApply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        tbComponentInfo->setItemText(tbComponentInfo->indexOf(page_8), QCoreApplication::translate("MainWindow", "Positive Obstacle", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

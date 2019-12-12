#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>
#include <QFileDialog>
#include <QRectF>
#include <QScrollBar>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int width = this->size().width();
    int height = this->size().height();
    ui->gvMainScene->setRenderHint(QPainter::Antialiasing);
    ui->gvMainScene->setFixedSize(width* 0.7, height*0.95);
    ui->gvMainScene->setSceneRect(0,0,4000,height * 0.95);
    ui->gvMainScene->fitInView(0, 0, 4000, height * 0.95 , Qt::KeepAspectRatioByExpanding);
    gameBuilder.reset(new GameBuilder(ui->gvMainScene));
    ui->gvMainScene->setScene(&(*gameBuilder));

    ui->gvMainScene->verticalScrollBar()->setValue(ui->gvMainScene->verticalScrollBar()->maximum());
    ui->gvMainScene->horizontalScrollBar()->setValue(ui->gvMainScene->horizontalScrollBar()->minimum());

    addSignalsAndSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addSignalsAndSlots()
{
    connect(ui->pbRectangle, SIGNAL(clicked()), this, SLOT(addRectangle()));
    connect(ui->pbChooseFromDefault, SIGNAL(clicked()), this, SLOT(loadDefaultBackground()));
}

void MainWindow::loadGame()
{

}

void MainWindow::saveGame()
{

}

void MainWindow::closeApp()
{

}


void MainWindow::addRectangle()
{

    ComponentInfoDialog* dialog = new ComponentInfoDialog(this);
    dialog->exec();

    if(dialog->accepted()){
        qreal x = dialog->x();
        qreal y = dialog->y();
        qreal width = dialog->width();
        qreal height = dialog->height();
        QList<QLineEdit*> rectangleInfo;
        rectangleInfo.append(ui->leRectangleX);
        rectangleInfo.append(ui->leRectangleY);
        rectangleInfo.append(ui->leRectangleWidth);
        rectangleInfo.append(ui->leRectangleHeight);
        gameBuilder->addRectangle(x, y, width, height, ui->tbComponentInfo, rectangleInfo, ui->pbRectangleApply);

    }
    else{
        return;
    }
}

void MainWindow::loadDefaultBackground()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose File"),"../RS_game_engine/backgrounds/", tr("Images (*.png *.jpg)"));
    QPixmap pix(fileName);
    int height = this->size().height();
    pix = pix.scaledToHeight(height, Qt::SmoothTransformation);
    ui->gvMainScene->setBackgroundBrush(pix);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    int width = this->size().width();
    int height = this->size().height();
    ui->gvMainScene->setFixedSize(width* 0.7, height*0.95);
}

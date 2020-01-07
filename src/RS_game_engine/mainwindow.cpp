#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //int width = this->size().width();
    int height = ui->gvMainScene->size().height();
    ui->gvMainScene->setRenderHint(QPainter::Antialiasing);
    ui->gvMainScene->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    ui->gvMainScene->setSceneRect(0,0,4000,height);
    ui->gvMainScene->fitInView(0, 0, 4000, height, Qt::KeepAspectRatioByExpanding);
    gameBuilder =new GameBuilder(ui->gvMainScene);
    ui->gvMainScene->setScene(&(*gameBuilder));
    ui->startBt->setIcon(QIcon("../RS_game_engine/icons/start.png"));
    ui->startBt->setFixedSize(QSize(20,20));
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
    connect(ui->pbAddPO, SIGNAL(clicked()), this, SLOT(addPositiveObstacle()));
    connect(ui->pbChooseFromDefault, SIGNAL(clicked()), this, SLOT(loadDefaultBackground()));
    connect(ui->pbEnemyOne, SIGNAL(clicked()), this, SLOT(addEnemyOne()));
    connect(ui->pbAddPlayer, SIGNAL(clicked()), this, SLOT(addPlayer()));
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


void MainWindow::addPositiveObstacle()
{
    PositiveObstacleDialog* dialog = new PositiveObstacleDialog(this);
    dialog->exec();
    QString lookPath = QFileDialog::getOpenFileName(this, tr("Choose File"),"../RS_game_engine/positiveObstacles/", tr("Images (*.png *.jpg *.jpeg)"));
    if(dialog->accepted()){
        qreal x = dialog->x();
        qreal y = dialog->y();
        qreal width = dialog->width();
        qreal height = dialog->height();
        QList<QLineEdit*> positiveObstacleInfo;
        positiveObstacleInfo.append(ui->lePOX);
        positiveObstacleInfo.append(ui->lePOY);
        positiveObstacleInfo.append(ui->lePOWidth);
        positiveObstacleInfo.append(ui->lePOHeight);
        gameBuilder->addPositiveObstacle(x, y, width, height, ui->tbComponentInfo, positiveObstacleInfo, ui->pbPOApply, lookPath);

    }
    else{
        return;
    }
}

void MainWindow::addRectangle()
{

    ComponentInfoDialog* dialog = new ComponentInfoDialog(this);
    dialog->exec();
    QString lookPath = QFileDialog::getOpenFileName(this, tr("Choose File"),"../RS_game_engine/obstacles/", tr("Images (*.png *.jpg *.jpeg)"));
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
        gameBuilder->addRectangle(x, y, width, height, ui->tbComponentInfo, rectangleInfo, ui->pbRectangleApply, lookPath);

    }
    else{
        return;
    }
}

void MainWindow::addEnemyOne()
{
    EnemyDialog* enemyDialog = new EnemyDialog(this);
    enemyDialog->exec();
    QString lookPath = QFileDialog::getOpenFileName(this, tr("Choose File"),"../RS_game_engine/enemies/", tr("Images (*.png *.jpg *.jpeg)"));
    if(enemyDialog->accepted()){
        qreal x = enemyDialog->x();
        qreal y = enemyDialog->y();
        qreal width = enemyDialog->width();
        qreal height = enemyDialog->height();
        qreal range = enemyDialog->range();
        QList<QLineEdit*> enemyInfo;
        enemyInfo.append(ui->leEnemyX);
        enemyInfo.append(ui->leEnemyY);
        enemyInfo.append(ui->leEnemyWidth);
        enemyInfo.append(ui->leEnemyHeight);
        enemyInfo.append(ui->leEnemyRange);
        gameBuilder->addEnemy(x, y, width, height, range, lookPath,ui->tbComponentInfo, enemyInfo, ui->pbEnemyApply);
    }
    else{
        return;
    }
}


void MainWindow::addPlayer()
{
    PlayerDialog* playerDialog = new PlayerDialog(this);
    playerDialog->exec();
    QString lookPath = QFileDialog::getOpenFileName(this, tr("Choose File"),"../RS_game_engine/players/", tr("Images (*.png *.jpg *.jpeg)"));
    if(playerDialog->accepted()){
        qreal x = playerDialog->x();
        qreal y = playerDialog->y();
        qreal width = playerDialog->width();
        qreal height = playerDialog->height();
        QList<QLineEdit*> playerInfo;
        playerInfo.append(ui->lePlayerX);
        playerInfo.append(ui->lePlayerY);
        playerInfo.append(ui->lePlayerWidth);
        playerInfo.append(ui->lePlayerHeight);
        playerInfo.append(ui->leJumpValue);
        playerInfo.append(ui->leBoostValue);
        playerInfo.append(ui->leSpeedValue);
        playerInfo.append(ui->leGravityValue);
        gameBuilder->addPlayer(x, y, width, height, lookPath,ui->tbComponentInfo, playerInfo, ui->pbPlayerApply);
    }
    else{
        return;
    }
}

static QString fileName;
void MainWindow::loadDefaultBackground()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Choose File"),"../RS_game_engine/backgrounds/", tr("Images (*.png *.jpg)"));
    QPixmap bkgnd;
    bkgnd.load(fileName);
    bkgnd = bkgnd.scaled(ui->gvMainScene->size());
    QPalette palette;
    palette.setBrush(QPalette::Base, bkgnd);
    ui->gvMainScene->setAutoFillBackground(true);
    ui->gvMainScene->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->gvMainScene->setRenderHints( QPainter::HighQualityAntialiasing);
    ui->gvMainScene->setPalette(palette);


}

void MainWindow::resizeEvent(QResizeEvent *event)
{

    QPixmap bkgnd(fileName);
    bkgnd = bkgnd.scaled(ui->gvMainScene->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Base, bkgnd);
    ui->gvMainScene->setPalette(palette);
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_actionSave_triggered()
{
    SceneLoader* s = new SceneLoader();
    s->setBackgroundName(fileName);
    s->sceneSave(&(*gameBuilder));
}

void MainWindow::on_actionLoad_triggered()
{
    QString fileLoad = QFileDialog::getOpenFileName(this, QObject::tr("Choose File"),"../../");
           SceneLoader* s = new SceneLoader();
       gameBuilder->clear();
       QJsonArray list = s->sceneLoad(fileLoad);
       for(auto it : list){
           if(it.toObject()["name"].toString().compare("Background")==0){
               QString path =it.toObject()["path"].toString();
               fileName = path;
               QPixmap bkgnd(path);
               bkgnd = bkgnd.scaled(ui->gvMainScene->size());
               QPalette palette;
               palette.setBrush(QPalette::Base, bkgnd);
               ui->gvMainScene->setPalette(palette);

           }
          if(it.toObject()["name"].toString().compare("Rectangle")==0){
              qreal x = it.toObject()["x"].toDouble();
              qreal y =it.toObject()["y"].toDouble();
              qreal width = it.toObject()["width"].toDouble();
              qreal height = it.toObject()["height"].toDouble();
              //TODO lookPath hardcoded
              QString lookPath = it.toObject()["look"].toString();
              QList<QLineEdit*> rectangleInfo;
              rectangleInfo.append(ui->leRectangleX);
              rectangleInfo.append(ui->leRectangleY);
              rectangleInfo.append(ui->leRectangleWidth);
              rectangleInfo.append(ui->leRectangleHeight);
              gameBuilder->addRectangle(x, y, width, height, ui->tbComponentInfo, rectangleInfo, ui->pbRectangleApply, lookPath);

          }else if(it.toObject()["name"].toString().compare("Enemy")==0){
              qreal x = it.toObject()["x"].toDouble();
              qreal y =it.toObject()["y"].toDouble();
              qreal width = it.toObject()["width"].toDouble();
              qreal height = it.toObject()["height"].toDouble();
              qreal range = it.toObject()["range"].toDouble();
              QString lookPath = it.toObject()["look"].toString();
              QList<QLineEdit*> enemyInfo;
              enemyInfo.append(ui->leEnemyX);
              enemyInfo.append(ui->leEnemyY);
              enemyInfo.append(ui->leEnemyWidth);
              enemyInfo.append(ui->leEnemyHeight);
              enemyInfo.append(ui->leEnemyRange);
              gameBuilder->addEnemy(x, y, width, height, range, lookPath,ui->tbComponentInfo, enemyInfo, ui->pbEnemyApply);

          }

       }
}

void MainWindow::on_actionClear_triggered()
{
    fileName = "";
    QPixmap bkgnd(fileName);
    bkgnd = bkgnd.scaled(ui->gvMainScene->size());
    QPalette palette;
    palette.setBrush(QPalette::Base, bkgnd);
    ui->gvMainScene->setPalette(palette);
    for(auto item: ui->gvMainScene->items()){
        delete item;
    }
    gameBuilder->getGameBuilderTimer()->stop();
}

void MainWindow::on_startBt_clicked()
{
    GameStart* main_game = new GameStart();
    main_game->setGameON(gameBuilder);
    main_game->setScene(ui->gvMainScene);
    main_game->setFName(fileName);
    main_game->start();
    main_game->show();
}

void MainWindow::on_cbCollision_clicked(bool checked)
{
    gameBuilder->setCollisionEnabled(checked);
}

void MainWindow::on_cbGravity_clicked(bool checked)
{
    if(gameBuilder->getPlayer()==nullptr){
        ui->cbGravity->setCheckState(Qt::CheckState::Checked);
        return;
    }
    gameBuilder->setGravityPlayer(checked);
}

void MainWindow::on_cbMoveUpDown_clicked(bool checked)
{
    gameBuilder->setMoveUpDownPlayer(checked);
}

void MainWindow::on_cbJump_clicked(bool checked)
{
    gameBuilder->setJumpEnabled(checked);
}

void MainWindow::on_cbSpeedBoost_clicked(bool checked)
{
    gameBuilder->setBoostEnabled(checked);
}

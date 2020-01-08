#include "gamestart.h"
#include "ui_gamestart.h"

GameStart::GameStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameStart),
    Points(0),
    timer(new QTimer())
{
    ui->setupUi(this);
    Points = 0;
    textPoints= new QGraphicsTextItem(QString::number(getPoints()));
    QFont font;
    font.setPixelSize(30);
    font.setFamily("Calibri");
    font.setBold(false);
    textPoints->setDefaultTextColor(Qt::red);
    textPoints->setFont(font);
    textPoints->setPos(130,20);

}
GameStart::~GameStart()
{
    delete ui;
}

QGraphicsView *GameStart::getScene() const
{
    return scene;
}

void GameStart::setScene(QGraphicsView *value)
{
    scene = value;
}
void GameStart::start(){

        QRectF exactRect(0, 0, this->size().width(), this->size().height());
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setSceneRect(exactRect);
//        ui->graphicsView->setInteractive(false);
        QGraphicsScene* new_scene= new QGraphicsScene(ui->graphicsView);
        for(QGraphicsItem* item:scene->scene()->items())
        {
            qreal oldX;
            qreal oldY;
            QPoint ref(0,this->scene->height() - this->scene->horizontalScrollBar()->size().height());
            QPoint new_ref(0,this->size().height());
            if( item->type() == 1 || item->type()==3){
                MapBuilder* r = qgraphicsitem_cast<MapBuilder*>(item);
                oldX = r->getX();
                oldY = r->getY();
                qreal refX = oldX - ref.rx();
                qreal refY =ref.ry() - oldY;
                qreal newX  = refX+new_ref.rx();
                qreal newY = new_ref.ry() - refY;
                qDebug() << newX << newY;
                r->setX(newX);
                r->setY(newY);
                r->setPos(newX,newY);
                new_scene->addItem(r);
           }else if(item->type() == 2 || item->type() == 4){
                GameComponent* r = qgraphicsitem_cast<GameComponent*>(item);
                oldX = r->getX();
                oldY = r->getY();
                qreal refX = oldX - ref.rx();
                qreal refY =ref.ry() - oldY;
                qreal newX  = refX+new_ref.rx();
                qreal newY = new_ref.ry() - refY;
                r->setX(newX);
                r->setY(newY);
                r->setPos(newX,newY);
                new_scene->addItem(r);
            }
      }
      if(gameON->getPlayer() != nullptr){
        connect(&(*timer), SIGNAL(timeout()),this, SLOT(update()));
      }
      timer->start(15);
      QPixmap bkgnd;
      bkgnd.load(getFName());
      bkgnd = bkgnd.scaled(this->size());
      QPalette palette;
      palette.setBrush(QPalette::Base, bkgnd);
       ui->graphicsView->setScene(&(*new_scene));
       ui->graphicsView->setPalette(palette);

}
void GameStart::closeEvent(QCloseEvent *event)
{
    QPoint new_ref(0,this->scene->height() - this->scene->horizontalScrollBar()->size().height());
        QPoint ref(0,this->size().height());
        for(QGraphicsItem* item:ui->graphicsView->scene()->items())
        {
            qreal oldX;
            qreal oldY;
            if( item->type() == 1 || item->type() ==3){
                MapBuilder* r = qgraphicsitem_cast<MapBuilder*>(item);
                oldX = r->getX();
                oldY = r->getY();
                qreal refX = oldX - ref.rx();
                qreal refY =ref.ry() - oldY;
                qreal newX  = refX+new_ref.rx();
                qreal newY = new_ref.ry() - refY;
                r->setX(newX);
                r->setY(newY);
                r->setPos(newX,newY);
                scene->scene()->addItem(r);
           }else if(item->type() == 2 || item->type() ==4){
                GameComponent* r = qgraphicsitem_cast<GameComponent*>(item);
                oldX = r->getX();
                oldY = r->getY();
                qreal refX = oldX - ref.rx();
                qreal refY =ref.ry() - oldY;
                qreal newX  = refX+new_ref.rx();
                qreal newY = new_ref.ry() - refY;
                r->setX(newX);
                r->setY(newY);
                r->setPos(newX,newY);
                scene->scene()->addItem(r);
            }
        }
        timer->stop();
        event->accept();
}
void GameStart::resizeEvent(QResizeEvent* event){
        QPoint ref(0,800);
        QPoint new_ref(0,event->size().height());
        QRectF exactRect(0, 0, this->size().width(), this->size().height());
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setSceneRect(exactRect);
        QGraphicsScene* new_scene= new QGraphicsScene(ui->graphicsView);
        for(auto item:ui->graphicsView->scene()->items())
        {
            qreal oldX;
            qreal oldY;
            if( item->type() == 1 || item->type()==3){
                MapBuilder* r = qgraphicsitem_cast<MapBuilder*>(item);
                oldX = r->getX();
                oldY = r->getY();
                qreal refX = oldX - ref.rx();
                qreal refY =ref.ry() - oldY;
                qreal newX  = refX+new_ref.rx();
                qreal newY = new_ref.ry() - refY;
                r->setX(newX);
                r->setY(newY);
                r->setPos(newX,newY);
                new_scene->addItem(r);
           }else if(item->type() == 2 || item->type() ==4){
                GameComponent* r = qgraphicsitem_cast<GameComponent*>(item);
                oldX = r->getX();
                oldY = r->getY();
                qreal refX = oldX - ref.rx();
                qreal refY =ref.ry() - oldY;
                qreal newX  = refX+new_ref.rx();
                qreal newY = new_ref.ry() - refY;
                r->setX(newX);
                r->setY(newY);
                r->setPos(newX,newY);
                new_scene->addItem(r);
            }
      }
        QPixmap bkgnd;
        bkgnd.load(getFName());
        bkgnd = bkgnd.scaled(ui->graphicsView->size());
        QPalette palette;
        palette.setBrush(QPalette::Base, bkgnd);
         ui->graphicsView->setScene(&(*new_scene));
         ui->graphicsView->setPalette(palette);

}

QGraphicsTextItem *GameStart::getTextPoints() const
{
    return textPoints;
}

void GameStart::setTextPoints(QGraphicsTextItem *value)
{
    textPoints = value;
}

int GameStart::getPoints() const
{
    return Points;
}

void GameStart::setPoints(int value)
{
    Points = value;
}
QString GameStart::getFName() const
{
    return fName;
}

void GameStart::setFName(const QString &value)
{
    fName = value;
}


void GameStart::update()
{
    QGraphicsTextItem* text = new QGraphicsTextItem("Points:");
    QFont font;
    font.setPixelSize(30);
    font.setFamily("Calibri");
    font.setBold(false);
    text->setDefaultTextColor(Qt::red);
    text->setFont(font);
    text->setPos(20,20);
    this->ui->graphicsView->scene()->addItem(text);
    this->ui->graphicsView->scene()->addItem(textPoints);
    GameBuilder* gameON = this->getGameON();
    Player* player = this->getGameON()->getPlayer();
    QList<Enemy*> lstEnemy = this->getGameON()->getLstEnemy();
    player->collidingItems();
    player->pos();
    QList<QGraphicsItem *> collidingObjects = player->collidingItems();
    if(gameON->getCollisionEnabled()){
        foreach (QGraphicsItem* item, collidingObjects){
            if(item->type() == 3){
                makePoint();
                ui->graphicsView->scene()->removeItem(item);
            }if(item->type() == 2){
                losePoint();
            }
        }
    }
    foreach(Enemy* e, lstEnemy){
        //qDebug() << e->getRange();
        if(e->getRange() > 0)
            e->move();
    }
    //W-0 A-1 S-2 D-3
    qreal speed = 4;
    if(player->movementArray[4])
        speed *= 2;

    if(gameON->playerCanMove(0,-speed) && player->movementArray[0]){
        player->move(0,-speed);
    }

    if(gameON->playerCanMove(-speed,0) && player->movementArray[1]){
        player->move(-speed,0);
    }

    if(gameON->playerCanMove(0,speed) && player->movementArray[2]){
        player->move(0,speed);
    }

    if(gameON->playerCanMove(speed,0) && player->movementArray[3]){
        player->move(speed,0);
    }
    if(player->getY() + player->getHeight() < scene->height() && gameON->playerGravityApply && gameON->playerCanMove(0,4))
        player->gravityApply();

    if(gameON->jumpPlayer && gameON->jumpAmout < 24){

        player->jumpAnimation();
        gameON->jumpAmout += 1;
    }
    else{
        gameON->jumpPlayer = false;
        gameON->jumpAmout = 0;
    }
}
void GameStart::keyReleaseEvent(QKeyEvent *event)
{
    Player* player = this->getGameON()->getPlayer();
    if(event->key() == Qt::Key_D){
        player->movementArray.setBit(3,false);
    }
    if(event->key() == Qt::Key_W){
        player->movementArray.setBit(0,false);
    }
    if(event->key() == Qt::Key_A){
        player->movementArray.setBit(1,false);
    }
    if(event->key() == Qt::Key_S){
        player->movementArray.setBit(2,false);
    }

//    qDebug() << player->movementArray[0] << " " << player->movementArray[1] << " " << player->movementArray[2] << " " << player->movementArray[3];

}

void GameStart::keyPressEvent(QKeyEvent *event)
{

   Player* player = this->getGameON()->getPlayer();

    if(event->key() == Qt::Key_D){
        player->setFocus();
        player->movementArray.setBit(3,true);
        player->setCurrentLook(true);
    }
    if(event->key() == Qt::Key_W){
        player->setFocus();
        player->movementArray.setBit(0,true);
    }
    if(event->key() == Qt::Key_A){
        player->setFocus();
        player->movementArray.setBit(1,true);
        player->setCurrentLook(false);

    }
    if(event->key() == Qt::Key_S){
        player->setFocus();
        player->movementArray.setBit(2,true);
    }

}

GameBuilder *GameStart::getGameON() const
{
    return gameON;
}

void GameStart::setGameON(GameBuilder *value)
{
    gameON = value;
}
void GameStart::makePoint(){
    this->ui->graphicsView->scene()->removeItem(textPoints);
    Points = Points +1;
    textPoints->setPlainText(QString::number(getPoints()));
    ui->graphicsView->scene()->addItem(textPoints);
}
void GameStart::losePoint(){
    this->ui->graphicsView->scene()->removeItem(textPoints);
    Points = Points -1;
    textPoints->setPlainText(QString::number(getPoints()));
    ui->graphicsView->scene()->addItem(textPoints);
}

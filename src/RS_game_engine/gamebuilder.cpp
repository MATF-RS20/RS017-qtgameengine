#include "gamebuilder.h"

GameBuilder::GameBuilder(QGraphicsView* parent)
    :parent(parent)
    ,player(new Player(60,80))
    ,gameBuilderTimer(new QTimer())
{
    addItem(&(*player));

    setFocus();
    connect(&(*gameBuilderTimer), SIGNAL(timeout()), this, SLOT(update()));

    gameBuilderTimer->start(15);
}

GameBuilder::~GameBuilder()
{
}

void GameBuilder::addRectangle(qreal x, qreal y, qreal width, qreal height,
                               QToolBox* componentInfo, QList<QLineEdit*> rectangleInfo, QPushButton* rectangleUpdate)
{
    rectangle = new Rectangle(x, y, width, height, componentInfo, rectangleInfo, rectangleUpdate);
    addItem(rectangle);
    lstRectangle.append(rectangle);
}

void GameBuilder::addEnemy(qreal x, qreal y, qreal width, qreal height, qreal range,
                           QString look,QToolBox* componentInfo,QList<QLineEdit*> enemyInfo, QPushButton* enemyUpdate)
{
    enemy = new Enemy(x, y, width, height, range, look,
                      componentInfo, enemyInfo, enemyUpdate);
    addItem(enemy);
    lstEnemy.append(enemy);
}

void GameBuilder::keyPressEvent(QKeyEvent *event)
{

    foreach(QGraphicsItem* item, items()){
        if(item->hasFocus() && event->key() == Qt::Key_Delete){
            lstRectangle.removeOne(dynamic_cast<Rectangle*>(item));
            removeItem(item);

            break;
        }
    }

    if(event->key() == Qt::Key_D){
        player->setFocus();
        qDebug() << "d pressed";
        qDebug() << "Can move D " << playerCanMove(2, 0);
        if(playerCanMove(2, 0))
            player->move(2,0);
    }
    else if(event->key() == Qt::Key_W){
        player->setFocus();
        qDebug() << "w pressed";
        qDebug() << "Can move W " << playerCanMove(0, -2);
        if(playerCanMove(0, -2))
            player->move(0,-2);
    }
    else if(event->key() == Qt::Key_A){
        player->setFocus();
        qDebug() << "a pressed";
        qDebug() << "Can move A " << playerCanMove(-2, 0);
        if(playerCanMove(-2, 0))
            player->move(-2,0);
    }
    else if(event->key() == Qt::Key_S){
        player->setFocus();
        qDebug() << "s pressed";
        qDebug() << "Can move S " << playerCanMove(0, 2);
        if(playerCanMove(0, 2))
            player->move(0,2);
    }

}

void GameBuilder::update()
{
    player->collidingItems();
    player->pos();
    QList<QGraphicsItem *> collidingObjects = player->collidingItems();
    foreach (QGraphicsItem* item, collidingObjects){

        qDebug() << dynamic_cast<QObject*>(item)->metaObject()->className();
        if (dynamic_cast<QObject*>(item)->metaObject()->className() == "MapBuilder"){

        }
    }

    //    player->advance(10);
}

bool GameBuilder::playerCanMove(qreal delta_x, qreal delta_y)
{
    QPointF playerPos = player->pos();
    qreal playerWidth = 60, playerHeight = 80;
    bool canMove = true;
    bool whereTo[4];

    foreach(Rectangle *r, lstRectangle) {
        QPointF rPos = r->pos();
        qreal rWidth = 100, rHeight = 100;

        if(playerPos.ry() + delta_y + playerHeight/2 >= rPos.ry() - rHeight/2 && playerPos.rx() + delta_x + playerWidth/2 >= rPos.rx() - rWidth/2)
            canMove = false;
        else if(playerPos.ry() + delta_y + playerHeight/2 >= rPos.ry() + rHeight/2 && playerPos.rx() + delta_x + playerWidth/2 >= rPos.rx() - rWidth/2)
            canMove = false;
        else if(playerPos.ry() + delta_y + playerHeight/2 >= rPos.ry() - rHeight/2 && playerPos.rx() + delta_x + playerWidth/2 >= rPos.rx() + rWidth/2)
            canMove = false;
        else if(playerPos.ry() + delta_y + playerHeight/2 >= rPos.ry() + rHeight/2 && playerPos.rx() + delta_x + playerWidth/2 >= rPos.rx() + rWidth/2)
            canMove = false;

//        if(playerPos.rx() + delta_x + playerWidth/2 >= rPos.rx() - rWidth/2)
//            canMove = false;
//        if(playerPos.rx() + delta_x + playerWidth/2 >= rPos.rx() + rWidth/2)
//            canMove = false;
    }
    return canMove;
}

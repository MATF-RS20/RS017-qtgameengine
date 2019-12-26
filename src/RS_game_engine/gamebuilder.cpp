#include "gamebuilder.h"

GameBuilder::GameBuilder(QGraphicsView* parent)
    :parent(parent)
    ,gameBuilderTimer(new QTimer())
{

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

void GameBuilder::addPlayer(qreal x, qreal y, qreal width, qreal height, QString look, QToolBox *componentInfo, QList<QLineEdit *> playerInfo, QPushButton *playerUpdate)
{
    player = new Player(x,y,width, height,look,componentInfo,playerInfo,playerUpdate);
    addItem(player);

    connect(&(*gameBuilderTimer), SIGNAL(timeout()), this, SLOT(update()));

    gameBuilderTimer->start(15);

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


    qDebug() << player->movementArray[0] << " " << player->movementArray[1] << " " << player->movementArray[2] << " " << player->movementArray[3];

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
    //W-0 A-1 S-2 D-3
    if(playerCanMoveUp(0,-4) && player->movementArray[0]){
        player->move(0,-4);
    }

    else if(playerCanMoveLeft(-4,0) && player->movementArray[1]){
        player->move(-4,0);
    }

    else if(playerCanMoveDown(0,4) && player->movementArray[2]){
        player->move(0,4);
    }

    else if(playerCanMoveRight(4,0) && player->movementArray[3]){
        player->move(4,0);
    }
}

void GameBuilder::keyReleaseEvent(QKeyEvent *event)
{
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

    qDebug() << player->movementArray[0] << " " << player->movementArray[1] << " " << player->movementArray[2] << " " << player->movementArray[3];

}

bool GameBuilder::playerCanMoveUp(qreal delta_x, qreal delta_y)
{
    QPointF playerPos = player->pos();
    qreal playerWidth = player->getWidth(), playerHeight = player->getHeight();
    qDebug() << playerPos.ry();
    foreach(Rectangle *r, lstRectangle) {
        QPointF rPos = r->pos();
        qreal rWidth = r->getWidth(), rHeight = r->getHeight();

        bool left = playerPos.rx() + playerWidth < rPos.rx();
        bool right = playerPos.rx() > rPos.rx() + rWidth;
        bool up = playerPos.ry() + playerHeight - delta_y < rPos.ry();
        bool down = playerPos.ry() + delta_y > rPos.ry() + rHeight;


        if(left || right)
            return true;
        else if(up || down)
             return true;
    }
    return false;
}

bool GameBuilder::playerCanMoveDown(qreal delta_x, qreal delta_y)
{
    QPointF playerPos = player->pos();
    qreal playerWidth = player->getWidth(), playerHeight = player->getHeight();

    foreach(Rectangle *r, lstRectangle) {
        QPointF rPos = r->pos();
        qreal rWidth = r->getWidth(), rHeight = r->getHeight();

        bool left = playerPos.rx() + playerWidth< rPos.rx();
        bool right = playerPos.rx() > rPos.rx() + rWidth;
        bool down = playerPos.ry() > rPos.ry() + rHeight + 4;
        bool up = playerPos.ry() + delta_y + playerHeight < rPos.ry();


        if(left || right)
            return true;
        else if(up || down)
             return true;
    }
    return false;
}

bool GameBuilder::playerCanMoveLeft(qreal delta_x, qreal delta_y)
{
    QPointF playerPos = player->pos();
    qreal playerWidth = player->getWidth(), playerHeight = player->getHeight();

    foreach(Rectangle *r, lstRectangle) {
        QPointF rPos = r->pos();
        qreal rWidth = r->getWidth(), rHeight = r->getHeight();

        bool up = playerPos.ry() + playerHeight < rPos.ry();
        bool down = playerPos.ry() > rPos.ry() + rHeight;
        bool left = playerPos.rx() + playerWidth - delta_x < rPos.rx();
        bool right = playerPos.rx() + delta_x > rPos.rx() + rWidth;

        if(up || down || left || right)
            return true;

    }
    return false;
}

bool GameBuilder::playerCanMoveRight(qreal delta_x, qreal delta_y)
{
    QPointF playerPos = player->pos();
    qreal playerWidth = player->getWidth(), playerHeight = player->getHeight();

    foreach(Rectangle *r, lstRectangle) {
        QPointF rPos = r->pos();
        qreal rWidth = r->getWidth(), rHeight = r->getHeight();

        bool up = playerPos.ry() + playerHeight < rPos.ry();
        bool down = playerPos.ry() > rPos.ry() + rHeight;
        bool left = playerPos.rx() + playerWidth + delta_x < rPos.rx();
        bool right = playerPos.rx() > rPos.rx() + rWidth;

        if(up || down || left || right)
            return true;

    }
    return false;
}

QGraphicsView *GameBuilder::getParent() const
{
    return parent;
}

#include "gamebuilder.h"

GameBuilder::GameBuilder(QGraphicsView* parent)
    :parent(parent)
    ,gameBuilderTimer(new QTimer()),player(nullptr)
    ,collisionEnabled(true)
    ,playerGravityApply(true)
    ,jumpEnabled(true)
{

}
/* QGraphicsView* parent;
    QTimer* gameBuilderTimer;
    Player* player;
    Rectangle* rectangle;
    QList<Rectangle*> lstRectangle;
    Enemy* enemy;
    QList<Enemy*> lstEnemy;
    QWidget* main;
    QToolBox* componentInfo;
    bool collisionEnabled;
    bool playerGravityApply;
    bool jumpPlayer;
    qreal jumpAmout;
    bool jumpEnabled;*/
GameBuilder::GameBuilder(GameBuilder* other):
    parent(other->getParent())
  ,gameBuilderTimer(other->gameBuilderTimer)
  ,collisionEnabled(other->collisionEnabled)
  ,playerGravityApply(other->playerGravityApply)
  ,jumpEnabled(other->jumpEnabled)
  ,player(other->player)
  ,lstEnemy(other->lstEnemy)
  ,main(other->main)
  ,componentInfo(other->componentInfo)
  ,jumpAmout(other->jumpAmout)
  ,jumpPlayer(other->jumpPlayer)
{

}

GameBuilder::~GameBuilder()
{
}

void GameBuilder::addRectangle(qreal x, qreal y, qreal width, qreal height,
                               QToolBox* componentInfo, QList<QLineEdit*> rectangleInfo, QPushButton* rectangleUpdate, QString lookPath)
{
    rectangle = new Rectangle(x, y, width, height, componentInfo, rectangleInfo, rectangleUpdate, lookPath);
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
    if(this->getPlayer() == nullptr){
        return;
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
    if(event->key() == Qt::Key_D){
        player->setFocus();
        player->movementArray.setBit(3,true);
        player->setCurrentLook(true);
    }
    if(event->key() == Qt::Key_F){
        player->setFocus();
        player->movementArray.setBit(4,true);
    }
    if(event->key() == Qt::Key_Space && jumpEnabled){
        if(jumpPlayer){
            return;
        }
        jumpPlayer = true;
        player->setPositionBeforeJump(player->pos().ry());
    }

//    qDebug() << player->movementArray[0] << " " << player->movementArray[1] << " " << player->movementArray[2] << " " << player->movementArray[3];

}

void GameBuilder::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        player->movementArray.setBit(0,false);
    }
    if(event->key() == Qt::Key_A){
        player->movementArray.setBit(1,false);
    }
    if(event->key() == Qt::Key_S){
        player->movementArray.setBit(2,false);
    }
    if(event->key() == Qt::Key_D){
        player->movementArray.setBit(3,false);
    }
    if(event->key() == Qt::Key_F){
        player->movementArray.setBit(4,false);
    }

//    qDebug() << player->movementArray[0] << " " << player->movementArray[1] << " " << player->movementArray[2] << " " << player->movementArray[3];

}

void GameBuilder::update()
{
    if(player == nullptr)
        return;
    player->collidingItems();
    player->pos();
    QList<QGraphicsItem *> collidingObjects = player->collidingItems();
    if(!collisionEnabled){
        foreach (QGraphicsItem* item, collidingObjects){

        //        qDebug() << dynamic_cast<QObject*>(item)->metaObject()->className();
            if (dynamic_cast<QObject*>(item)->metaObject()->className() == "MapBuilder"){

            }
        }
    }
    foreach(Enemy* e, lstEnemy){
//        qDebug() << e->getRange();
        if(e->getRange() > 0)
            e->move();
    }
    //W-0 A-1 S-2 D-3
//    qDebug() << player->movementArray;
//    qDebug() << playerCanMove(0,-4);
    //W-0 A-1 S-2 D-3
    qreal speed = 4;
    if(player->movementArray[4])
        speed *= 2;

    if(playerCanMove(0,-speed) && player->movementArray[0]){
        player->move(0,-speed);
    }

    else if(playerCanMove(-speed,0) && player->movementArray[1]){
        player->move(-speed,0);
    }

    else if(playerCanMove(0,speed) && player->movementArray[2]){
        player->move(0,speed);
    }

    else if(playerCanMove(speed,0) && player->movementArray[3]){
        player->move(speed,0);
    }

    //Hardcoded constant 25
    if(player->getY() + player->getHeight() + 25 < parent->height() && playerGravityApply && playerCanMove(0,4))
        player->gravityApply();

    if(jumpPlayer && jumpAmout < 24){

        player->jumpAnimation();
        jumpAmout += 1;
    }
    else{
        jumpPlayer = false;
        jumpAmout = 0;
    }
}

QTimer *GameBuilder::getGameBuilderTimer() const
{
    return gameBuilderTimer;
}


bool GameBuilder::playerCanMove(qreal delta_x, qreal delta_y)
{
    if(!collisionEnabled){
        return true;
    }

    QPointF playerPos = player->pos();
    qreal playerWidth = player->getWidth(), playerHeight = player->getHeight();
    foreach(Rectangle *r, lstRectangle) {
        QPointF rPos = r->pos();
        qreal rWidth = r->getWidth(), rHeight = r->getHeight();

        bool left = playerPos.rx() + delta_x + playerWidth > rPos.rx();
        bool up = playerPos.ry() + delta_y + playerHeight > rPos.ry();
        bool right = playerPos.rx() + delta_x < rPos.rx() + rWidth;
        bool down = playerPos.ry() + delta_y < rPos.ry() + rHeight;
        if(left && up && right && down){

            return false;
        }
    }
    return true;
}

QList<Enemy *> GameBuilder::getLstEnemy() const
{
    return lstEnemy;
}

void GameBuilder::setLstEnemy(const QList<Enemy *> &value)
{
    lstEnemy = value;
}

Player *GameBuilder::getPlayer() const
{
    return player;
}

void GameBuilder::setPlayer(Player *value)
{
    player = value;
}

QGraphicsView *GameBuilder::getParent() const
{
    return parent;
}

void GameBuilder::setMoveUpDownPlayer(bool checked)
{
    player->setMoveUpDownEnabled(checked);
}

void GameBuilder::setGravityPlayer(bool checked)
{
    this->playerGravityApply = checked;
    player->setGravityEnabled(checked);
}

void GameBuilder::setCollisionEnabled(bool checked)
{
    this->collisionEnabled = checked;
}

void GameBuilder::setBoostEnabled(bool checked)
{
    player->setBoostEnabled(checked);
}

void GameBuilder::setJumpEnabled(bool checked)
{
    this->jumpEnabled = checked;
}

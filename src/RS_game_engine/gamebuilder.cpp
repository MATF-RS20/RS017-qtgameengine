#include "gamebuilder.h"

GameBuilder::GameBuilder(QGraphicsView* parent)
    :parent(parent)
    ,gameBuilderTimer(new QTimer())
    ,player(nullptr)
    ,collisionEnabled(true)
    ,playerGravityApply(true)
    ,jumpEnabled(true)
    ,playerExists(false)
    ,playerSpeed(4)
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

void GameBuilder::addPositiveObstacle(qreal x, qreal y, qreal width, qreal height, QToolBox *componentInfo, QList<QLineEdit *> positiveObstacleInfo, QPushButton *positiveObstacleUpdate, QString lookPath)
{
    positiveObstacle = new PositiveObstacle(x, y, width, height, componentInfo, positiveObstacleInfo, positiveObstacleUpdate, lookPath);
    addItem(positiveObstacle);
    lstPositiveObstacle.append(positiveObstacle);
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
    connect(playerUpdate, SIGNAL(clicked()), this, SLOT(playerUpdateClicked()));
    player = new Player(x,y,width, height,look,componentInfo,playerInfo,playerUpdate);
    addItem(player);
    playerExists = true;
    connect(&(*gameBuilderTimer), SIGNAL(timeout()), this, SLOT(update()));

    gameBuilderTimer->start(15);
}

void GameBuilder::keyPressEvent(QKeyEvent *event)
{
    if(!playerExists)
        return;
    foreach(QGraphicsItem* item, items()){
        if(item->hasFocus() && event->key() == Qt::Key_Delete){
            lstRectangle.removeOne(dynamic_cast<Rectangle*>(item));
            removeItem(item);

            break;
        }
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
    if(event->key() == Qt::Key_E){
        foreach(Enemy* e ,lstEnemy){
            if(componentInfo->itemText(1) == ("Enemy " + QString::number(e->getId()))){
                qDebug() << "been here";
                enemy = new Enemy(e->getX() -20, e->getY() + 20, e->getWidth(), e->getHeight(), e->getRange(), e->getLookString(),
                                  componentInfo, e->getEnemyInfo(), e->getEnemyUpdate());
                addItem(enemy);
                lstEnemy.append(enemy);
            }
        }
    }

//    qDebug() << player->movementArray[0] << " " << player->movementArray[1] << " " << player->movementArray[2] << " " << player->movementArray[3];

}

void GameBuilder::keyReleaseEvent(QKeyEvent *event)
{
    if(!playerExists)
            return;
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
    if(!playerExists)
        return;
    player->collidingItems();
    player->pos();
    QList<QGraphicsItem *> collidingObjects = player->collidingItems();
    if(collisionEnabled){
        foreach (QGraphicsItem* item, collidingObjects){
            if(item->type() == 3){
                removeItem(item);
            }
            if (dynamic_cast<QObject*>(item)->metaObject()->className() == "MapBuilder"){
            }
        }
    }
    foreach(Enemy* e, lstEnemy){
//        qDebug() << e->getRange();
        if(e->getRange() > 0){
            if(enemyCanMove(e, e->getSpeed(), 0)){
                e->move();
            }
            else{
                e->setSpeed(e->getSpeed() * -1);
                e->move();
            }

        }
        if(e->pos().ry() + e->getHeight() +25 < parent->height() && e->EnemyGravityEnabled() && enemyCanMove(e,0,4))
            e->gravityApply();

    }
    //W-0 A-1 S-2 D-3
//    qDebug() << player->movementArray;
//    qDebug() << playerCanMove(0,-4);
    //W-0 A-1 S-2 D-3
    if(player->movementArray[4])
        playerSpeed = player->getBoost();

    if(playerCanMove(0,-playerSpeed) && player->movementArray[0]){
        player->move(0,-playerSpeed);
    }

    if(playerCanMove(-playerSpeed,0) && player->movementArray[1]){

        if(player->getX()  < parent->horizontalScrollBar()->value() + (parent->width()/2.0))
            parent->horizontalScrollBar()->setValue(player->getX() - (parent->width()/2.0));

        player->move(-playerSpeed,0);
    }

    if(playerCanMove(0,playerSpeed) && player->movementArray[2]){
        player->move(0,playerSpeed);
    }

    if(playerCanMove(playerSpeed,0) && player->movementArray[3]){
        if(player->getX() + player->getWidth() > parent->horizontalScrollBar()->value() + (parent->width()/2.0))
            parent->horizontalScrollBar()->setValue(player->getX() + player->getWidth()-(parent->width()/2.0));
        player->move(playerSpeed,0);
    }

    if(player->getY() + player->getHeight() +25 < parent->height() && playerGravityApply && playerCanMove(0,4))
        player->gravityApply();

    if(jumpPlayer && jumpAmout < 24){
        if(playerCanMove(0,-playerSpeed)){
            player->jumpAnimation(jumpAmout);
            jumpAmout += 1;
        }
        else{
            jumpPlayer = false;
            jumpAmout = 0;
        }
    }
    else{
        jumpPlayer = false;
        jumpAmout = 0;
    }
}

void GameBuilder::playerUpdateClicked()
{
    playerSpeed = player->getSpeed();
}

void GameBuilder::setComponentInfo(QToolBox *value)
{
    componentInfo = value;
}

bool GameBuilder::getCollisionEnabled() const
{
    return collisionEnabled;
}

QTimer *GameBuilder::getGameBuilderTimer() const
{
    return gameBuilderTimer;
}

bool GameBuilder::getJumpEnabled() const
{
    return jumpEnabled;
}

bool GameBuilder::getJumpPlayer() const
{
    return jumpPlayer;
}

qreal GameBuilder::getJumpAmout() const
{
    return jumpAmout;
}

bool GameBuilder::getPlayerGravityApply() const
{
    return playerGravityApply;
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

bool GameBuilder::enemyCanMove(Enemy *enemy, qreal delta_x, qreal delta_y)
{
    QPointF enemyPos = enemy->pos();
    qreal enemyWidth = enemy->getWidth(), enemyHeight = enemy->getHeight();
    foreach(Rectangle *r, lstRectangle) {
        QPointF rPos = r->pos();
        qreal rWidth = r->getWidth(), rHeight = r->getHeight();

        bool left = enemyPos.rx() + delta_x + enemyWidth > rPos.rx();
        bool up = enemyPos.ry() + delta_y + enemyHeight > rPos.ry();
        bool right = enemyPos.rx() + delta_x < rPos.rx() + rWidth;
        bool down = enemyPos.ry() + delta_y < rPos.ry() + rHeight;
        if(left && up && right && down){
            return false;
        }
    }
    return true;
}

void GameBuilder::setUpDownMovementEnabled(bool checked)
{
    for(Enemy* e : lstEnemy){
        e->upDownMovementEnabled(checked);
    }
}

void GameBuilder::setLeftRightMovementEnabled(bool checked)
{
    for(Enemy* e : lstEnemy){
        e->leftRightMovementEnabled(checked);
    }
}

void GameBuilder::setEnemyGravityEnabled(bool checked)
{
    for(Enemy* e : lstEnemy){
        e->setGravityEnabled(checked);
    }
}

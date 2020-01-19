#include "gamebuilder.h"

GameBuilder::GameBuilder(QGraphicsView* parent)
    :parent(parent)
    ,collisionEnabled(true)
    ,gameBuilderTimer(new QTimer())
    ,playerGravityApply(true)
    ,player(nullptr)
    ,jumpEnabled(true)
    ,jumpAllowed(false)
    ,playerExists(false)
    ,playerSpeed(4)
    ,levelPassedAdded(false)
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

void GameBuilder::addLevelPassed(qreal x, qreal y, qreal width, qreal height, QToolBox *componentInfo, QList<QLineEdit *> levelPassedInfo, QPushButton *levelPassedUpdate, QString lookPath)
{
    if(!levelPassedAdded){
        levelPassed = new LevelPassed(x, y, width, height, componentInfo, levelPassedInfo, levelPassedUpdate, lookPath);
        addItem(levelPassed);
        levelPassedAdded = true;
    }
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
    player->setPlayersBulletLook(this->playersBulletLook);
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
        if(jumpAllowed){
            jumpPlayer = true;
        }
        player->setPositionBeforeJump(player->pos().ry());
    }
    if(event->key() == Qt::Key_E){
        foreach(Enemy* e ,lstEnemy){
            if(componentInfo->itemText(1) == ("Enemy " + QString::number(e->getId()))){
                enemy = new Enemy(e->getX() -20, e->getY() + 20, e->getWidth(), e->getHeight(), e->getRange(), e->getLookString(),
                                  componentInfo, e->getEnemyInfo(), e->getEnemyUpdate());
                addItem(enemy);
                lstEnemy.append(enemy);
            }
        }
    }
    if(event->key() == Qt::Key_R){
        foreach(Rectangle* r ,lstRectangle){
              if(componentInfo->itemText(0) == ("Rectangle " + QString::number(r->getId()))){
                rectangle = new Rectangle(r->getX() -20, r->getY() + 20, r->getWidth(), r->getHeight(),
                                  componentInfo, r->getRectangleInfo(), r->getRectangleUpdate(),r->getLookString());
                addItem(rectangle);
                lstRectangle.append(rectangle);
            }
        }
    }
    if(event->key() == Qt::Key_P){
        foreach(PositiveObstacle* p ,lstPositiveObstacle){
              if(componentInfo->itemText(3) == ("Positive Obstacle " + QString::number(p->getId()))){
                positiveObstacle = new PositiveObstacle(p->getX() -20, p->getY() + 20, p->getWidth(), p->getHeight(),
                                  componentInfo, p->getPositiveObstacleInfo(), p->getPositiveObstacleUpdate(),p->getLookString());
                addItem(positiveObstacle);
                lstPositiveObstacle.append(positiveObstacle);
            }
        }
    }
    if(event->key() == Qt::Key_B){
        if(!player->getBulletEnabled()){
            return;
        }
        if(player->getIsRight()){
            Bullet* bullet = new Bullet(player->getX() + player->getWidth(), player->getY() + 20, 30, 20, true, player->getBulletSpeed());
            lstPlayerBullets.append(bullet);
            if(playersBulletLook != nullptr)
                bullet->setTexture(playersBulletLook);
            addItem(bullet);
        }
        else{
            Bullet* bullet = new Bullet(player->getX(), player->getY() + 20, 30, 20, false, player->getBulletSpeed());
            lstPlayerBullets.append(bullet);
            if(playersBulletLook != nullptr)
                bullet->setTexture(playersBulletLook);
            addItem(bullet);
        }
    }

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
}

void GameBuilder::update()
{
    if(!playerExists)
        return;
    if(!playerCanMove(0,playerSpeed)){
        jumpAllowed = true;
    }
    else{
        jumpAllowed = false;
    }

    player->collidingItems();
    player->pos();
    QList<QGraphicsItem *> collidingObjects = player->collidingItems();
    if(collisionEnabled){
        foreach (QGraphicsItem* item, collidingObjects){
            if(item->type() == 3){
                removeItem(item);
            }
            if(item->type() == 5) {
                //Collisio with bullet what to do ?
            }
        }
    }
    foreach(Enemy* e, lstEnemy){

        //bullet fire
        if(e->getBulletEnabled()){
            if(e->getSpeed() > 0){
                if(e->bullets.isEmpty() || e->bullets.back()->getDistancePassed() >= e->getBulletDistanceTillNext() ){
                    Bullet* bullet = new Bullet(e->getX() + e->getWidth(), e->getY() + 20, 30, 20, true, e->getBulletSpeed());
                    e->bullets.append(bullet);
                    addItem(bullet);
                }
            }
            else{
                if(e->bullets.isEmpty() || e->bullets.back()->getDistancePassed() >= e->getBulletDistanceTillNext()){
                    Bullet* bullet = new Bullet(e->getX(), e->getY() + 20, 30, 20, false, e->getBulletSpeed());
                    e->bullets.append(bullet);
                    addItem(bullet);
                }
            }
        }
        if(!e->bullets.isEmpty()){
            if(e->bullets.front()->getDistancePassed() > parent->width()){
                removeItem(e->bullets.front());
                delete e->bullets.front();
                e->bullets.removeFirst();
            }
        }

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

        if(!e->bullets.isEmpty()){
            foreach(QGraphicsItem* item, e->bullets){
                bool bulletDeleted = false;
                QList<QGraphicsItem*> itemsColided = item->collidingItems();
                foreach(QGraphicsItem* ic, itemsColided){
                    if(ic->type() == 1){
                        e->bullets.removeOne(dynamic_cast<Bullet*>(item));
                        removeItem(item);
                        delete item;
                        bulletDeleted = true;
                        break;
                    }

                    if(ic->type() == 4){
                        player->setHealthPoints(player->getHealthPoints() - e->getBulletPower());
                        qDebug() << player->getHealthPoints();

                        e->bullets.removeOne(dynamic_cast<Bullet*>(item));
                        removeItem(item);
                        delete item;
                        bulletDeleted = true;
//                        if(player->getHealthPoints())
//                            return;
                        break;
                    }

                }
            }
        }
    }

    foreach(QGraphicsItem* item, lstPlayerBullets){
        bool bulletDeleted = false;
        QList<QGraphicsItem*> itemsColided = item->collidingItems();
        foreach(QGraphicsItem* ic, itemsColided){
            if(ic->type() == 1){
                lstPlayerBullets.removeOne(dynamic_cast<Bullet*>(item));
                removeItem(item);
                delete item;
                bulletDeleted = true;
                break;
            }

            if(ic->type() == 2){
                Enemy *eHit = dynamic_cast<Enemy*>(ic);
                eHit->setHealthPoints(eHit->getHealthPoints() - player->getBulletPower());
                qDebug() << eHit->getHealthPoints();
                lstPlayerBullets.removeOne(dynamic_cast<Bullet*>(item));
                removeItem(item);
                delete item;
                bulletDeleted = true;

                if(eHit->getHealthPoints() <= 0){
                    lstEnemy.removeOne(eHit);
                    removeItem(eHit);
                    delete  eHit;
                }

                break;


            }

        }
        if(!bulletDeleted && dynamic_cast<Bullet*>(item)->getDistancePassed() > parent->width()){
            lstPlayerBullets.removeOne(dynamic_cast<Bullet*>(item));
            removeItem(item);delete item;
        }
    }

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

    foreach(Enemy *e, lstEnemy) {
        QPointF ePos = e->pos();
        qreal eWidth = e->getWidth(), eHeight = e->getHeight();

        bool left = playerPos.rx() + delta_x + playerWidth > ePos.rx();
        bool up = playerPos.ry() + delta_y + playerHeight > ePos.ry();
        bool right = playerPos.rx() + delta_x < ePos.rx() + eWidth;
        bool down = playerPos.ry() + delta_y < ePos.ry() + eHeight;
        if(left && up && right && down){
            player->setHealthPoints(player->getHealthPoints() - e->getCollisionDamage());
            qDebug() << player->getHealthPoints() << " Hello from gambuilder";
            player->move(-delta_x, -delta_y);
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

    bool leftPlayer = enemyPos.rx() + delta_x + enemyWidth > player->pos().rx();
    bool upPlayer = enemyPos.ry() + delta_y + enemyHeight > player->pos().ry();
    bool rightPlayer = enemyPos.rx() + delta_x < player->pos().rx() + player->getWidth();
    bool downPlayer = enemyPos.ry() + delta_y < player->pos().ry() + player->getHeight();
    if(leftPlayer && upPlayer && rightPlayer && downPlayer)
        return false;

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

void GameBuilder::setPlayerBulletEnabled(bool checked)
{
    player->setBulletEnabled(checked);
}

void GameBuilder::setTextureToPlayersBullet(QString lookPath)
{
    this->playersBulletLook = lookPath;
}

void GameBuilder::setEnemyBulletEnabled(bool checked) const
{
    foreach(Enemy* e, lstEnemy){
        if(componentInfo->itemText(1) == "Enemy " + QString::number(e->getId())){
            e->setBulletEnabled(checked);
            break;
        }
    }
}

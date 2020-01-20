#include "gamestart.h"
#include "ui_gamestart.h"

GameStart::GameStart(/*QWidget *parent,*/ bool collision, bool gravity, qreal jump, bool jumpPlayer, bool jumpEnabled) :
    /*QWidget(parent),*/
    Points(0),
    ui(new Ui::GameStart),
    timer(new QTimer()),
    collisionEnabled(collision),
    playerGravityApply(gravity),
    jumpAmout(jump),
    jumpPlayer(jumpPlayer),
    jumpEnabled(jumpEnabled),
    jumpAllowed(false)
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
        ui->graphicsView->verticalScrollBar()->setValue(ui->graphicsView->verticalScrollBar()->maximum());
        ui->graphicsView->horizontalScrollBar()->setValue(ui->graphicsView->horizontalScrollBar()->minimum());
        ui->graphicsView->horizontalScrollBar()->hide();
        ui->graphicsView->verticalScrollBar()->hide();
        ui->graphicsView->setSceneRect(exactRect);
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
                qDebug() << oldX << oldY;
                qreal refX = oldX - ref.rx();
                qreal refY =ref.ry() - oldY;
                qreal newX  = refX+new_ref.rx();
                qreal newY = new_ref.ry() - refY;
                qDebug() << newX << newY;
                r->setX(newX);
                r->setY(newY);
                r->setPos(newX,newY);
                new_scene->addItem(r);
                if(item->type() == 1){
                    lstRectangle.push_back(qgraphicsitem_cast<Rectangle*>(item));
                }
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
                if(item->type() == 4){
                    player = qgraphicsitem_cast<Player*>(item);
                    playerSpeed = player->getSpeed();
                } else {
                   lstEnemy.push_back(qgraphicsitem_cast<Enemy*>(item));
                }
            }
      }
      if(player != nullptr){
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
       }else if(item->type() == 4 || item->type() == 2){
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
    foreach(Enemy *e, lstEnemyKilled){
        qreal oldX = e->getX();
        qreal oldY = e->getY();
        qreal refX = oldX - ref.rx();
        qreal refY =ref.ry() - oldY;
        qreal newX  = refX+new_ref.rx();
        qreal newY = new_ref.ry() - refY;
        e->setX(newX);
        e->setY(newY);
        e->setPos(newX,newY);
        scene->scene()->addItem(e);
    }
    timer->stop();
    gameON->getGameBuilderTimer()->start(15);


    event->accept();
}
void GameStart::resizeEvent(QResizeEvent* event){
        QPoint ref(0,800);
        QPoint new_ref(0,event->size().height());
        QRectF exactRect(0, 0, /*this->size().width()*/ 4000, this->size().height());
//        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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

bool pom = true;
void GameStart::update()
{
    if(!playerCanMoveStart(0,playerSpeed)){
        jumpAllowed = true;
    }
    else{
        jumpAllowed = false;
    }
    if(pom){
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
        pom = false;
    }
    if(player == nullptr)
        return;
    player->collidingItems();
    player->pos();
    QList<QGraphicsItem *> collidingObjects = player->collidingItems();
    if(this->collisionEnabled){
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

        //bullet fire
        if(e->getBulletEnabled()){
            if(e->getSpeed() > 0){
                if(e->bullets.isEmpty() || e->bullets.back()->getDistancePassed() >= e->getBulletDistanceTillNext() ){
                    Bullet* bullet = new Bullet(e->getX() + e->getWidth(), e->getY() + 20, 30, 20, true, e->getBulletSpeed());
                    e->bullets.append(bullet);
                    ui->graphicsView->scene()->addItem(bullet);
                }
            }
            else{
                if(e->bullets.isEmpty() || e->bullets.back()->getDistancePassed() >= e->getBulletDistanceTillNext()){
                    Bullet* bullet = new Bullet(e->getX(), e->getY() + 20, 30, 20, false, e->getBulletSpeed());
                    e->bullets.append(bullet);
                    ui->graphicsView->scene()->addItem(bullet);
                }
            }
        }
        if(!e->bullets.isEmpty()){
            if(e->bullets.front()->getDistancePassed() > ui->graphicsView->scene()->width()){
                ui->graphicsView->scene()->removeItem(e->bullets.front());
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
        if(e->pos().ry() + e->getHeight() +25 < ui->graphicsView->scene()->height() && e->EnemyGravityEnabled() && enemyCanMove(e,0,4))
            e->gravityApply();

        if(!e->bullets.isEmpty()){
            foreach(QGraphicsItem* item, e->bullets){
                bool bulletDeleted = false;
                QList<QGraphicsItem*> itemsColided = item->collidingItems();
                foreach(QGraphicsItem* ic, itemsColided){
                    if(ic->type() == 1){
                        e->bullets.removeOne(dynamic_cast<Bullet*>(item));
                        ui->graphicsView->scene()->removeItem(item);
                        delete item;
                        bulletDeleted = true;
                        break;
                    }

                    if(ic->type() == 4){
                        player->setHealthPoints(player->getHealthPoints() - e->getBulletPower());
                        qDebug() << player->getHealthPoints();

                        e->bullets.removeOne(dynamic_cast<Bullet*>(item));
                        ui->graphicsView->scene()->removeItem(item);
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
                ui->graphicsView->scene()->removeItem(item);
                delete item;
                bulletDeleted = true;
                break;
            }

            if(ic->type() == 2){
                Enemy *eHit = dynamic_cast<Enemy*>(ic);
                eHit->setHealthPoints(eHit->getHealthPoints() - player->getBulletPower());
                qDebug() << eHit->getHealthPoints();
                lstPlayerBullets.removeOne(dynamic_cast<Bullet*>(item));
                ui->graphicsView->scene()->removeItem(item);
                delete item;
                bulletDeleted = true;

                if(eHit->getHealthPoints() <= 0){
//                    lstEnemy.removeOne(eHit);dddd


                    ui->graphicsView->scene()->removeItem(eHit);
                    this->lstEnemyKilled.append(eHit);
                    eHit->setBulletEnabled(false);

//                    delete  eHit;
                }

                break;


            }

        }
        if(!bulletDeleted && dynamic_cast<Bullet*>(item)->getDistancePassed() > ui->graphicsView->scene()->width()){
            lstPlayerBullets.removeOne(dynamic_cast<Bullet*>(item));
            ui->graphicsView->scene()->removeItem(item);delete item;
        }
    }

    //W-0 A-1 S-2 D-3
    if(player->movementArray[4])
        playerSpeed *= 2;

    if(playerCanMoveStart(0,-playerSpeed) && player->movementArray[0]){
        player->move(0,-playerSpeed);
    }

    if(playerCanMoveStart(-playerSpeed,0) && player->movementArray[1]){
        if(player->getX()  < ui->graphicsView->horizontalScrollBar()->value() + (ui->graphicsView->width()/2.0))
            ui->graphicsView->horizontalScrollBar()->setValue(player->getX() - (ui->graphicsView->width()/2.0));
        player->move(-playerSpeed,0);
    }

    if(playerCanMoveStart(0,playerSpeed) && player->movementArray[2]){
        player->move(0,playerSpeed);
    }

    if(playerCanMoveStart(playerSpeed,0) && player->movementArray[3]){
        if(player->getX() + player->getWidth() > ui->graphicsView->horizontalScrollBar()->value() + (ui->graphicsView->width()/2.0)){
            ui->graphicsView->horizontalScrollBar()->setValue(player->getX() + player->getWidth()-(ui->graphicsView->width()/2.0));
        }
        player->move(playerSpeed,0);
    }
    if(player->getY() + player->getHeight() < ui->graphicsView->scene()->height() && playerGravityApply && playerCanMoveStart(0,player->getGravityIntensity()))
        player->gravityApply();

    if(jumpPlayer && jumpAmout < 24){
        if(playerCanMoveStart(0,-playerSpeed)){
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
void GameStart::keyReleaseEvent(QKeyEvent *event)
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

}

void GameStart::keyPressEvent(QKeyEvent *event)
{

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
    if(event->key() == Qt::Key_Space && jumpEnabled){
        if(jumpPlayer){
            return;
        }
        if(jumpAllowed){
            jumpPlayer = true;
        }
        player->setPositionBeforeJump(player->pos().ry());
    }

    if(event->key() == Qt::Key_B){

        if(!player->getBulletEnabled()){
            return;
        }

        if(player->getIsRight()){
            Bullet* bullet = new Bullet(player->getX() + player->getWidth(), player->getY() + 20, 30, 20, true, player->getBulletSpeed());
            lstPlayerBullets.append(bullet);
            if(player->getPlayersBulletLook() != nullptr)
                bullet->setTexture(player->getPlayersBulletLook());
            ui->graphicsView->scene()->addItem(bullet);
        }
        else{
            Bullet* bullet = new Bullet(player->getX(), player->getY() + 20, 30, 20, false, player->getBulletSpeed());
            lstPlayerBullets.append(bullet);
            if(player->getPlayersBulletLook() != nullptr)
                bullet->setTexture(player->getPlayersBulletLook());
            ui->graphicsView->scene()->addItem(bullet);
        }
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

bool GameStart::playerCanMoveStart(qreal delta_x, qreal delta_y)
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
//    qDebug() << lstEnemy.size();
    foreach(Enemy *e, lstEnemy) {
        QPointF ePos = e->pos();
        qreal eWidth = e->getWidth(), eHeight = e->getHeight();

        bool left = playerPos.rx() + delta_x + playerWidth > ePos.rx();
        bool up = playerPos.ry() + delta_y + playerHeight > ePos.ry();
        bool right = playerPos.rx() + delta_x < ePos.rx() + eWidth;
        bool down = playerPos.ry() + delta_y < ePos.ry() + eHeight;
        if(left && up && right && down){
            player->setHealthPoints(player->getHealthPoints() - e->getCollisionDamage());
            qDebug() << player->getHealthPoints();
            if(std::find(this->lstEnemyKilled.begin(), this->lstEnemyKilled.end(), e) == this->lstEnemyKilled.end()){
                player->move(-delta_x, -delta_y);
                qDebug() << "IMA GA";
                return false;
            }

        }
    }

    return true;
}

bool GameStart::enemyCanMove(Enemy *enemy, qreal delta_x, qreal delta_y)
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

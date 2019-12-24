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
        if(playerCanMove(4, 0)){
            player->setCurrentLook(true);
            player->move(4,0);
        }
    }
    else if(event->key() == Qt::Key_W){
        player->setFocus();
        if(playerCanMove(0, -4))
            player->move(0,-4);
    }
    else if(event->key() == Qt::Key_A){
        player->setFocus();
        if(playerCanMove(-4, 0)){
            player->setCurrentLook(false);
            player->move(-4,0);
        }
    }
    else if(event->key() == Qt::Key_S){
        player->setFocus();
        if(playerCanMove(0, 4))
            player->move(0,4);
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
    qreal playerWidth = player->getWidth(), playerHeight = player->getHeight();

    foreach(Rectangle *r, lstRectangle) {
        QPointF rPos = r->pos();
        qreal rWidth = r->getWidth(), rHeight = r->getHeight();

        bool a1 = playerPos.ry() + delta_y + playerHeight/2 > rPos.ry() - rHeight/2;
        bool a2 = playerPos.rx() + delta_x + playerWidth/2 > rPos.rx() - rWidth/2;
        bool a3 = playerPos.ry() + delta_y - playerHeight/2 < rPos.ry() + rHeight/2;
        bool a4 = playerPos.rx() + delta_x - playerWidth/2 < rPos.rx() + rWidth/2;
        qDebug() << a1 << " " << a2 << " " << a3 << " " << a4;
        if(a1 && a2 && a3 && a4){
            return false;
        }
    }
    return true;
}

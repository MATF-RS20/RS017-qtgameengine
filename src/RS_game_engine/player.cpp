#include "player.h"
#include <QDebug>

Player::Player(qreal x, qreal y, qreal width, qreal height, QString look,
               QToolBox* componentInfo,QList<QLineEdit*> playerInfo, QPushButton* playerUpdate)
    : GameComponent(x, y, width, height)
    ,lookRight(look)
    ,componentInfo(componentInfo)
    ,playerInfo(playerInfo)
    ,playerUpdate(playerUpdate)
    ,movementArray(4)
{
    setFlags(ItemIsMovable|ItemIsFocusable);
    int indexOfR = look.lastIndexOf('R');
    int indexOfDot = look.length() - look.lastIndexOf('.');
    QString lookL = look.left(indexOfR) + "Left" + look.right(indexOfDot);
    lookLeft = QPixmap(lookL);
    connect(playerUpdate, SIGNAL(clicked()), this, SLOT(pbApply()));
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    playerInfo.at(0)->setPlaceholderText(QString::number(this->pos().rx()));
    playerInfo.at(1)->setPlaceholderText(QString::number(this->pos().ry()));
    painter->drawPixmap(0, 0, width, height, this->isRight ? lookRight : lookLeft);
}

void Player::advance(int step)
{

}

void Player::move(qreal delta_x, qreal delta_y)
{
    if(movementArray[0]){
        y-=4;
    }

    if(movementArray[1]){
        x-=4;
    }

    if(movementArray[2]){
        y+=4;
    }

    if(movementArray[3]){
        x+=4;
    }
    this->setPos(x, y);

    update();
}

qreal Player::getHeight()
{
    return this->height;
}

qreal Player::getWidth()
{
    return this->width;
}

void Player::setCurrentLook(bool right)
{
    this->isRight = right;
}


void Player::pbApply()
{
    this->x = (qreal)playerInfo.at(0)->text().toFloat();
    this->y = (qreal)playerInfo.at(1)->text().toFloat();
    this->setPos((qreal)playerInfo.at(0)->text().toFloat(), (qreal)playerInfo.at(1)->text().toFloat());
    this->width = (qreal)playerInfo.at(2)->text().toFloat();
    this->height = (qreal)playerInfo.at(3)->text().toFloat();
    update();
}

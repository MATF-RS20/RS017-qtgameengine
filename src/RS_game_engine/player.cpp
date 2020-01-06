#include "player.h"
#include <QDebug>

Player::Player(qreal x, qreal y, qreal width, qreal height, QString look,
               QToolBox* componentInfo,QList<QLineEdit*> playerInfo, QPushButton* playerUpdate)
    : GameComponent(x, y, width, height)
    ,lookRight(look)
    ,componentInfo(componentInfo)
    ,playerInfo(playerInfo)
    ,playerUpdate(playerUpdate)
    ,movementArray(5)
    ,jumpEnabled(true)
    ,gravityEnabled(true)
    ,moveUpDownEnabled(true)
    ,boost(10)
    ,boostEnabled(true)
{
    setFlags(ItemIsMovable|ItemIsFocusable);
    lookLeft = lookRight.transformed(QTransform().scale(-1,1));
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    playerInfo.at(0)->setPlaceholderText(QString::number(this->pos().rx()));
    playerInfo.at(1)->setPlaceholderText(QString::number(this->pos().ry()));
    painter->drawPixmap(0, 0, width, height, this->isRight ? lookRight : lookLeft);
}


void Player::move(qreal delta_x, qreal delta_y)
{

    if(movementArray[0] && moveUpDownEnabled){
        if(movementArray[4] && boostEnabled)
            y -= boost;
        else
            y -= 4;
    }

    if(movementArray[1]){
        if(movementArray[4] && boostEnabled)
            x -= boost;
        else
            x -= 4;
    }

    if(movementArray[2] && moveUpDownEnabled){
        if(movementArray[4] && boostEnabled)
            y += boost;
        else
            y += 4;
    }

    if(movementArray[3]){
        if(movementArray[4] && boostEnabled)
            x += boost;
        else
            x += 4;
    }

    this->setPos(x, y);
    update();
}

void Player::setMoveUpDownEnabled(bool checked)
{
    this->moveUpDownEnabled = checked;
}

void Player::setGravityEnabled(bool checked)
{
    this->gravityEnabled = checked;
}

void Player::gravityApply(qreal value)
{
    y += value;
    this->setPos(x, y);
    update();
}

void Player::setBoostEnabled(bool checked)
{
    this->boostEnabled = checked;
}

void Player::setCurrentSpeed(qreal speed)
{
    this->speed = speed;
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

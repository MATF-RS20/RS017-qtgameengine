#include "player.h"
#include <QDebug>

Player::Player(qreal x, qreal y, qreal width, qreal height, QString look,
               QToolBox* componentInfo,QList<QLineEdit*> playerInfo, QPushButton* playerUpdate)
    : GameComponent(x, y, width, height)
    ,look(look)
    ,componentInfo(componentInfo)
    ,playerInfo(playerInfo)
    ,playerUpdate(playerUpdate)
{
    setFlags(ItemIsMovable|ItemIsFocusable);

    connect(playerUpdate, SIGNAL(clicked()), this, SLOT(pbApply()));
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0, 0, width, height, look);
}

void Player::advance(int step)
{

}

void Player::move(qreal delta_x, qreal delta_y)
{
    x += delta_x;
    y += delta_y;
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

void Player::pbApply()
{
    this->x = (qreal)playerInfo.at(0)->text().toFloat();
    this->y = (qreal)playerInfo.at(1)->text().toFloat();
    this->setPos((qreal)playerInfo.at(0)->text().toFloat(), (qreal)playerInfo.at(1)->text().toFloat());
    this->width = (qreal)playerInfo.at(2)->text().toFloat();
    this->height = (qreal)playerInfo.at(3)->text().toFloat();
    update();
}

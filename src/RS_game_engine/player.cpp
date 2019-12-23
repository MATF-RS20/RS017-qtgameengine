#include "player.h"
#include <QDebug>

Player::Player(qreal x, qreal y)
    : GameComponent(x, y, 60, 80)
    ,look("../RS_game_engine/images/player.jpg")
{

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

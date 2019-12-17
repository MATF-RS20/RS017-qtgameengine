#include "player.h"

Player::Player(qreal x, qreal y)
    : GameComponent(x, y, 60, 80)
    ,look("../RS_game_engine/images/player.jpg")
{

}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, width, height, look);
}

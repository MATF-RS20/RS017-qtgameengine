#ifndef PLAYER_H
#define PLAYER_H

#include "gamecomponent.h"
#include <QPixmap>


class Player : public GameComponent
{
    Q_OBJECT
public:
    Player(qreal x, qreal y);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void advance(int step) override;
    void move(qreal delta_x, qreal delta_y);
private:
    QPixmap look;

};

#endif // PLAYER_H

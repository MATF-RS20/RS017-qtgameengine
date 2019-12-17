#include "gamecomponent.h"

GameComponent::GameComponent(qreal x, qreal y, qreal width, qreal height)
    :x(x)
    ,y(y)
    ,width(width)
    ,height(height)
{
    setPos(x, y);
}

QRectF GameComponent::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

QPainterPath GameComponent::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, width, height);
    return path;
}

void GameComponent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(0, 0, width, height);
}

void GameComponent::pbApply(){}

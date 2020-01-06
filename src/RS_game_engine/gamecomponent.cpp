#include "gamecomponent.h"

GameComponent::GameComponent(qreal x, qreal y, qreal width, qreal height)
    :x(x)
    ,y(y)
    ,width(width)
    ,height(height)
{
    setAcceptDrops(true);
    setPos(x, y);
}
GameComponent::GameComponent(GameComponent &a):
    x(a.getX()),
    y(a.getY()),
    width(a.getWidth()),
    height(a.getHeight())
{
    setPos(x,y);
}
GameComponent::~GameComponent(){
    delete this;
}

void GameComponent::gravity(bool wantGravity)
{
    if(wantGravity == true){
        y+=5;
        this->setPos(x,y);
        update();
    }
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

qreal GameComponent::getHeight() const
{
    return height;
}

void GameComponent::setHeight(const qreal &value)
{
    height = value;
}

qreal GameComponent::getWidth() const
{
    return width;
}

void GameComponent::setWidth(const qreal &value)
{
    width = value;
}

qreal GameComponent::getY() const
{
    return y;
}

void GameComponent::setY(const qreal &value)
{
    y = value;
}

qreal GameComponent::getX() const
{
    return x;
}

void GameComponent::setX(const qreal &value)
{
    x = value;
}
void GameComponent::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(event->scenePos());
    this->setX(event->scenePos().rx());
    this->setY(event->scenePos().ry());
}

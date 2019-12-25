#include "mapbuilder.h"
#include <QDebug>

MapBuilder::MapBuilder(qreal x, qreal y, qreal width, qreal height, QToolBox* componentInfo)
    :x(x)
    ,y(y)
    ,width(width)
    ,height(height)
    ,componentInfo(componentInfo)
    ,id(random())
{
    setPos(x, y);
    qDebug() << "Pozvao sam se ";
}

MapBuilder::~MapBuilder(){}

QRectF MapBuilder::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

QPainterPath MapBuilder::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, width, height);
    return path;
}

void MapBuilder::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    componentInfo->setItemText(0, "Rectangle");
    painter->drawRect(0, 0, width, height);
}

void MapBuilder::pbApply()
{}

qreal MapBuilder::getHeight() const
{
    return height;
}

void MapBuilder::setHeight(const qreal &value)
{
    height = value;
}

qreal MapBuilder::getWidth() const
{
    return width;
}

void MapBuilder::setWidth(const qreal &value)
{
    width = value;
}

qreal MapBuilder::getY() const
{
    return y;
}

void MapBuilder::setY(const qreal &value)
{
    y = value;
}

qreal MapBuilder::getX() const
{
    return x;
}

void MapBuilder::setX(const qreal &value)
{
    x = value;
}

long MapBuilder::getId() const
{
    return id;
}

void MapBuilder::setId(long value)
{
    id = value;
}

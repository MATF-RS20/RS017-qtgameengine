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


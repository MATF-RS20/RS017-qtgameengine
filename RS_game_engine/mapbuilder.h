#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <QGraphicsObject>
#include <QPainter>
#include <QObject>
#include <QToolBox>

class MapBuilder : public QGraphicsObject
{
    Q_OBJECT
public:
    MapBuilder(qreal x, qreal y, qreal width, qreal height, QToolBox* componentInfo);
    ~MapBuilder();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private slots:
    virtual void pbApply();

protected:
    long id;
    qreal x;
    qreal y;
    qreal width;
    qreal height;
    QToolBox* componentInfo;
};

#endif // MAPBUILDER_H

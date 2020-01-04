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
    ~MapBuilder() override;

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    long getId() const;
    void setId(long value);

    qreal getX() const;
    void setX(const qreal &value);

    qreal getY() const;
    void setY(const qreal &value);

    qreal getWidth() const;
    void setWidth(const qreal &value);

    qreal getHeight() const;
    void setHeight(const qreal &value);

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

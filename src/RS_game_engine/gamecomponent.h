#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

#include <QGraphicsObject>
#include <QPainter>
#include <QObject>

class GameComponent : public QGraphicsObject
{
    Q_OBJECT
public:
    GameComponent(qreal x, qreal y, qreal width, qreal height);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private slots:
    virtual void pbApply();

protected:
    qreal x;
    qreal y;
    qreal width;
    qreal height;

};

#endif // GAMECOMPONENT_H

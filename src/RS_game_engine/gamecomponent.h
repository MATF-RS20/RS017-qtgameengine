#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

#include <QGraphicsObject>
#include <QPainter>
#include <QObject>
#include <QGraphicsSceneDragDropEvent>

class GameComponent : public QGraphicsObject
{
    Q_OBJECT
public:
    GameComponent(qreal x, qreal y, qreal width, qreal height);
    GameComponent(GameComponent &a);
     ~GameComponent() override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

     void gravity(bool wantGravity);

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
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    qreal x;
    qreal y;
    qreal width;
    qreal height;

};

#endif // GAMECOMPONENT_H

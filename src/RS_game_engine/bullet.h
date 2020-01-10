#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsObject>
#include <QPainter>
#include <QObject>
#include <QTimer>

class Bullet : public QGraphicsObject
{
    Q_OBJECT
public:
    Bullet(qreal x, qreal y, qreal width, qreal height, bool direction);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setTexture(QString lookPath);
    //true --> | <-- false
public slots:
    void move();

private:
    qreal speed;
    qreal direction;
    QPixmap texture;
    qreal x,y;
    qreal width, height;
    bool textureApplied;
};

#endif // BULLET_H

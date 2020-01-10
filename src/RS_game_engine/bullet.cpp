#include "bullet.h"

Bullet::Bullet(qreal x, qreal y, qreal width, qreal height, bool direction)
    :x(x)
    ,y(y)
    ,width(width)
    ,height(height)
    ,textureApplied(false)
    ,speed(5)
    ,direction(direction)
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(15);
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(textureApplied){
        painter->setPen(Qt::NoPen);
        painter->setBrush(QBrush(texture));
        texture.scaled(100,100);
        painter->drawRect(0, 0, width, height);
    }
    else{
        painter->drawRect(0, 0, width, height);
    }
}

void Bullet::setTexture(QString lookPath)
{
    texture = QPixmap(lookPath);
    textureApplied = true;
}

void Bullet::move()
{
    if(direction){
        x += speed;
        this->setPos(x, y);
        update();
    }
    else{
        x -= speed;
        this->setPos(x, y);
        update();
    }
}

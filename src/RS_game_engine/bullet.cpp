#include "bullet.h"

Bullet::Bullet(qreal x, qreal y, qreal width, qreal height, bool direction, qreal speed)
    :x(x)
    ,y(y)
    ,width(width)
    ,height(height)
    ,textureApplied(true)
    ,direction(direction)
    ,distancePassed(0)
    ,speed(speed)
    ,texture("/home/stefan/Desktop/finalRS/RS017-qtgameengine/src/RS_game_engine/icons/fireBall.png")
{
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(15);
}

Bullet::~Bullet()
{
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
//        painter->drawRect(0, 0, width, height);
        painter->drawPixmap(0, 0, width, height, texture);
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

int Bullet::type() const
{
    return 5;
}

void Bullet::move()
{
    distancePassed += speed;
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

qreal Bullet::getDistancePassed() const
{
    return distancePassed;
}

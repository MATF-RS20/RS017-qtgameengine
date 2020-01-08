#include "enemy.h"
#include <QDebug>

Enemy::Enemy(qreal x, qreal y, qreal width, qreal height, qreal range, QString look,
             QToolBox* componentInfo,QList<QLineEdit*> enemyInfo, QPushButton* enemyUpdate)
    :GameComponent(x, y, width, height)
    ,componentInfo(componentInfo)
    ,enemyInfo(enemyInfo)
    ,enemyUpdate(enemyUpdate)
    ,range(range)
    ,maxLeft(x-range)
    ,maxRight(x+range)
    ,maxUp(y - range)
    ,maxDown(y + range)
    ,lookRight(look)
    ,id(random())
    ,focused(false)
    ,upDownMovement(false)
    ,leftRightMovement(true)
    ,gravityIntensity(2)
{
    setFlags(ItemIsMovable|ItemIsFocusable);
    lookLeft = lookRight.transformed(QTransform().scale(-1,1));
    connect(enemyUpdate, SIGNAL(clicked()), this, SLOT(pbApply()));
}

void Enemy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    componentInfo->setCurrentIndex(1);
    QString id = QString::number(this->id);
    componentInfo->setItemText(1,"Enemy one " + id);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->hasFocus()) {
        this->focused = true;
        enemyInfo.at(0)->setPlaceholderText(QString::number(this->pos().rx()));
        enemyInfo.at(1)->setPlaceholderText(QString::number(this->pos().ry()));
        enemyInfo.at(2)->setPlaceholderText(QString::number(this->width));
        enemyInfo.at(3)->setPlaceholderText(QString::number(this->height));
    }
    else{
        this->focused = false;
    }
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(lookRight));
    painter->drawPixmap(0, 0, width, height, this->speed > 0 ? lookRight : lookLeft);
}

void Enemy::pbApply()
{
    QString id = QString::number(this->id);
    if(componentInfo->itemText(1) == ("Enemy one " + id) ){
        qDebug() << "USAO";
        this->x = (qreal)enemyInfo.at(0)->text().toFloat();
        this->y = (qreal)enemyInfo.at(1)->text().toFloat();
        this->setPos((qreal)enemyInfo.at(0)->text().toFloat(), (qreal)enemyInfo.at(1)->text().toFloat());
        this->width = (qreal)enemyInfo.at(2)->text().toFloat();
        this->height = (qreal)enemyInfo.at(3)->text().toFloat();
        this->range = (qreal)enemyInfo.at(4)->text().toFloat();
        if(this->speed > 0)
            this->speed = static_cast<qreal>(enemyInfo.at(5)->text().toFloat());
        else
            this->speed = static_cast<qreal>(enemyInfo.at(5)->text().toFloat()) * (-1);

        this->gravityIntensity = static_cast<qreal>(enemyInfo.at(6)->text().toFloat());
        this->maxLeft = this->x - this->range;
        this->maxRight = this->x + this->range;
        update();
    }
}

void Enemy::setSpeed(const qreal &value)
{
    speed = value;
}

void Enemy::upDownMovementEnabled(bool checked)
{
    QString id = QString::number(this->id);
    if(componentInfo->itemText(1) == ("Enemy one " + id) ){
        upDownMovement = checked;
    }
}

void Enemy::leftRightMovementEnabled(bool checked)
{
    QString id = QString::number(this->id);
    if(componentInfo->itemText(1) == ("Enemy one " + id) ){
        leftRightMovement = checked;
    }
}

qreal Enemy::getSpeed() const
{
    return speed;
}

QPixmap Enemy::getLook() const
{
    return lookRight;
}

void Enemy::setLook(const QPixmap &value)
{
    lookRight = value;
}

qreal Enemy::getRange() const
{
    return range;
}

void Enemy::setRange(const qreal &value)
{
    range = value;
}

long Enemy::getId() const
{
    return id;
}

void Enemy::setId(long value)
{
    id = value;
}

bool Enemy::getFocused() const
{
    return focused;
}

void Enemy::setFocused(bool value)
{
    focused = value;
}
int Enemy::type() const{
    return 2;
}

void Enemy::move()
{
    if(leftRightMovement){
        x += speed;
    }
    else if(upDownMovement){
        y += speed;
    }

    this->setPos(x, y);
    if(x <= maxLeft || x >= maxRight || y <= maxUp || y >= maxDown)
        speed *= (-1);
}

void Enemy::gravityApply()
{
    y += gravityIntensity;
    this->setPos(x, y);
    update();
}

void Enemy::setGravityEnabled(bool checked)
{
    QString id = QString::number(this->id);
    if(componentInfo->itemText(1) == ("Enemy one " + id) ){
        gravityEnabled = checked;
    }
}

bool Enemy::EnemyGravityEnabled()
{
    return this->gravityEnabled;
}

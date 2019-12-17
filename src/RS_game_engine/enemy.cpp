#include "enemy.h"
#include <QDebug>

Enemy::Enemy(qreal x, qreal y, qreal width, qreal height, qreal range, QString look,
             QToolBox* componentInfo,QList<QLineEdit*> enemyInfo, QPushButton* enemyUpdate)
    :GameComponent(x, y, width, height)
    ,componentInfo(componentInfo)
    ,enemyInfo(enemyInfo)
    ,enemyUpdate(enemyUpdate)
    ,range(range)
    ,look(look)
    ,id(random())
    ,focused(false)
{
    setFlags(ItemIsMovable|ItemIsFocusable);

    connect(enemyUpdate, SIGNAL(clicked()), this, SLOT(pbApply()));
}

void Enemy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
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
    painter->setBrush(QBrush(look));
    painter->drawPixmap(0, 0, width, height, look);
}

void Enemy::pbApply()
{

    QString id = QString::number(this->id);
    if(componentInfo->itemText(1) == ("Enemy one " + id) ){
        this->setPos((qreal)enemyInfo.at(0)->text().toFloat(), (qreal)enemyInfo.at(1)->text().toFloat());
        this->width = (qreal)enemyInfo.at(2)->text().toFloat();
        this->height = (qreal)enemyInfo.at(3)->text().toFloat();
        update();
    }
}

#include "rectangle.h"
#include <QDebug>
#include <QPushButton>

Rectangle::Rectangle(qreal x, qreal y, qreal width, qreal height, QToolBox* componentInfo,
                     QList<QLineEdit*> rectangleInfo, QPushButton* rectangleUpdate, QString lookPath)
    : MapBuilder(x, y, width, height, componentInfo)
    , texture(lookPath)
    , focused(false)
    ,rectangleInfo(rectangleInfo)
    ,rectangleUpdate(rectangleUpdate)
{
    setFlags(ItemIsMovable | ItemIsFocusable);
    connect(rectangleUpdate, SIGNAL(clicked()), this, SLOT(pbApply()));
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->hasFocus()) {
        this->focused = true;
        rectangleInfo.at(0)->setPlaceholderText(QString::number(this->pos().rx()));
        rectangleInfo.at(1)->setPlaceholderText(QString::number(this->pos().ry()));
        rectangleInfo.at(2)->setPlaceholderText(QString::number(this->width));
        rectangleInfo.at(3)->setPlaceholderText(QString::number(this->height));
    }
    else{
        this->focused = false;
    }
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(texture));
    texture.scaled(100,100);
    painter->drawRect(0, 0, width, height);
}

void Rectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    componentInfo->setCurrentIndex(0);
    QString id = QString::number(this->id);
    componentInfo->setItemText(0,"Rectangle " + id);
}

void Rectangle::pbApply()
{
    QString id = QString::number(this->id);
    if(componentInfo->itemText(0) == ("Rectangle " + id) ){
        this->setPos((qreal)rectangleInfo.at(0)->text().toFloat(), (qreal)rectangleInfo.at(1)->text().toFloat());
        this->width = (qreal)rectangleInfo.at(2)->text().toFloat();
        this->height = (qreal)rectangleInfo.at(3)->text().toFloat();
        update();
    }
}

int Rectangle::type() const{
    return 1;
}

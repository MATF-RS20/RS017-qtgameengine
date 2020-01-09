#include "positiveobstacle.h"

PositiveObstacle::PositiveObstacle(qreal x, qreal y, qreal width, qreal height,
                                   QToolBox* componentInfo, QList<QLineEdit*> positiveObstacleInfo, QPushButton* positiveObstacleUpdate, QString lookPath)
    :MapBuilder(x, y, width, height, componentInfo)
    ,texture(lookPath)
    ,focused(false)
    ,positiveObstacleUpdate(positiveObstacleUpdate)
    ,positiveObstacleInfo(positiveObstacleInfo)
    ,lookString(lookPath)
{
    setFlags(ItemIsMovable|ItemIsFocusable);
    connect(positiveObstacleUpdate, SIGNAL(clicked()), this, SLOT(pbApply()));

}

void PositiveObstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->hasFocus()) {
        this->focused = true;
        positiveObstacleInfo.at(0)->setPlaceholderText(QString::number(this->pos().rx()));
        positiveObstacleInfo.at(1)->setPlaceholderText(QString::number(this->pos().ry()));
        positiveObstacleInfo.at(2)->setPlaceholderText(QString::number(this->width));
        positiveObstacleInfo.at(3)->setPlaceholderText(QString::number(this->height));
    }
    else{
        this->focused = false;
    }

    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(texture));
    painter->drawPixmap(0,0, width, height, texture);
}

void PositiveObstacle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    componentInfo->setCurrentIndex(3);
    QString id = QString::number(this->id);
    componentInfo->setItemText(3,"Positive Obstacle " + id);
}

int PositiveObstacle::type() const
{
    return 3;
}

void PositiveObstacle::pbApply()
{
    QString id = QString::number(this->id);
    qDebug() << "Positive Obstacle " << id;
    if(componentInfo->itemText(3) == ("Positive Obstacle " + id) ){
        qDebug() << "PO";
        this->setPos((qreal)positiveObstacleInfo.at(0)->text().toFloat(), (qreal)positiveObstacleInfo.at(1)->text().toFloat());
        this->width = (qreal)positiveObstacleInfo.at(2)->text().toFloat();
        this->height = (qreal)positiveObstacleInfo.at(3)->text().toFloat();
        update();
    }
}

QList<QLineEdit *> PositiveObstacle::getPositiveObstacleInfo() const
{
    return positiveObstacleInfo;
}

QPushButton *PositiveObstacle::getPositiveObstacleUpdate() const
{
    return positiveObstacleUpdate;
}

QString PositiveObstacle::getLookString() const
{
    return lookString;
}

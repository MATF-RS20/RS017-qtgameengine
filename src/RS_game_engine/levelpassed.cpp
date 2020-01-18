#include "levelpassed.h"

LevelPassed::LevelPassed(qreal x, qreal y, qreal width, qreal height,
                         QToolBox* componentInfo, QList<QLineEdit*> levelPassedInfo, QPushButton* levePassedUpdate, QString lookPath)
    : MapBuilder(x, y, width, height, componentInfo)
    , texture(lookPath)
    , focused(false)
    ,levelPassedInfo(levelPassedInfo)
    ,levelPassedUpdate(levePassedUpdate)
{
    setFlags(ItemIsMovable | ItemIsFocusable);
    connect(levelPassedUpdate, SIGNAL(clicked()), this, SLOT(pbApply()));
}

void LevelPassed::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->hasFocus()) {
        this->focused = true;
        levelPassedInfo.at(0)->setPlaceholderText(QString::number(this->pos().rx()));
        levelPassedInfo.at(1)->setPlaceholderText(QString::number(this->pos().ry()));
        levelPassedInfo.at(2)->setPlaceholderText(QString::number(this->width));
        levelPassedInfo.at(3)->setPlaceholderText(QString::number(this->height));
    }
    else{
        this->focused = false;
    }
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(texture));
    texture.scaled(100,100);
    painter->drawRect(0, 0, width, height);
}

void LevelPassed::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    componentInfo->setCurrentIndex(4);
    QString id = QString::number(this->id);
    componentInfo->setItemText(4,"Level Passed " + id);
}

void LevelPassed::pbApply()
{
    QString id = QString::number(this->id);
    if(componentInfo->itemText(4) == ("Level Passed " + id) ){
        this->setPos((qreal)levelPassedInfo.at(0)->text().toFloat(), (qreal)levelPassedInfo.at(1)->text().toFloat());
        this->width = (qreal)levelPassedInfo.at(2)->text().toFloat();
        this->height = (qreal)levelPassedInfo.at(3)->text().toFloat();
        update();
    }
}

QList<QLineEdit *> LevelPassed::getLevelPassedInfo() const
{
    return levelPassedInfo;
}

int LevelPassed::type() const{
    return 6;
}


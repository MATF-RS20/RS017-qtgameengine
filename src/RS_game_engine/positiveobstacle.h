#ifndef POSITIVEOBSTACLE_H
#define POSITIVEOBSTACLE_H

#include "mapbuilder.h"
#include <QPixmap>
#include <QList>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class PositiveObstacle : public MapBuilder
{
public:
    PositiveObstacle(qreal x, qreal y, qreal width, qreal height,
                     QToolBox* componentInfo, QList<QLineEdit*> positiveObstacleInfo, QPushButton* positiveObstacleUpdate, QString lookPath);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    int type() const override;

private slots:
    void pbApply() override;

private:
    QPixmap texture;
    QList<QLineEdit*> positiveObstacleInfo;
    QLineEdit* line;
    bool focused;
    QPushButton* positiveObstacleUpdate;
};

#endif // POSITIVEOBSTACLE_H

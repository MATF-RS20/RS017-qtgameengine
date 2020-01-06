#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "mapbuilder.h"
#include <QPixmap>
#include <QList>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>

class Rectangle : public MapBuilder
{
public:
    Rectangle(qreal x, qreal y, qreal width, qreal height,
              QToolBox* componentInfo, QList<QLineEdit*> rectangleInfo, QPushButton* rectangleUpdate, QString lookPath);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    int type() const override;
private slots:
    void pbApply() override;
private:
    QPixmap texture;
    bool focused;
    QList<QLineEdit*> rectangleInfo;
    QLineEdit* line;
    QPushButton* rectangleUpdate;
};

#endif // RECTANGLE_H

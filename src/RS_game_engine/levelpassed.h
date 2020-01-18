#ifndef LEVELPASSED_H
#define LEVELPASSED_H

#include "mapbuilder.h"
#include <QPixmap>
#include <QList>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>


class LevelPassed : public MapBuilder
{
public:
    LevelPassed(qreal x, qreal y, qreal width, qreal height,
                QToolBox* componentInfo, QList<QLineEdit*> levelPassedInfo, QPushButton* levePassedUpdate, QString lookPath);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    int type() const override;
    QList<QLineEdit *> getLevelPassedInfo() const;

private slots:
    void pbApply() override;

private:
    QPixmap texture;
    bool focused;
    QList<QLineEdit*> levelPassedInfo;
    QLineEdit* line;
    QPushButton* levelPassedUpdate;
};

#endif // LEVELPASSED_H

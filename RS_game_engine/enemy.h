#ifndef ENEMY_H
#define ENEMY_H

#include "gamecomponent.h"
#include <QPixmap>
#include <QToolBox>
#include <QLineEdit>
#include <QPushButton>

class Enemy : public GameComponent
{
    Q_OBJECT
public:
    Enemy(qreal x, qreal y, qreal width, qreal height, qreal range, QString look,
          QToolBox* componentInfo,QList<QLineEdit*> enemyInfo, QPushButton* enemyUpdate);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private slots:
    void pbApply() override;

private:
    bool focused;
    long id;
    QPixmap look;
    qreal range;
    QToolBox* componentInfo;
    QList<QLineEdit*> enemyInfo;
    QPushButton* enemyUpdate;
};

#endif // ENEMY_H

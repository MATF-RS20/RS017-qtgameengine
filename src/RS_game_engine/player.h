#ifndef PLAYER_H
#define PLAYER_H

#include "gamecomponent.h"
#include <QPixmap>
#include <QToolBox>
#include <QLineEdit>
#include <QPushButton>
#include <QBitArray>
#include <QtMath>


class Player : public GameComponent
{
    Q_OBJECT
public:
    Player(qreal x, qreal y, qreal width, qreal height, QString look,
           QToolBox* componentInfo,QList<QLineEdit*> playerInfo, QPushButton* playerUpdate);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    int type() const override;
    void move(qreal delta_x, qreal delta_y);
    qreal getHeight();
    qreal getWidth();
    void setCurrentLook(bool right);
    QBitArray movementArray;
    void setMoveUpDownEnabled(bool checked);
    void setGravityEnabled(bool checked);
    void gravityApply();
    void setBoostEnabled(bool checked);
    void setBulletEnabled(bool checked);
    void setCurrentSpeed(qreal speed);
    void jumpAnimation(qreal currentJumpPosition);
    qreal getJump();
    void setPositionBeforeJump(qreal position);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    qreal getGravityIntensity() const;
    qreal getSpeed();
    qreal getBoost();
    bool getIsRight() const;

    qreal getBulletSpeed() const;

private slots:
    void pbApply() override;

private:
    QPixmap lookRight;
    QPixmap lookLeft;
    QToolBox* componentInfo;
    QList<QLineEdit*> playerInfo;
    QPushButton* playerUpdate;
    bool isRight;
    bool gravityEnabled, moveUpDownEnabled, jumpEnabled,boostEnabled, bulletEnabled;
    qreal bulletSpeed;
    qreal boost;
    qreal gravityIntensity;
    qreal speed;
    qreal jump, currentJumpPosition;

    QList<qreal> jumpArray;
    qreal positionBeforeJump;

};

#endif // PLAYER_H

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
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    bool getFocused() const;
    void setFocused(bool value);

    long getId() const;
    void setId(long value);
    int type() const override;
    qreal getRange() const;
    void setRange(const qreal &value);

    QPixmap getLook() const;
    void setLook(const QPixmap &value);

    void move();

    qreal getSpeed() const;

    void setSpeed(const qreal &value);
    void upDownMovementEnabled(bool checked);
    void leftRightMovementEnabled(bool checked);
    void gravityApply();
    void setGravityEnabled(bool checked);
    bool EnemyGravityEnabled();

    QString getLookString() const;

    QPushButton *getEnemyUpdate() const;

    QList<QLineEdit *> getEnemyInfo() const;

private slots:
    void pbApply() override;

private:
    bool focused;
    long id;
    QPixmap look;
    QPixmap lookRight;
    QPixmap lookLeft;
    qreal range;
    qreal maxLeft;
    qreal maxRight;
    qreal speed = 1;
    QToolBox* componentInfo;
    QList<QLineEdit*> enemyInfo;
    QPushButton* enemyUpdate;
    bool upDownMovement;
    bool leftRightMovement;
    qreal maxUp, maxDown;
    qreal gravityIntensity;
    bool gravityEnabled;
    QString lookString;
};

#endif // ENEMY_H

#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H


#include "player.h"
#include "enemy.h"
#include "positiveobstacle.h"
#include "rectangle.h"
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>
#include <QScopedPointer>
#include <QTimer>
#include <QKeyEvent>
#include <QList>
#include <QDebug>
#include <QBitArray>
#include <QScrollBar>

class GameBuilder : public QGraphicsScene
{
    Q_OBJECT

public:
    GameBuilder(QGraphicsView* parent);
    GameBuilder(GameBuilder* parent);
    ~GameBuilder() override;

    GameBuilder(const GameBuilder&) = delete;
    GameBuilder& operator=(const GameBuilder&) = delete;

    void addRectangle(qreal x, qreal y, qreal width, qreal height, QToolBox* componentInfo, QList<QLineEdit*> rectangleInfo, QPushButton* rectangleUpdate, QString lookPath);
    void addPositiveObstacle(qreal x, qreal y, qreal width, qreal height, QToolBox* componentInfo, QList<QLineEdit*> positiveObstacleInfo, QPushButton* positiveObstacleUpdate, QString lookPath);
    void addEnemy(qreal x, qreal y, qreal width, qreal height, qreal range, QString look, QToolBox* componentInfo,QList<QLineEdit*> enemyInfo, QPushButton* enemyUpdate);
    void addPlayer(qreal x, qreal y, qreal width, qreal height, QString look, QToolBox* componentInfo,QList<QLineEdit*> playerInfo, QPushButton* playerUpdate);
    bool playerCanMove(qreal delta_x, qreal delta_y);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    QGraphicsView *getParent() const;
    void setMoveUpDownPlayer(bool checked);
    void setGravityPlayer(bool checked);
    void setCollisionEnabled(bool checked);
    void setBoostEnabled(bool checked);
    void setJumpEnabled(bool checked);

    Player *getPlayer() const;
    void setPlayer(Player *value);

    QList<Enemy *> getLstEnemy() const;
    void setLstEnemy(const QList<Enemy *> &value);

    QTimer *getGameBuilderTimer() const;

    //privremeno public dok ne napravimo u gamestart
    QGraphicsView* parent;
    bool playerGravityApply;
    bool jumpPlayer;
    bool collisionEnabled;
    bool jumpEnabled;
    qreal jumpAmout;

    bool getCollisionEnabled() const;

    bool getPlayerGravityApply() const;

    qreal getJumpAmout() const;

    bool getJumpPlayer() const;

    bool getJumpEnabled() const;

private slots:
    void update();

private:
    QTimer* gameBuilderTimer;
    Player* player;
    Rectangle* rectangle;
    QList<Rectangle*> lstRectangle;
    Enemy* enemy;
    QList<Enemy*> lstEnemy;
    QWidget* main;
    QToolBox* componentInfo;

    PositiveObstacle* positiveObstacle;
    QList<PositiveObstacle*> lstPositiveObstacle;
};

#endif // GAMEBUILDER_H

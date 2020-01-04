#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H

#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>
#include <QScopedPointer>
#include <QTimer>
#include <QKeyEvent>
#include <QList>
#include "player.h"
#include "enemy.h"
#include "rectangle.h"
#include <QDebug>
#include <QBitArray>

class GameBuilder : public QGraphicsScene
{
    Q_OBJECT

public:
    GameBuilder(QGraphicsView* parent);

    ~GameBuilder() override;

    GameBuilder(const GameBuilder&) = delete;
    GameBuilder& operator=(const GameBuilder&) = delete;

    void addRectangle(qreal x, qreal y, qreal width, qreal height, QToolBox* componentInfo, QList<QLineEdit*> rectangleInfo, QPushButton* rectangleUpdate, QString lookPath);
    void addEnemy(qreal x, qreal y, qreal width, qreal height, qreal range, QString look, QToolBox* componentInfo,QList<QLineEdit*> enemyInfo, QPushButton* enemyUpdate);
    void addPlayer(qreal x, qreal y, qreal width, qreal height, QString look, QToolBox* componentInfo,QList<QLineEdit*> playerInfo, QPushButton* playerUpdate);
    bool playerCanMove(qreal delta_x, qreal delta_y);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    QGraphicsView *getParent() const;
    void setMoveUpDownPlayer(bool checked);
    void setGravityPlayer(bool checked);
    void setCollisionEnabled(bool checked);

    Player *getPlayer() const;
    void setPlayer(Player *value);

    QList<Enemy *> getLstEnemy() const;
    void setLstEnemy(const QList<Enemy *> &value);

private slots:
    void update();

private:

    QGraphicsView* parent;
    QScopedPointer<QTimer> gameBuilderTimer;
    Player* player;
    Rectangle* rectangle;
    QList<Rectangle*> lstRectangle;
    Enemy* enemy;
    QList<Enemy*> lstEnemy;
    QWidget* main;
    QToolBox* componentInfo;
    bool collisionEnabled;
};

#endif // GAMEBUILDER_H

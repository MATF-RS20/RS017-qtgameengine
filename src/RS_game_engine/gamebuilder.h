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

    ~GameBuilder();

    GameBuilder(const GameBuilder&) = delete;
    GameBuilder& operator=(const GameBuilder&) = delete;

    void addRectangle(qreal x, qreal y, qreal width, qreal height, QToolBox* componentInfo, QList<QLineEdit*> rectangleInfo, QPushButton* rectangleUpdate);
    void addEnemy(qreal x, qreal y, qreal width, qreal height, qreal range, QString look, QToolBox* componentInfo,QList<QLineEdit*> enemyInfo, QPushButton* enemyUpdate);
    void addPlayer(qreal x, qreal y, qreal width, qreal height, QString look, QToolBox* componentInfo,QList<QLineEdit*> playerInfo, QPushButton* playerUpdate);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    QGraphicsView *getParent() const;

private slots:
    void update();

private:
    bool playerCanMoveUp(qreal delta_x, qreal delta_y);
    bool playerCanMoveDown(qreal delta_x, qreal delta_y);
    bool playerCanMoveLeft(qreal delta_x, qreal delta_y);
    bool playerCanMoveRight(qreal delta_x, qreal delta_y);
    QGraphicsView* parent;
    QScopedPointer<QTimer> gameBuilderTimer;
    Player* player;
    Rectangle* rectangle;
    QList<Rectangle*> lstRectangle;
    Enemy* enemy;
    QList<Enemy*> lstEnemy;
    QWidget* main;
    QToolBox* componentInfo;


};

#endif // GAMEBUILDER_H

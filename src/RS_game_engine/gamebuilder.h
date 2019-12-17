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
    void keyPressEvent(QKeyEvent *event) override;

private:
    QGraphicsView* parent;
    QScopedPointer<QTimer> gameBuilderTimer;
    QScopedPointer<Player> player;
    Rectangle* rectangle;
    QList<Rectangle*> lstRectangle;
    Enemy* enemy;
    QList<Enemy*> lstEnemy;
    QWidget* main;
    QToolBox* componentInfo;

};

#endif // GAMEBUILDER_H

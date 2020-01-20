#ifndef GAMESTART_H
#define GAMESTART_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDebug>
#include <QFlags>
#include "mainwindow.h"
#include "player.h"
#include "rectangle.h"
#include "enemy.h"
#include "bullet.h"

namespace Ui {
class GameStart;
}

class GameStart : public QWidget
{
    Q_OBJECT

public:
    explicit GameStart(/*QWidget *parent = nullptr,*/ bool collision = true,
                       bool gravity = true, qreal jump=0, bool jumpPlayer=true, bool jumpEnabled=true);
    ~GameStart();
    void start();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    QGraphicsView *getScene() const;
    void setScene(QGraphicsView *value);
    void closeEvent(QCloseEvent *event) override;
    QString getFName() const;
    void setFName(const QString &value);
    void makePoint();
    void losePoint();
    bool playerCanMoveStart(qreal delta_x, qreal delta_y);
    bool enemyCanMove(Enemy *enemy, qreal delta_x, qreal delta_y);

    QScopedPointer<QTimer> getTimer() const;

    GameBuilder *getGameON() const;
    void setGameON(GameBuilder *value);

    int getPoints() const;
    void setPoints(int value);

    QGraphicsTextItem *getTextPoints() const;
    void setTextPoints(QGraphicsTextItem *value);

private slots:
    void update();
private:
    void resizeEvent(QResizeEvent* event);
    int Points;
    QGraphicsTextItem* textPoints;
    QGraphicsTextItem* gameOver;
    QGraphicsTextItem* gameWin;
    QGraphicsTextItem* playerHealt;
    Ui::GameStart *ui;
    QGraphicsView* scene;
    GameBuilder* gameON;
    QString fName;
    QScopedPointer<QTimer> timer;
    Player *player;
    QList<Rectangle*> lstRectangle;
    QList<Enemy*> lstEnemy;
    QList<Enemy*> lstEnemyKilled;
    bool collisionEnabled;
    bool playerGravityApply;
    qreal playerSpeed;
    qreal jumpAmout;
    bool jumpPlayer;
    bool jumpEnabled;
    bool jumpAllowed;

    QList<Bullet*> lstPlayerBullets;
};

#endif // GAMESTART_H

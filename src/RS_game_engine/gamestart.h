#ifndef GAMESTART_H
#define GAMESTART_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDebug>
#include <QFlags>
#include "mainwindow.h"
#include "player.h"

namespace Ui {
class GameStart;
}

class GameStart : public QWidget
{
    Q_OBJECT

public:
    explicit GameStart(QWidget *parent = nullptr);
    ~GameStart();
    void start();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    QGraphicsView *getScene() const;
    void setScene(QGraphicsView *value);
    void closeEvent(QCloseEvent *event);
    QString getFName() const;
    void setFName(const QString &value);
    void makePoint();
    void losePoint();

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
    Ui::GameStart *ui;
    QGraphicsView* scene;
    GameBuilder* gameON;
    QString fName;
    QScopedPointer<QTimer> timer;
};

#endif // GAMESTART_H

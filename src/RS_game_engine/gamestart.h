#ifndef GAMESTART_H
#define GAMESTART_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDebug>
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

    QScopedPointer<QTimer> getTimer() const;

    GameBuilder *getGameON() const;
    void setGameON(GameBuilder *value);

private slots:
    void update();
private:
    void resizeEvent(QResizeEvent* event);
    Ui::GameStart *ui;
    QGraphicsView* scene;
    GameBuilder* gameON;
    QString fName;
    QScopedPointer<QTimer> timer;
};

#endif // GAMESTART_H

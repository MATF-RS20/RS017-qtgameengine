#ifndef GAMESTART_H
#define GAMESTART_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDebug>
#include "mainwindow.h"
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
    QGraphicsView *getScene() const;
    void setScene(QGraphicsView *value);
    void closeEvent(QCloseEvent *event);
    QString getFName() const;
    void setFName(const QString &value);

private:
    Ui::GameStart *ui;
    QGraphicsView* scene;
    QString fName;
};

#endif // GAMESTART_H

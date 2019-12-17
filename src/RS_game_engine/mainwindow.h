#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QTreeWidget>
#include "gamebuilder.h"
#include "componentinfodialog.h"
#include "gameobjectinfo.h"
#include "enemydialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void loadGame();
    void saveGame();
    void closeApp();
    void addSignalsAndSlots();


private slots:
    void addRectangle();
    void loadDefaultBackground();
    void addEnemyOne();


private:
    Ui::MainWindow *ui;
    QScopedPointer<GameBuilder> gameBuilder;
    void resizeEvent(QResizeEvent* event);

};
#endif // MAINWINDOW_H

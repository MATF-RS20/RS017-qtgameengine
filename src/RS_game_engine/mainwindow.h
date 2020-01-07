#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QTreeWidget>
#include "gamebuilder.h"
#include "componentinfodialog.h"
#include "gameobjectinfo.h"
#include "enemydialog.h"
#include "playerdialog.h"
#include <QWheelEvent>
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>
#include <QFileDialog>
#include <QRectF>
#include <QScrollBar>
#include "sceneloader.h"
#include "gamestart.h"
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

    GameBuilder* getGameBuilder() const;

private slots:
    void addRectangle();
    void loadDefaultBackground();
    void addEnemyOne();
    void addPlayer();
    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionClear_triggered();

    void on_startBt_clicked();
    void on_cbCollision_clicked(bool checked);

    void on_cbGravity_clicked(bool checked);

    void on_cbMoveUpDown_clicked(bool checked);

    void on_cbJump_clicked(bool checked);

    void on_cbSpeedBoost_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    GameBuilder* gameBuilder;
    void resizeEvent(QResizeEvent* event);
};
#endif // MAINWINDOW_H

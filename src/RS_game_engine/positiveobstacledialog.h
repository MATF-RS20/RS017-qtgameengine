#ifndef POSITIVEOBSTACLEDIALOG_H
#define POSITIVEOBSTACLEDIALOG_H

#include <QDialog>

namespace Ui {
class PositiveObstacleDialog;
}

class PositiveObstacleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PositiveObstacleDialog(QWidget *parent = nullptr);
    ~PositiveObstacleDialog();

    qreal x(){return this->x_coord;}
    qreal y(){return this->y_coord;}
    qreal width(){return this->m_width;}
    qreal height(){return this->m_height;}
    bool accepted(){return this->m_accepted;}


private slots:
    void on_dApplyBtn_clicked();

    void on_dCancelBtn_clicked();

private:
    Ui::PositiveObstacleDialog *ui;
    bool m_accepted;
    qreal x_coord;
    qreal y_coord;
    qreal m_width;
    qreal m_height;
};

#endif // POSITIVEOBSTACLEDIALOG_H

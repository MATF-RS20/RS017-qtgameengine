#ifndef ENEMYDIALOG_H
#define ENEMYDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class EnemyDialog;
}

class EnemyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EnemyDialog(QWidget *parent = nullptr);
    ~EnemyDialog();
    qreal x(){return this->x_coord;}
    qreal y(){return this->y_coord;}
    qreal width(){return this->m_width;}
    qreal height(){return this->m_height;}
    qreal range(){return this->m_range;}
    bool accepted(){return this->m_accepted;}

private slots:
    void on_epbApply_clicked();

    void on_epbCancel_clicked();

private:
    Ui::EnemyDialog *ui;
    bool m_accepted;
    qreal x_coord;
    qreal y_coord;
    qreal m_width;
    qreal m_height;
    qreal m_range;
};

#endif // ENEMYDIALOG_H

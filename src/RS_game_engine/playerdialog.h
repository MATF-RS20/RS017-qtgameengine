#ifndef PLAYERDIALOG_H
#define PLAYERDIALOG_H

#include <QDialog>

namespace Ui {
class PlayerDialog;
}

class PlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerDialog(QWidget *parent = nullptr);
    ~PlayerDialog();
    qreal x(){return this->x_coord;}
    qreal y(){return this->y_coord;}
    qreal width(){return this->m_width;}
    qreal height(){return this->m_height;}
    bool accepted(){return this->m_accepted;}

private slots:
    void on_pApplyBtn_clicked();

    void on_pCancelBtn_clicked();

private:
    Ui::PlayerDialog *ui;
    bool m_accepted;
    qreal x_coord;
    qreal y_coord;
    qreal m_width;
    qreal m_height;
};

#endif // PLAYERDIALOG_H

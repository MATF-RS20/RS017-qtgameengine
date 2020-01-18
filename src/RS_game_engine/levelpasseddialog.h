    #ifndef LEVELPASSEDDIALOG_H
#define LEVELPASSEDDIALOG_H

#include <QDialog>

namespace Ui {
class LevelPassedDialog;
}

class LevelPassedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LevelPassedDialog(QWidget *parent = nullptr);
    ~LevelPassedDialog();

    qreal x(){return this->x_coord;}
    qreal y(){return this->y_coord;}
    qreal width(){return this->m_width;}
    qreal height(){return this->m_height;}
    bool accepted(){return this->m_accepted;}


private slots:
    void on_dApplyBtn_clicked();

    void on_dCancelBtn_clicked();

private:
    Ui::LevelPassedDialog *ui;
    bool m_accepted;
    qreal x_coord;
    qreal y_coord;
    qreal m_width;
    qreal m_height;

};

#endif // LEVELPASSEDDIALOG_H

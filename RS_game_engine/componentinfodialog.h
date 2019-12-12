#ifndef COMPONENTINFODIALOG_H
#define COMPONENTINFODIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class ComponentInfoDialog;
}

class ComponentInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComponentInfoDialog(QWidget *parent = nullptr);
    ~ComponentInfoDialog();

    qreal x(){return this->x_coord;}
    qreal y(){return this->y_coord;}
    qreal width(){return this->m_width;}
    qreal height(){return this->m_height;}
    bool accepted(){return this->m_accepted;}

private slots:
    void on_dApplyBtn_clicked();

    void on_dCancelBtn_clicked();

private:
    Ui::ComponentInfoDialog *ui;
    bool m_accepted;
    qreal x_coord;
    qreal y_coord;
    qreal m_width;
    qreal m_height;
};

#endif // COMPONENTINFODIALOG_H

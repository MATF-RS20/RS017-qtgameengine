#include "playerdialog.h"
#include "ui_playerdialog.h"

PlayerDialog::PlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerDialog)
{
    ui->setupUi(this);
}

PlayerDialog::~PlayerDialog()
{
    delete ui;
}

void PlayerDialog::on_pApplyBtn_clicked()
{
    this->x_coord = (qreal)ui->dpX->text().toFloat();
    this->y_coord = (qreal)ui->dpY->text().toFloat();
    this->m_width = (qreal)ui->dpWidth->text().toFloat();
    this->m_height = (qreal)ui->dpHeight->text().toFloat();
    this->m_accepted = true;
    accept();
}

void PlayerDialog::on_pCancelBtn_clicked()
{
    this->m_accepted = false;
    reject();
}

#include "positiveobstacledialog.h"
#include "ui_positiveobstacledialog.h"

PositiveObstacleDialog::PositiveObstacleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PositiveObstacleDialog)
{
    ui->setupUi(this);
    this->setModal(true);
}

PositiveObstacleDialog::~PositiveObstacleDialog()
{
    delete ui;
}

void PositiveObstacleDialog::on_dApplyBtn_clicked()
{
    this->x_coord = (qreal)ui->dPOX->text().toFloat();
    this->y_coord = (qreal)ui->dPOY->text().toFloat();
    this->m_width = (qreal)ui->dPOWidth->text().toFloat();
    this->m_height = (qreal)ui->dPOHeight->text().toFloat();
    this->m_accepted = true;
    accept();
}

void PositiveObstacleDialog::on_dCancelBtn_clicked()
{
    this->m_accepted = false;
    reject();
}

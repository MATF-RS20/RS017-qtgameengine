#include "enemydialog.h"
#include "ui_enemydialog.h"

EnemyDialog::EnemyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnemyDialog)
{
    ui->setupUi(this);
    this->setModal(true);
}

EnemyDialog::~EnemyDialog()
{
    delete ui;
}

void EnemyDialog::on_epbApply_clicked()
{
    this->x_coord = (qreal)ui->eX->text().toFloat();
    this->y_coord = (qreal)ui->eY->text().toFloat();
    this->m_width = (qreal)ui->eWidth->text().toFloat();
    this->m_height = (qreal)ui->eHeight->text().toFloat();
    this->m_height = (qreal)ui->eRange->text().toFloat();
    this->m_accepted = true;
    accept();
}

void EnemyDialog::on_epbCancel_clicked()
{
    this->m_accepted = false;
    reject();
}

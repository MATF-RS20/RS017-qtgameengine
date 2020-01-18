#include "levelpasseddialog.h"
#include "ui_levelpasseddialog.h"

LevelPassedDialog::LevelPassedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LevelPassedDialog)
{
    ui->setupUi(this);
    this->setModal(true);
}

LevelPassedDialog::~LevelPassedDialog()
{
    delete ui;
}

void LevelPassedDialog::on_dApplyBtn_clicked()
{
    this->x_coord = (qreal)ui->dLPX->text().toFloat();
    this->y_coord = (qreal)ui->dLPY->text().toFloat();
    this->m_width = (qreal)ui->dLPWidth->text().toFloat();
    this->m_height = (qreal)ui->dLPHeight->text().toFloat();
    this->m_accepted = true;
    accept();
}

void LevelPassedDialog::on_dCancelBtn_clicked()
{
    this->m_accepted = false;
    reject();
}


#include "componentinfodialog.h"
#include "ui_componentinfodialog.h"

ComponentInfoDialog::ComponentInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComponentInfoDialog)
{
    ui->setupUi(this);
    this->setModal(true);
}

ComponentInfoDialog::~ComponentInfoDialog()
{
    delete ui;
}

void ComponentInfoDialog::on_dApplyBtn_clicked()
{
    this->x_coord = (qreal)ui->dX->text().toFloat();
    this->y_coord = (qreal)ui->dY->text().toFloat();
    this->m_width = (qreal)ui->dWidth->text().toFloat();
    this->m_height = (qreal)ui->dHeight->text().toFloat();
    this->m_accepted = true;
    accept();
}

void ComponentInfoDialog::on_dCancelBtn_clicked()
{
    this->m_accepted = false;
    reject();
}

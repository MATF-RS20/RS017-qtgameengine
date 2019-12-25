#include "gameon.h"

GameOn::GameOn(QGraphicsScene* parent):
    scene(parent),
    ui(new Ui::GameOn)
{
    ui->setupUi(this);
}
GameOn::~GameOn(){
    delete ui;
}

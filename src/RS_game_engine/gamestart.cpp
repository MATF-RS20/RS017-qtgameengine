#include "gamestart.h"
#include "ui_gamestart.h"

GameStart::GameStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameStart)
{
    ui->setupUi(this);

}
GameStart::~GameStart()
{
    delete ui;
}

QGraphicsView *GameStart::getScene() const
{
    return scene;
}

void GameStart::setScene(QGraphicsView *value)
{
    scene = value;
}
void GameStart::start(){
  this->setFixedSize(1600,1000);
  QRectF exactRect(0, 0, 1600, 1000);
  float scaleX;
  scaleX = 1600/554;
  float scaleY;
  scaleY = 1000/600;
  ui->graphicsView->setSceneRect(exactRect);
  QGraphicsScene* new_scene= new QGraphicsScene(ui->graphicsView);
  for(QGraphicsItem* item:scene->scene()->items())
  {
//      qreal oldX;
//      qreal oldY;
//      if(GameComponent* v = qgraphicsitem_cast<GameComponent*>(item)){
//          oldX = v->getX();
//          oldY = v->getY();
//          v->setY(oldY/scaleY);
//          v->setPos(oldX,oldY/scaleY);

//      }
//      if(MapBuilder* r = qgraphicsitem_cast<MapBuilder*>(item)){
//          oldX = r->getX();
//          oldY = r->getY();
//          r->setX(oldX);
//          r->setY(oldY*scaleY);
//          r->setPos(r->getX(),r->getY());
//          qDebug() << r->pos();

//      }
      new_scene->addItem(item);
  }
  QPixmap bkgnd;
  bkgnd.load(getFName());
  bkgnd = bkgnd.scaled(QSize(1600,1000));
  QPalette palette;
  palette.setBrush(QPalette::Base, bkgnd);
   ui->graphicsView->setScene(&(*new_scene));
   ui->graphicsView->setPalette(palette);
   ui->graphicsView->horizontalScrollBar()->hide();
   ui->graphicsView->verticalScrollBar()->hide();
}
void GameStart::closeEvent(QCloseEvent *event)
{
    event->accept();
}

QString GameStart::getFName() const
{
    return fName;
}

void GameStart::setFName(const QString &value)
{
    fName = value;
}

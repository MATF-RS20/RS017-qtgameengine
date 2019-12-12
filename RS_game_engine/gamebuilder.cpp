#include "gamebuilder.h"

GameBuilder::GameBuilder(QGraphicsView* parent)
    :parent(parent)
    ,player(new Player(60,80))
    ,gameBuilderTimer(new QTimer())
{
    addItem(&(*player));

    setFocus();
}

GameBuilder::~GameBuilder()
{
}

void GameBuilder::addRectangle(qreal x, qreal y, qreal width, qreal height, QToolBox* componentInfo, QList<QLineEdit*> rectangleInfo, QPushButton* rectangleUpdate)
{
    rectangle = new Rectangle(x, y, width, height, componentInfo, rectangleInfo, rectangleUpdate);
    addItem(rectangle);
    lstRectangle.append(rectangle);
}

void GameBuilder::keyPressEvent(QKeyEvent *event)
{

    foreach(QGraphicsItem* item, items()){

        if(item->hasFocus() && event->key() == Qt::Key_Delete){
            qDebug() << "removing";
            removeItem(item);
            break;
        }

        if(item->hasFocus()){
            qDebug() << "item " << item->pos() << " has focus";
            componentInfo->setItemText(0,"Rectangle");
            break;
        }
    }
}

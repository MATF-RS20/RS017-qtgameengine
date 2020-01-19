#include "player.h"
#include <QDebug>

Player::Player(qreal x, qreal y, qreal width, qreal height, QString look,
               QToolBox* componentInfo,QList<QLineEdit*> playerInfo, QPushButton* playerUpdate)
    : GameComponent(x, y, width, height)
    ,lookRight(look)
    ,componentInfo(componentInfo)
    ,playerInfo(playerInfo)
    ,playerUpdate(playerUpdate)
    ,movementArray(5)
    ,jumpEnabled(true)
    ,gravityEnabled(true)
    ,moveUpDownEnabled(true)
    ,boost(10)
    ,boostEnabled(true)
    ,speed(4)
    ,gravityIntensity(1)
    ,jump(100)
    ,bulletEnabled(true)
    ,bulletSpeed(10)
    ,healthPoints(1000)
    ,bulletPower(10)
//    ,currentJumpPosition(0)
{
    for(qreal i = 0; i < M_PI_2 ;i+=0.07){
        jumpArray.append(sin(i)*jump);
    }
    setFlags(ItemIsMovable|ItemIsFocusable);
    lookLeft = lookRight.transformed(QTransform().scale(-1,1));
    connect(playerUpdate, SIGNAL(clicked()), this, SLOT(pbApply()));
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    playerInfo.at(0)->setPlaceholderText(QString::number(this->pos().rx()));
    playerInfo.at(1)->setPlaceholderText(QString::number(this->pos().ry()));
    painter->drawPixmap(0, 0, width, height, this->isRight ? lookRight : lookLeft);
}


void Player::move(qreal delta_x, qreal delta_y)
{
    x += delta_x;
    if(moveUpDownEnabled)
        y+=delta_y;


    this->setPos(x, y);
    update();
}

void Player::jumpAnimation(qreal currentJumpPosition)
{
    if(currentJumpPosition < 23){
        y = positionBeforeJump - jumpArray.at(currentJumpPosition);
        currentJumpPosition++;
    }
    else{
        currentJumpPosition = 0;
    }

    this->setPos(x, y);
    update();
}

qreal Player::getJump()
{
    return this->jump;
}

void Player::setPositionBeforeJump(qreal position)
{
    positionBeforeJump = position;
}

void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    componentInfo->setCurrentIndex(2);
}

void Player::setMoveUpDownEnabled(bool checked)
{
    this->moveUpDownEnabled = checked;
}

void Player::setGravityEnabled(bool checked)
{
        this->gravityEnabled = checked;
}

void Player::gravityApply()
{
    y += gravityIntensity;
    this->setPos(x, y);
    update();
}

void Player::setBoostEnabled(bool checked)
{
    this->boostEnabled = checked;
}

void Player::setBulletEnabled(bool checked)
{
    this->bulletEnabled = checked;
}

void Player::setCurrentSpeed(qreal speed)
{
    this->speed = speed;
}


qreal Player::getHeight()
{
    return this->height;
}

qreal Player::getWidth()
{
    return this->width;
}

void Player::setCurrentLook(bool right)
{
    this->isRight = right;
}

void Player::pbApply()
{
    this->x = (qreal)playerInfo.at(0)->text().toFloat();
    this->y = (qreal)playerInfo.at(1)->text().toFloat();
    this->setPos((qreal)playerInfo.at(0)->text().toFloat(), (qreal)playerInfo.at(1)->text().toFloat());
    this->width = (qreal)playerInfo.at(2)->text().toFloat();
    this->height = (qreal)playerInfo.at(3)->text().toFloat();
    this->jump = (qreal)playerInfo.at(4)->text().toFloat();
    jumpArray.clear();
    for(qreal i = 0; i < M_PI_2 ;i+=0.07){
        jumpArray.append(sin(i)*jump);
    }
    if(bulletEnabled){

    }
    this->boost = (qreal)playerInfo.at(5)->text().toFloat();
    this->speed = (qreal)playerInfo.at(6)->text().toFloat();
    this->gravityIntensity = (qreal)playerInfo.at(7)->text().toFloat();
    this->bulletSpeed = (qreal)playerInfo.at(8)->text().toFloat();
    this->healthPoints = (qreal)playerInfo.at(9)->text().toFloat();
    this->bulletPower = (qreal)playerInfo.at(10)->text().toFloat();
    update();
}

QString Player::getPlayersBulletLook() const
{
    return playersBulletLook;
}

void Player::setPlayersBulletLook(const QString &value)
{
    playersBulletLook = value;
}

qreal Player::getBulletPower() const
{
    return bulletPower;
}

qreal Player::getHealthPoints() const
{
    return healthPoints;
}

void Player::setHealthPoints(const qreal &value)
{
    healthPoints = value;
}

bool Player::getBulletEnabled() const
{
    return bulletEnabled;
}

qreal Player::getBulletSpeed() const
{
    return bulletSpeed;
}

bool Player::getIsRight() const
{
    return isRight;
}

qreal Player::getGravityIntensity() const
{
    return gravityIntensity;
}

qreal Player::getSpeed()
{
    return this->speed;
}

qreal Player::getBoost()
{
    return this->boost;
}
int Player::type() const{
    return 4;
}

//
// Created by nikang on 1/30/17.
//

#include "Player.h"
#include "Bullet.h"
#include "game.h"
#include "EnemyObject.h"
#include "Wall.h"
#include <QDebug>
#include <QGraphicsScene>
#include <typeinfo>

int Player::height = 50;
int Player::width;

Player::Player(FuelIndicator* fuel , Game* game, double vX, double aX)
    :Object(Physics(vX,  aX), Physics()), sound(":/sounds/fire.wav")
{
    this->game = game;
    this->fuel = fuel;
    QPixmap p(":/images/player.png");
    p = p.scaledToHeight(height);
    width = p.width();
    setPixmap(p);

    this->setZValue(20);

    direction = 0;
    upKeyPushed = false;
    downKeyPushed = false;
    rightKeyPushed = false;
    leftKeyPushed = false;
    hasBullet = false;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    if(event->key() == Qt::Key_Escape)
        game->pause();
    if(event->key() == Qt::Key_Space && !hasBullet)
    {
        sound.play();
        Bullet * bullet = new Bullet(game, this, -400);
        bullet->setPos(x() + this->pixmap().width() / 2 - bullet->pixmap().width() / 2 , y() - bullet->pixmap().height() / 2);
        scene()->addItem(bullet);
        hasBullet = true;
//        qDebug() << "bullet is created!";
    }
    if(event->key() == Qt::Key_Right)
    {
        rightKeyPushed = true;
        if(direction != 1)
            this->setPixmap(QPixmap(":/images/rightRotatedPlayer").scaledToHeight(height));
        direction = 1;
    }
    if(event->key() == Qt::Key_Left)
    {
        leftKeyPushed = true;
        if(direction != -1)
            this->setPixmap(QPixmap(":/images/leftRotatedPlayer").scaledToHeight(height));
        direction = -1;
    }
    if(event->key() == Qt::Key_Up)
        upKeyPushed = true;
    if(event->key() == Qt::Key_Down)
        downKeyPushed = true;
}
void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    if(event->key() == Qt::Key_Right)
    {
        rightKeyPushed = false;
        if(!leftKeyPushed)
        {
            setPixmap(QPixmap(":/images/player.png").scaledToHeight(height));
            direction = 0;
        }
        else
        {
            this->setPixmap(QPixmap(":/images/leftRotatedPlayer").scaledToHeight(height));
            direction = -1;
        }
    }
    if(event->key() == Qt::Key_Left)
    {
        leftKeyPushed = false;
        if(!rightKeyPushed)
        {
            setPixmap(QPixmap(":/images/player.png").scaledToHeight(height));
            direction = 0;
        }
        else
        {
            this->setPixmap(QPixmap(":/images/rightRotatedPlayer").scaledToHeight(height));
            direction = 1;
        }
    }
    //if(!rightKeyPushed && !leftKeyPushed)
    if(event->key() == Qt::Key_Up)
        upKeyPushed = false;
    if(event->key() == Qt::Key_Down)
        downKeyPushed = false;
}

void Player::explode()
{
    scene()->removeItem(this);
    delete this;
}

void Player::setHasBullet(bool value)
{
    hasBullet = value;
}


int Player::getHeight()
{
    return height;
}

void Player::setHeight(int value)
{
    height = value;
}

int Player::getWidth()
{
    return width;
}

void Player::setWidth(int value)
{
    width = value;
}
void Player::advance(int phase)
{
    if(this->fuel->is_empty())
    {
        qDebug() << "player fuel is empty";
        this->explode();
        this->game->pause();
    }
    if(upKeyPushed)
    {
        MovingObject::screenPhysics().accelerate(1);
    }

    if(downKeyPushed)
    {
        MovingObject::screenPhysics().accelerate(-1);
    }
    if(!upKeyPushed && !downKeyPushed)
    {
        if(MovingObject::screenPhysics().getAccelerattionFrames() > 0)
            MovingObject::screenPhysics().accelerate(-1);
        else if(MovingObject::screenPhysics().getAccelerattionFrames() < 0)
            MovingObject::screenPhysics().accelerate(+1);
    }
    setPos(mapToParent(this->xPhys.movement() * direction, 0));


    game->offFuel();
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
    {
        if(((Object*)colliding_items[i])->isEnemy())
        {
            qDebug() << "player explode";
            this->explode();
            this->game->pause();
            ((Object*)colliding_items[i])->explode();
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Wall))
        {
            this->explode();
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(DepotFuel))
            game->onFuel();
    }
}

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
extern Game * game;
Player::Player(double vX, double aX)
    :Object(Physics(vX,  aX), Physics())
{

    QPixmap p(":/images/player.png");
    if(p.isNull())
        qDebug() << "why";
    setPixmap(QPixmap(":/images/player.png").scaledToHeight(80));
    direction = 0;
    upKeyPushed = false;
    downKeyPushed = false;
}
void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet(-200);
        bullet->setPos(x() + this->pixmap().width() / 2 - bullet->pixmap().width() / 2 , y() - bullet->pixmap().height() / 2);
        scene()->addItem(bullet);
//        qDebug() << "bullet is created!";
    }

    if(event->key() == Qt::Key_Right)
    {
        direction = 1;
    }
    else if(event->key() == Qt::Key_Left)
    {
        direction = -1;
    }

    if(event->key() == Qt::Key_Up)
        upKeyPushed = true;
    else if(event->key() == Qt::Key_Down)
        downKeyPushed = true;
}
void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Right || event->key() == Qt::Key_Left)
    {
        direction = 0;
    }
    if(event->key() == Qt::Key_Up)
        upKeyPushed = false;
    if(event->key() == Qt::Key_Down)
        downKeyPushed = false;
}

void Player::explode()
{

}

int Player::getHeightScaled() const
{
    return playerScaledOfImageHeight;
}
int Player::getWidthScaled() const
{
    return playerScaledOfImageWidth;
}


void Player::advance(int phase)
{
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

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
    {
        if(((Object*)colliding_items[i])->isEnemy())
        {
            qDebug() << "player explode";
            this->explode();
            ((Object*)colliding_items[i])->explode();
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Wall))
        {
            this->explode();
            return;
        }
    }
}

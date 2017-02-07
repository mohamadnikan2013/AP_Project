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
Player::Player(double vX, double vY, double aX, double aY)
    :Object(vX, vY, aX, aY)
{
    QPixmap p(":/images/player.png");
    setPixmap(p.scaledToHeight(80));
    qDebug() << QString::number(p.height());

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
    {
/*        MovingObject dummy(0);
        if(dummy.getVYScreen() + dummy.getAYScreen() * (dummy.getAccelerateFramesYScreen() + 1) <= dummy.getMaxVYScreen())
            dummy.setAccelerateFramesYScreen(dummy.getAccelerateFramesYScreen() + 1);*/
    }
    else if(event->key() == Qt::Key_Down)
    {
/*        MovingObject dummy(0);
        if(dummy.getVYScreen() + dummy.getAYScreen() * (dummy.getAccelerateFramesYScreen() + 1) >= dummy.getMinVYScreen())
            dummy.setAccelerateFramesYScreen(dummy.getAccelerateFramesYScreen() - 1);*/
    }
}
void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Right || event->key() == Qt::Key_Left)
    {
//        qDebug() << "released";
        direction = 0;
    }
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
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
    {
        if(typeid(*(colliding_items[i])) == typeid(EnemyObject) || typeid(*(colliding_items[i])) == typeid(Wall))
        {

                  scene()->removeItem(this);
                  delete this;
                  return;
        }
    }
    setPos(x() + getDeltaX() * direction , y());
}

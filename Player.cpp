//
// Created by nikang on 1/30/17.
//

#include "Player.h"
#include "Bullet.h"
#include "game.h"
#include <QDebug>
#include <QGraphicsScene>
extern Game * game;
Player::Player()
{
    QPixmap p(":/images/player.jpg");
    setPixmap(p.scaledToHeight(120));
}
void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+width/2 , y());
        scene()->addItem(bullet);
        qDebug() << "bullet is created!";
    }
    else if(event->key() == Qt::Key_Right)
    {

    }
    else if(event->key() == Qt::Key_Left)
    {

    }
    else if(event->key() == Qt::Key_Up)
    {

    }
    else if(event->key() == Qt::Key_Down)
    {

    }
}
void Player::keyReleaseEvent(QKeyEvent *event)
{

}

int Player::getHeight()
{
    return height;
}
int Player::getWidth()
{
    return width;
}

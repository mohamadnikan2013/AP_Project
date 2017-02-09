//
// Created by nikang on 1/30/17.
//
#include <typeinfo>
#include <QGraphicsScene>
#include <QDebug>
#include "Bullet.h"
#include "EnemyObject.h"
#include "Jet.h"
#include <QDebug>

Bullet::Bullet(Player* player, double vY) : Object(Physics(), Physics(vY))
{
    this->player = player;
    setPixmap(QPixmap(":/images/missile.png").scaledToHeight(10));
}

void Bullet::advance(int phase)
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
    {
        if(((Object*)colliding_items[i])->isEnemy())
        {
            ((Object*)(colliding_items[i]))->explode();
            this->explode();
            return;
        }
    }
//    qDebug() << x() <<" " << y() << " " << getDeltaY();
    setPos(player->x() + player->getWidth() / 2 , y() + yPhys.movement());
    if(y() < 0)
        this->explode();
}

void Bullet::explode()
{
    player->setHasBullet(false);
    this->scene()->removeItem(this);
    delete this;
}

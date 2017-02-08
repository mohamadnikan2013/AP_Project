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

Bullet::Bullet(double vY) : Object(Physics(), Physics(vY))
{
    setPixmap(QPixmap(":/images/missile.png").scaledToHeight(10));
}

void Bullet::advance(int phase)
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    if(colliding_items.size() > 0)
        qDebug() << colliding_items.size();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
    {

        if(((Object*)colliding_items[i])->isEnemy())
        {
            qDebug() << "got here";
            ((Object*)(colliding_items[i]))->explode();
            this->explode();
            return;
        }
    }
//    qDebug() << x() <<" " << y() << " " << getDeltaY();
    setPos(x() , y() + yPhys.movement());
    if(y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::explode()
{
    this->scene()->removeItem(this);
    delete this;
}

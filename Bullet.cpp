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
Bullet::Bullet(double vY) : Object(0 , vY , 0 , 0)
{
    setPixmap(QPixmap(":/images/missile.png").scaledToHeight(10));
}

void Bullet::advance(int phase)
{
//    qDebug() << "Bullet is release";
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
    {
        if(typeid(*(colliding_items[i])) == typeid(Jet))
        {

            qDebug() << "got here";
            ((Object*)(colliding_items[i]))->collideWithBullet();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
//    qDebug() << x() <<" " << y() << " " << getDeltaY();
    setPos(x() , y() + getDeltaY());
    if(y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

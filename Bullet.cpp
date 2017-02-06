//
// Created by nikang on 1/30/17.
//
#include <typeinfo>
#include <QGraphicsScene>
#include "Bullet.h"
#include "EnemyObject.h"
Bullet::Bullet(double vY) : Object(0 , vY , 0 , 0)
{
    QPixmap p = QPixmap(":/images/bullet.jpg");
    p.scaledToHeight(100);
}

void Bullet::advance(int phase)
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
    {
        if(typeid(*(colliding_items[i])) == typeid(EnemyObejct))
         {

                  scene()->removeItem(colliding_items[i]);
                  scene()->removeItem(this);
                  delete colliding_items[i];
                  delete this ;
                  return ;

        }
    }
    setPos(mapToParent(0, getDeltaY()));
    if(y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

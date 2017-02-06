//
// Created by nikang on 1/30/17.
//
#include <typeinfo>
#include <QGraphicsScene>
#include <QDebug>
#include "Bullet.h"
#include "EnemyObject.h"
#include <QDebug>
Bullet::Bullet(double vY) : Object(0 , vY , 0 , 0)
{

    QPixmap p = QPixmap(":/images/missile.png");
    p.scaledToHeight(20);
    setPixmap(p);



}

void Bullet::advance(int phase)
{
    qDebug() << "Bullet is release";
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
    {
        if(typeid(*(colliding_items[i])) == typeid(EnemyObject))
         {
                  scene()->removeItem(colliding_items[i]);
                  scene()->removeItem(this);
                  delete colliding_items[i];
                  delete this ;
                  return ;
        }
    }

    qDebug() << x() <<" " << y() << " " << getDeltaY();
    setPos(x() , y() - 20);
    if(y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

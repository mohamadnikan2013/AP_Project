//
// Created by nikang on 1/31/17.
//

#include "Marinenemy.h"
#include "Wall.h"
#include <typeinfo>
#include <QDebug>


Marinenemy::Marinenemy(QString leftAddress, QString rightAddress, int height, int score, double vX)
        : EnemyObject(leftAddress, rightAddress, height,score, vX)
{
}

void Marinenemy::advance(int phase)
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
        if(typeid(*colliding_items[i]) == typeid(Wall))
        {
            this->xPhys.setV(-1 * this->xPhys.getV());
            if(this->xPhys.getV() > 0)
            {
                this->setPixmap(right);
                this->setPos(mapToParent(5, 0));
            }
            else
            {
                this->setPixmap(left);
                this->setPos(mapToParent(-5, 0));
            }
            return;
        }
    this->setPos(mapToParent(xPhys.movement(), ScreenPhys.movement()));
}

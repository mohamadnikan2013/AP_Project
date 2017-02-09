//
// Created by nikang on 1/31/17.
//

#include "Marinenemy.h"
#include "Wall.h"
#include <typeinfo>


Marinenemy::Marinenemy(QString leftAddress, QString rightAddress, int height, int score, double vX)
        : EnemyObject(leftAddress, rightAddress, height,score, vX)
{
}

void Marinenemy::advance(int phase)
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
        if(typeid(colliding_items) == typeid(Wall))
        {
            this->xPhys.setV(-this->xPhys.getV());
            if(this->xPhys.getV() > 0)
                this->setPixmap(right);
            else
                this->setPixmap(left);
            return;
        }
    this->setPos(mapToParent(xPhys.movement(), ScreenPhys.movement()));
}

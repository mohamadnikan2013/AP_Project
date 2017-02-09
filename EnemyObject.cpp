//
// Created by nikang on 1/30/17.
//

#include "EnemyObject.h"

int EnemyObject::height() const
{
    return left.height();
}

int EnemyObject::width() const
{
    return left.width();
}

EnemyObject::EnemyObject(QString leftAddress, QString rightAddress, int height, int score, double vX)
    :left(QPixmap(leftAddress).scaledToHeight(height)),
     right(QPixmap(rightAddress).scaledToHeight(height)),
     MovingObject(score, Physics(vX), Physics())
{
    if(vX > 0)
        this->setPixmap(right);
    else
        this->setPixmap(left);
}

bool EnemyObject::isEnemy()
{
    return true;
}

void EnemyObject::explode()
{
    this->scene()->removeItem(this);
    //delete this;
}

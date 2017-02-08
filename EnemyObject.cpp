//
// Created by nikang on 1/30/17.
//

#include "EnemyObject.h"


EnemyObject::EnemyObject(int score, double vX)
    :MovingObject(score, Physics(vX), Physics())
{

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

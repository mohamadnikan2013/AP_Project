//
// Created by nikang on 1/30/17.
//

#ifndef ENEMYOBEJCT_H
#define ENEMYOBEJCT_H

#include"movingObject.h"

class MovingObject;

class EnemyObject : public MovingObject{
public:
    EnemyObject(int score, double vX = 0, double vY = 0, double aX = 0, double aY = 0);
    virtual void collideWithBullet();
};


#endif //ENEMYOBEJCT_H

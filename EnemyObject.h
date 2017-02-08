//
// Created by nikang on 1/30/17.
//

#ifndef ENEMYOBEJCT_H
#define ENEMYOBEJCT_H

#include"movingObject.h"

class MovingObject;

class EnemyObject : public MovingObject{
public:
    EnemyObject(int score, double vX = 0);

    virtual bool isEnemy();
    virtual void explode();

};


#endif //ENEMYOBEJCT_H

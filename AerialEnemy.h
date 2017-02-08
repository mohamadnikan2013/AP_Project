//
// Created by nikang on 1/31/17.
//

#ifndef AERIALENEMY_H
#define AERIALENEMY_H

#include<EnemyObject.h>

class EnemyObject;

class AerialEnemy : public EnemyObject{
public:
    AerialEnemy(int score, double vX = 0);
};


#endif //AERIALENEMY_H

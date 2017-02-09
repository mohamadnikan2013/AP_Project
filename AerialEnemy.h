//
// Created by nikang on 1/31/17.
//

#ifndef AERIALENEMY_H
#define AERIALENEMY_H

#include<EnemyObject.h>

class EnemyObject;

class AerialEnemy : public EnemyObject{
public:
    AerialEnemy(QString leftAddress, QString rightAddress, int height, int score, double vX = 0);
    virtual void advance(int phase);
};


#endif //AERIALENEMY_H

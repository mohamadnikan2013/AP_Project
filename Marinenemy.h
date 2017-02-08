//
// Created by nikang on 1/31/17.
//

#ifndef MARINENEMY_H
#define MARINENEMY_H

#include"EnemyObject.h"

class EnemyObject;

class Marinenemy : public EnemyObject{
public:
    Marinenemy(int score, double vX = 0);
};


#endif //MARINENEMY_H

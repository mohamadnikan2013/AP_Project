//
// Created by nikang on 1/30/17.
//

#ifndef HELICOPTER_H
#define HELICOPTER_H

#include"AerialEnemy.h"

class AerialEnemy;

class Helicopter  : public AerialEnemy{
public:
    Helicopter(double vX = 0, double vY = 0, double aX = 0, double aY = 0);
};


#endif //HELICOPTER_H

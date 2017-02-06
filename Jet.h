//
// Created by nikang on 1/30/17.
//

#ifndef JET_H
#define JET_H

#include"AerialEnemy.h"

class AerialEnemy;

class Jet : public AerialEnemy {
public:
    Jet(double vX = 0, double vY = 0, double aX = 0, double aY = 0);
};


#endif //JET_H

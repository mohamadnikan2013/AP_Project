//
// Created by nikang on 1/30/17.
//

#ifndef DEPOTFUEL_H
#define DEPOTFUEL_H

class MovingObject;

#include"movingObject.h"

class DepotFuel : MovingObject {
public:
    DepotFuel(double vX = 0, double vY = 0, double aX = 0, double aY = 0);
};


#endif //DEPOTFUEL_H

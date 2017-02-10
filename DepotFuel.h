//
// Created by nikang on 1/30/17.
//

#ifndef DEPOTFUEL_H
#define DEPOTFUEL_H

class MovingObject;

#include"movingObject.h"

class DepotFuel : public MovingObject {
public:
    DepotFuel();
    int height();
    int width();
};


#endif //DEPOTFUEL_H

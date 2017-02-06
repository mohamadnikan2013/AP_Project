//
// Created by nikang on 1/30/17.
//

#ifndef TANKER_H
#define TANKER_H

#include "Marinenemy.h"

class Marinenemy;

class Tanker : public Marinenemy {
public:
    Tanker(double vX = 0, double vY = 0, double aX = 0, double aY = 0);
};


#endif //TANKER_H

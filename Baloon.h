//
// Created by nikang on 1/30/17.
//

#ifndef BALOON_H
#define BALOON_H

#include"Marinenemy.h"

class Marinenemy;

class Baloon : public Marinenemy{
public:
    Baloon(double vX = 0, double vY = 0, double aX = 0, double aY = 0);
};


#endif //BALOON_H

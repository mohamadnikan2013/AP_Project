//
// Created by nikang on 1/30/17.
//

#include "Helicopter.h"


Helicopter::Helicopter(double vX, double vY, double aX, double aY)
    :AerialEnemy(60, vX, vY, aX, aY)
{
    this->setPixmap(QPixmap("file"));
}

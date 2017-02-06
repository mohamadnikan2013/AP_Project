//
// Created by nikang on 1/30/17.
//

#include "DepotFuel.h"


DepotFuel::DepotFuel(double vX, double vY, double aX, double aY)
    :MovingObject(150, vX, vY, aX, aY)
{
    this->setPixmap(QPixmap(":/images/fuelDepot.png"));
}

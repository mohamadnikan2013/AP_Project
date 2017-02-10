//
// Created by nikang on 1/30/17.
//

#include "DepotFuel.h"


DepotFuel::DepotFuel()
    :MovingObject(150, Physics(), Physics())
{
    this->setPixmap(QPixmap(":/images/fuelDepot.png").scaled(20, 50));
}

int DepotFuel::height()
{
    return 50;
}

int DepotFuel::width()
{
    return 20;
}

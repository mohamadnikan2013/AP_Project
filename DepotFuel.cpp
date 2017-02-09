//
// Created by nikang on 1/30/17.
//

#include "DepotFuel.h"


DepotFuel::DepotFuel()
    :MovingObject(150, Physics(), Physics())
{
    this->setPixmap(QPixmap(":/images/fuelDepot.png").scaled(20, 50));
}

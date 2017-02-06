//
// Created by nikang on 1/30/17.
//

#include "Baloon.h"


Baloon::Baloon(double vX, double vY, double aX, double aY)
    : Marinenemy(60, vX, vY, aX, aY)
{
    this->setPixmap(QPixmap(":/images/balloon.png"));
}

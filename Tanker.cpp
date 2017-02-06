//
// Created by nikang on 1/30/17.
//

#include "Tanker.h"


Tanker::Tanker(double vX, double vY, double aX, double aY)
    :Marinenemy(30, vX, vY, aX, aY)
{
    if(vX > 0)
        this->setPixmap(QPixmap(":/images/rightTanker.png"));
    else
        this->setPixmap(QPixmap(":/images/leftTanker.png"));
}

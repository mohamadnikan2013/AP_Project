//
// Created by nikang on 1/30/17.
//

#include "Jet.h"


Jet::Jet(double vX, double vY, double aX, double aY)
    :AerialEnemy(100, vX, vY, aX, aY)
{
    if(vX > 0)
        this->setPixmap(QPixmap(":/images/rightJet.png"));
    else
        this->setPixmap(QPixmap(":/images/leftJet.png"));
}

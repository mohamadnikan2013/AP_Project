//
// Created by nikang on 1/30/17.
//

#include "Helicopter.h"


Helicopter::Helicopter(double vX)
    :AerialEnemy(60, vX)
{
    if(vX > 0)
        this->setPixmap(QPixmap(":/images/rightHelicopter.png"));
    else
        this->setPixmap(QPixmap(":/images/leftHelicopter.png"));
}

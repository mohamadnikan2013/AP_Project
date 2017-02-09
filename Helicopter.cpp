//
// Created by nikang on 1/30/17.
//

#include "Helicopter.h"
#include "Wall.h"
#include <typeinfo>

Helicopter::Helicopter(double vX)
    :Marinenemy(":/images/leftHelicopter.gif", ":/images/rightHelicopter.gif", 15, 60, vX)
{
}

//
// Created by nikang on 1/30/17.
//

#include "Object.h"

Object::Object(Physics xPhys, Physics yPhys)
{
    this->xPhys = xPhys;
    this->yPhys = yPhys;
}

void Object::advance(int phase)
{
    setPos(mapToParent(xPhys.movement(), yPhys.movement()));
}

bool Object::isEnemy()
{
    return false;
}

void Object::explode()
{

}

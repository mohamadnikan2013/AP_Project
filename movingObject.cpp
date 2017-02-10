#include "movingObject.h"

#include<QDebug>

Physics MovingObject::ScreenPhys;


int MovingObject::getScore() const
{
    return score;
}
MovingObject::MovingObject(int score, Physics xPhys, Physics yPhys)
    : score(score), Object(xPhys, yPhys)
{
}

void MovingObject::advance(int phase)
{
    setPos(mapToParent(xPhys.movement(), yPhys.movement() + ScreenPhys.movement()));
}

Physics& MovingObject::screenPhysics()
{
    return ScreenPhys;
}

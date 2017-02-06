#include "movingObject.h"

double MovingObject::vYScreen;
double MovingObject::aYScreen;
double MovingObject::maxVYScreen;
double MovingObject::minVYScreen;

double MovingObject::getVYScreen()
{
    //return vYScreen;
    return MovingObject::vYScreen;
}

void MovingObject::setVYScreen(double value)
{
    vYScreen = value;
}

double MovingObject::getAYScreen()
{
    return aYScreen;
}

void MovingObject::setAYScreen(double value)
{
    aYScreen = value;
}

double MovingObject::getMaxVYScreen()
{
    return maxVYScreen;
}

void MovingObject::setMaxVYScreen(double value)
{
    maxVYScreen = value;
}

double MovingObject::getMinVYScreen()
{
    return minVYScreen;
}

void MovingObject::setMinVYScreen(double value)
{
    minVYScreen = value;
}

int MovingObject::getAccelerateFramesYScreen() const
{
    return accelerateFramesYScreen;
}

void MovingObject::setAccelerateFramesYScreen(int value)
{
    accelerateFramesYScreen = value;
}
MovingObject::MovingObject(int score, double vX, double vY, double aX, double aY)
    : score(score), Object(vX, vY, aX, aY)
{
    accelerateFramesYScreen = 0;
}

double MovingObject::getDeltaYScreen()
{
    return (vYScreen + aYScreen * accelerateFramesYScreen) / getFramesPerSecond();
}

void MovingObject::advance(int phase)
{
    setPos(mapToParent(getDeltaX(), getDeltaY() + getDeltaYScreen()));
}

#include "movingObject.h"


MovingObject::MovingObject(int score, double vYScreen, double aYScreen, double maxVYScreen, double vX, double vY, double aX, double aY)
    :vYScreen(vYScreen), score(score), aYScreen(aYScreen), maxVYScreen(maxVYScreen), Object(vX, vY, aX, aY)
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

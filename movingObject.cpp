#include "movingObject.h"


MovingObject::MovingObject(int framesPerSecond, double vYScreen, double aYScreen, double maxVYScreen, double vX, double vY, double aX, double aY)
    :vYScreen(vYScreen), aYScreen(aYScreen), maxVYScreen(maxVYScreen), Object(framesPerSecond, vX, vY, aX, aY)
{
    accelerateFramesYScreen = 0;
}

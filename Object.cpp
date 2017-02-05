//
// Created by nikang on 1/30/17.
//

#include "Object.h"


int Object::getAccelerateFramesX() const
{
    return accelerateFramesX;
}

void Object::setAccelerateFramesX(int value)
{
    accelerateFramesX = value;
}

int Object::getAccelerateFramesY() const
{
    return accelerateFramesY;
}

void Object::setAccelerateFramesY(int value)
{
    accelerateFramesY = value;
}

Object::Object(int framesPerSecond, double vX, double vY, double aX, double aY) : framesPerSecond(framesPerSecond), vX(vX), vY(vY), aX(aX), aY(aY)
{
}

int Object::getFramesPerSecond() const
{
    return framesPerSecond;
}

double Object::getAY() const
{
    return aY;
}

double Object::getAX() const
{
    return aX;
}

double Object::getVY() const
{
    return vY;
}

double Object::getVX() const
{
    return vX;
}

int Object::getDeltaX()
{
    return (vX + aX * accelerateFramesX) / framesPerSecond;
}

int Object::getDeltaY()
{
    return (vY + aY * accelerateFramesY) / framesPerSecond;
}

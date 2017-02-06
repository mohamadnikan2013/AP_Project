//
// Created by nikang on 1/30/17.
//

#include "Object.h"

int Object::framesPerSecond = 30;

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

Object::Object(double vX, double vY, double aX, double aY) : vX(vX), vY(vY), aX(aX), aY(aY)
{
    accelerateFramesX = 0;
    accelerateFramesY = 0;
}

int Object::getFramesPerSecond() const
{
    return framesPerSecond;
}

int Object::setFramesPerSecond(int f)
{
    framesPerSecond = f;
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

double Object::getDeltaX()
{
    return (vX + aX * accelerateFramesX) / framesPerSecond;
}

double Object::getDeltaY()
{
    return (vY + aY * accelerateFramesY) / framesPerSecond;
}

void Object::advance(int phase)
{
    setPos(mapToParent(getDeltaX(), getDeltaY()));
}

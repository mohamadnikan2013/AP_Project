#include "physics.h"

int Physics::fps;

int Physics::getFps()
{
    return fps;
}

void Physics::setFps(int value)
{
    fps = value;
}

double Physics::getMaxV() const
{
    return maxV;
}

void Physics::setMaxV(double value)
{
    maxV = value;
}

double Physics::getMinV() const
{
    return minV;
}

void Physics::setMinV(double value)
{
    minV = value;
}
Physics::Physics(double v, double a, double maxV, double minV)
{
    this->v = v;
    this->a = a;
    this->maxV = maxV;
    this->minV = minV;
    this->accelerattionFrames = 0;
}

double Physics::getV() const
{
    return v;
}

void Physics::setV(double value)
{
    v = value;
}

double Physics::getA() const
{
    return a;
}

void Physics::setA(double value)
{
    a = value;
}

void Physics::accelerate(int x)
{
    double nextV = this->v + this->a * (this->accelerattionFrames + x);
    if(nextV > maxV || nextV < minV)
        return;
    this->accelerattionFrames += x;
}

int Physics::getAccelerattionFrames() const
{
    return accelerattionFrames;
}

double Physics::movement()
{
    return (this->v + this->a * this->accelerattionFrames) / fps;
}

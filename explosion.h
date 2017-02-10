#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "movingObject.h"
#include "physics.h"

class Explosion : public MovingObject
{
private:
    int length;
    int framesPast;
    int picNumber;
public:
    Explosion(int length);
    virtual void advance(int phase);
};

#endif // EXPLOSION_H

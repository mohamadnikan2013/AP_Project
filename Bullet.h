//
// Created by nikang on 1/30/17.
//

#ifndef BULLET_H
#define BULLET_H

#include "Object.h"

class Object;

class Bullet : public Object {
public:

    Bullet(double vY);
    virtual void advance(int phase);
};


#endif //BULLET_H

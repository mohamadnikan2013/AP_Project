//
// Created by nikang on 1/30/17.
//

#ifndef WALL_H
#define WALL_H

#include "movingObject.h"

class MovingObject;

class Wall :public MovingObject {
public:
    Wall(int width, int height);
};


#endif //WALL_H

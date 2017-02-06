//
// Created by nikang on 1/30/17.
//

#include "Wall.h"


Wall::Wall( int width, int height)
    :MovingObject(0, 0, 0, 0, 0)
{
    this->setPixmap(QPixmap(":/images/green.png").scaled(width, height));
}

//
// Created by nikang on 1/30/17.
//

#include "Bullet.h"
Bullet::Bullet(double vY) : Object(0 , vY , 0 , 0)
{
    QPixmap p = QPixmap(":/images/bullet.jpg");
    p.scaledToHeight(100);
}

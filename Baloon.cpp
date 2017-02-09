//
// Created by nikang on 1/30/17.
//

#include "Baloon.h"


Baloon::Baloon(double vX, double vY, double aX, double aY)
<<<<<<< HEAD
    : Marinenemy(":/images/leftBalloon.png", ":/images/rightBalloon.png", 50, 60, vX)
{
=======
        : Marinenemy(60, vX) {
    this->setPixmap(QPixmap(":/images/balloon.png").scaled(80, 80));
>>>>>>> 871b6673e634db03b3d5aa0ab6c47fc371956e15
}

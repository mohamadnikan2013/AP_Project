//
// Created by nikang on 1/31/17.
//

#include "AerialEnemy.h"


AerialEnemy::AerialEnemy(QString leftAddress, QString rightAddress, int height, int score, double vX)
    : EnemyObject(leftAddress, rightAddress, height,score, vX)
{

}

void AerialEnemy::advance(int phase)
{
    this->setPos(mapToParent(xPhys.movement(), ScreenPhys.movement()));
    if(x() + height() < 0 && xPhys.getV() < 0)
        setX(scene()->width());
    else if(x() > scene()->width() && xPhys.getV() > 0)
        setX(-width());
}

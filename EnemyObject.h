//
// Created by nikang on 1/30/17.
//

#ifndef ENEMYOBEJCT_H
#define ENEMYOBEJCT_H

#include"movingObject.h"
class MovingObject;

class EnemyObject : public MovingObject{
protected:
    const QPixmap left;
    const QPixmap right;
public:
    EnemyObject(QString leftAddress, QString rightAddress, int height, int score, double vX = 0);

    virtual bool isEnemy();
    virtual void explode();

    int height() const;
    int width() const;
};

#endif //ENEMYOBEJCT_H

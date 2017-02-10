//
// Created by nikang on 1/30/17.
//

#include "EnemyObject.h"
#include <QDebug>

int EnemyObject::height() const
{
    return left.height();
}

int EnemyObject::width() const
{
    return left.width();
}

EnemyObject::EnemyObject(QString leftAddress, QString rightAddress, int height, int score, double vX)
    :left(QPixmap(leftAddress).scaledToHeight(height)),
     right(QPixmap(rightAddress).scaledToHeight(height)),
     MovingObject(score, Physics(vX), Physics())
{
    if(vX > 0)
        this->setPixmap(right);
    else
        this->setPixmap(left);
}

bool EnemyObject::isEnemy()
{
    return true;
}

void EnemyObject::explode()
{
    int expLength = qMin(this->height(), this->width());
    QPoint center(this->x() + this->width() / 2, this->y() + this->height() / 2);
    Explosion* explosion = new Explosion(expLength);
    explosion->setPos(center.x() - expLength / 2, center.y() - expLength / 2);
    this->scene()->addItem(explosion);
    this->scene()->removeItem(this);
    //delete this;
}

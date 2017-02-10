#include "explosion.h"

Explosion::Explosion(int length): MovingObject(0, Physics(), Physics())
{
    this->length = length;
    framesPast = 0;
    picNumber = 1;
    this->setPixmap(QPixmap(":images/explode1.png").scaled(length, length));
}

void Explosion::advance(int phase)
{
    framesPast++;
    if(((double)1) / Physics::getFps() * framesPast > (double)0.15)
    {
        if(picNumber++ < 6)
        {
            framesPast = 0;
            QPixmap pixmap(":images/explode" + QString::number(picNumber) + ".png");
            pixmap = pixmap.scaled(length, length);
            this->setPixmap(pixmap);
        }
        else
        {
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    this->setPos(mapToParent(0, this->screenPhysics().movement()));
}

//
// Created by nikang on 1/30/17.
//
#include <typeinfo>
#include <QGraphicsScene>
#include <QDebug>
#include "Bullet.h"
#include "EnemyObject.h"
#include "Jet.h"
#include <QDebug>
#include<typeinfo>
#include"Wall.h"

Bullet::Bullet(Game* game, Player* player, double vY) : Object(Physics(), Physics(vY))
{
    this->game = game;
    this->player = player;
    setPixmap(QPixmap(":/images/missile.png").scaledToHeight(10));
}

void Bullet::advance(int phase)
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0 , n = colliding_items.size() ; i < n ; i++ )
    {
        if(((Object*)colliding_items[i])->isEnemy() || typeid(*(colliding_items[i])) == typeid(DepotFuel))
        {
            ((Object*)(colliding_items[i]))->explode();
            game->addScore(((MovingObject*)colliding_items[i])->getScore());
            this->explode();
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Wall))
            this->explode();
    }
//    qDebug() << x() <<" " << y() << " " << getDeltaY();
    setPos(player->x() + player->getWidth() / 2 , y() + yPhys.movement());
    if(y() < 0)
        this->explode();
}

void Bullet::explode()
{
    player->setHasBullet(false);
    this->scene()->removeItem(this);
    delete this;
}

//
// Created by nikang on 1/30/17.
//

#ifndef BULLET_H
#define BULLET_H

#include "Object.h"
#include "Player.h"

class Object;
class Player;

class Bullet : public Object {
    Game* game;
    Player* player;
public:
    Bullet(Game* game, Player* player, double vY);
    virtual void advance(int phase);
    virtual void explode();
};


#endif //BULLET_H

//
// Created by nikang on 1/30/17.
//

#ifndef PLAYER_H
#define PLAYER_H

#include"Object.h"
#include <QKeyEvent>
#include <QtMultimedia/qsound.h>
#include "game.h"
#include "DepotFuel.h"
#include"fuelindicator.h"
class Game;
class Object;

class Player : public Object{
private:
    Game* game;
    static int height;
    static int width;

    int direction;
    bool upKeyPushed;
    bool downKeyPushed;
    bool rightKeyPushed;
    bool leftKeyPushed;
    bool hasBullet;
    FuelIndicator * fuel;

    QSound sound;
public:
    virtual void advance(int phase);
    Player(FuelIndicator* fuel , Game* game, double vX, double aX);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    virtual void explode();
    void setHasBullet(bool value);
    static int getHeight();
    static void setHeight(int value);
    static int getWidth();
    static void setWidth(int value);
};


#endif //MAINJET_H

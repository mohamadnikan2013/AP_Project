//
// Created by nikang on 1/30/17.
//

#ifndef PLAYER_H
#define PLAYER_H

#include"Object.h"
#include <QKeyEvent>
class Object;

class Player : public Object{
public:
    Player(double vX, double vY = 0, double aX = 0, double aY = 0);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
private:
    const int playerScaledOfImageHeight = 120;
    const int playerScaledOfImageWidth = 120;
    int direction;
public:
    int getHeightScaled() const;
    int getWidthScaled() const;
    virtual void advance(int phase);
};


#endif //MAINJET_H

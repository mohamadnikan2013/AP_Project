//
// Created by nikang on 1/30/17.
//

#ifndef PLAYER_H
#define PLAYER_H

#include"Object.h"
#include <QKeyEvent>
class Object;

class Player : public Object{
private:
    const int playerScaledOfImageHeight = 120;
    const int playerScaledOfImageWidth = 120;
    int direction;
    bool upKeyPushed;
    bool downKeyPushed;
public:
    int getHeightScaled() const;
    int getWidthScaled() const;
    virtual void advance(int phase);
    Player(double vX, double aX);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    virtual void explode();
};


#endif //MAINJET_H

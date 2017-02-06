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
    Player();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
private:
    const int playerScaledOfImageHeight = 120;
    const int playerScaledOfImageWidth = 120;
public:
    int getHeightScaled() const;
    int getWidthScaled() const;
};


#endif //MAINJET_H

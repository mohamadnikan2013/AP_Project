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
    int height;
    int width;
public:
    int getHeight();
    int getWidth();
};


#endif //MAINJET_H

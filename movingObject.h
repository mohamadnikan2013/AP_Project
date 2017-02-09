#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include"Object.h"
#include<QObject>

class Object;
class QObject;

class MovingObject:public Object , public QObject{
protected:
    static Physics ScreenPhys;
    const int score;
public:
    MovingObject(int score, Physics xPhys, Physics yPhys);
    virtual void advance(int phase);

    static Physics& screenPhysics();
};

#endif // MOVINGOBJECT_H

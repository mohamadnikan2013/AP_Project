#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include"Object.h"
#include<QObject>

class Object;
class QObject;

class MovingObject:public Object , public QObject{
protected:
    const double vYScreen;
    const double aYScreen;
    const double maxVYScreen;
    int accelerateFramesYScreen;
public:
    MovingObject(int framesPerSecond, double vYScreen, double aYScreen,double maxVYScreen, double vX = 0, double vY = 0, double aX = 0, double aY = 0);
};

#endif // MOVINGOBJECT_H

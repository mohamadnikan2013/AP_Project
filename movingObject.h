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
    const int score;
public:
    MovingObject(int framesPerSecond, int score,  double vYScreen, double aYScreen,double maxVYScreen, double vX = 0, double vY = 0, double aX = 0, double aY = 0);
    double getDeltaYScreen();
    virtual void advance(int phase);
};

#endif // MOVINGOBJECT_H

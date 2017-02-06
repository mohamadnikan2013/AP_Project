#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include"Object.h"
#include<QObject>

class Object;
class QObject;

class MovingObject:public Object , public QObject{
protected:
    static double vYScreen;
    static double aYScreen;
    static double maxVYScreen;
    static double minVYScreen;
    int accelerateFramesYScreen;
    const int score;
public:
    MovingObject(int score, double vX = 0, double vY = 0, double aX = 0, double aY = 0);
    double getDeltaYScreen();
    virtual void advance(int phase);

    static double getVYScreen();
    static void setVYScreen(double value);
    static double getAYScreen();
    static void setAYScreen(double value);
    static double getMaxVYScreen();
    static void setMaxVYScreen(double value);
    static double getMinVYScreen();
    static void setMinVYScreen(double value);
    int getAccelerateFramesYScreen() const;
    void setAccelerateFramesYScreen(int value);
};

#endif // MOVINGOBJECT_H

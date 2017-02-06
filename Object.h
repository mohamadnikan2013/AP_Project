//
// Created by nikang on 1/30/17.
//

#ifndef OBJECT_H
#define OBJECT_H

#include<QGraphicsPixmapItem>

class QGraphicsPixmapItem;

class Object : public QGraphicsPixmapItem{
protected:
    const double vX;
    const double vY;
    const double aX;
    const double aY;

    int accelerateFramesX;
    int accelerateFramesY;
    int a;
private:
    static int framesPerSecond;
public:
    Object(double vX = 0, double vY = 0, double aX = 0, double aY = 0);

    int getFramesPerSecond() const;

    int setFramesPerSecond(int f);

    double getAY() const;

    double getAX() const;

    double getVY() const;

    double getVX() const;

    int getAccelerateFramesX() const;

    void setAccelerateFramesX(int value);

    int getAccelerateFramesY() const;

    void setAccelerateFramesY(int value);

    double getDeltaX();

    double getDeltaY();

    virtual void advance(int phase);
};

#endif //OBJECT_H

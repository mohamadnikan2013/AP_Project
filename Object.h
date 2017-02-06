//
// Created by nikang on 1/30/17.
//

#ifndef OBJECT_H
#define OBJECT_H

#include<QGraphicsPixmapItem>

class QGraphicsPixmapItem;

class Object : public QGraphicsPixmapItem{
protected:
    double vX;
    double vY;
    double aX;
    double aY;

    int accelerateFramesX;
    int accelerateFramesY;
    int a;
private:
    static int framesPerSecond;
public:
    Object(double vX = 0, double vY = 0, double aX = 0, double aY = 0);

    int getFramesPerSecond() const;

    int setFramesPerSecond(int f);

    int getAccelerateFramesX() const;

    void setAccelerateFramesX(int value);

    int getAccelerateFramesY() const;

    void setAccelerateFramesY(int value);

    double getDeltaX();

    double getDeltaY();

    virtual void advance(int phase);
    double getVX() const;
    void setVX(double value);
    double getVY() const;
    void setVY(double value);
    double getAX() const;
    void setAX(double value);
    double getAY() const;
    void setAY(double value);
};

#endif //OBJECT_H

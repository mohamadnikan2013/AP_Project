//
// Created by nikang on 1/30/17.
//

#ifndef OBJECT_H
#define OBJECT_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include"physics.h"

#define inf 999999999

class QGraphicsPixmapItem;
class QGraphicsScene;

class Object : public QGraphicsPixmapItem{
protected:
    Physics xPhys;
    Physics yPhys;
    int a;
public:
    Object(Physics xPhys, Physics yPhys);

    int getFramesPerSecond() const;

    int setFramesPerSecond(int f);

    virtual void advance(int phase);

    virtual bool isEnemy();
    virtual void explode();
};

#endif //OBJECT_H

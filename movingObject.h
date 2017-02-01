#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H
#include"Object.h"
#include<QObject>
class MovingObject:public Object , public QObject{
public:
    MovingObject();
};

#endif // MOVINGOBJECT_H

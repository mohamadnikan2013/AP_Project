#ifndef FUELINDICATOR_H
#define FUELINDICATOR_H

#include <QGraphicsItemGroup>
#include <QPen>
#include <QtMath>
#include <QDebug>

class FuelIndicator : public QGraphicsItemGroup
{
private:
    double fuel;
    bool increase;
    const QPoint center;
    const double indicatorLength;
    int fps;

    QGraphicsPixmapItem* backGround;
    QGraphicsLineItem* indicator;
public:
    FuelIndicator(int fps, double length);
    QPoint getDist();
    virtual void advance(int phase);
    void onDepotFuel();
    void offDepotFuel();
    bool is_empty();
};

#endif // FUELINDICATOR_H

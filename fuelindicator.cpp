#include "fuelindicator.h"

FuelIndicator::FuelIndicator(int fps, double length) : center(length / 2, length * 28 / 40), indicatorLength(length * 23 / 50)
{
    this->fps = fps;
    backGround = new QGraphicsPixmapItem(QPixmap(":/images/fuelIndicator.png").scaled(length, length));
    increase = false;

    this->fuel = 10000000;
    QPen pen;
    pen.setColor(Qt::red);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(length / 30);
    indicator = new QGraphicsLineItem();
    indicator->setPen(pen);
    QPoint dest = getDist();
    indicator->setLine(center.x(), center.y(), dest.x(), dest.y());

    this->addToGroup(backGround);
    this->addToGroup(indicator);

    this->setZValue(10.0);
}

QPoint FuelIndicator::getDist()
{
    QPoint res;

    double alpha = qDegreesToRadians(133 - fuel / 1000 * 86);
    res.setX(center.x() + qCos(alpha) * indicatorLength);
    res.setY(center.y() - qSin(alpha) * indicatorLength);
    return res;
}

void FuelIndicator::advance(int phase)
{
    if(increase)
        fuel += (double)1000 / 5 / fps;
    else
        fuel -= (double)1000 / 25 / fps;
    if(fuel < 0)
    {
        fuel = 0;
        return;
    }
    if(fuel > 1000)
    {
        fuel = 1000;
        return;
    }
    QPoint dest = getDist();
    indicator->setLine(center.x(), center.y(), dest.x(), dest.y());
}

void FuelIndicator::onDepotFuel()
{
    increase = true;
}

void FuelIndicator::offDepotFuel()
{
    increase = false;
}

bool FuelIndicator::is_empty()
{
    if (this->fuel<=0.00001)
        return true;
    return false;
}

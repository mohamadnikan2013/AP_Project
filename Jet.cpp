//
// Created by nikang on 1/30/17.
//

#include "Jet.h"
#include <QDebug>


Jet::Jet(double vX)
        : AerialEnemy(":/images/lefttJet.png", ":/images/rightJet.png", 17, 100, vX)
{
    if(left.isNull())
        qDebug() << "why?";
    QPixmap p(":/images/lefttJet.png");
    if(p.isNull())
        qDebug() << "wth?";
}

Jet::~Jet() {

}

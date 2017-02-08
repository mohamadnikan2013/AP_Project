//
// Created by nikang on 1/30/17.
//

#include "Tanker.h"


Tanker::Tanker(double vX)
        : Marinenemy(30, vX) {
    if (vX > 0)
        this->setPixmap(QPixmap(":/images/rightTanker.png"));
    else
        this->setPixmap(QPixmap(":/images/leftTanker.png"));
}

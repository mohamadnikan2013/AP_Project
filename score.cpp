#include "score.h"

Score::Score()
{
    score = 0;
    this->setPlainText(QString::number(score));
    this->setZValue(10);
}

void Score::addScore(int x)
{
    score += x;
    this->setPlainText(QString::number(score));
}

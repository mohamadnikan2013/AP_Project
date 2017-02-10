#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QString>
class Score : public QGraphicsTextItem
{
private:
    int score;
public:
    Score();
    void addScore(int x);
};

#endif // SCORE_H

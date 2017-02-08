#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include<QList>
#include "Player.h"
#include "score.h"
#include "Jet.h"

class Game : public QGraphicsView
{
private:
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    const int height;
    const int width;
public:
    Game(int w = 800 , int h = 600);

    void createMap(QGraphicsScene* scene, int y, int height, int road, int difficulty);
};

#endif // GAME_H

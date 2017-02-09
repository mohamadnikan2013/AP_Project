#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include<QList>
#include "Player.h"
#include "score.h"
#include "Jet.h"

class Game : public QGraphicsView {
private:
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    const int height;
    const int width;
    int difficulty;
    int river_width;
    int framesPerSecond;
    bool is_finished;

public:
    Game(int w = 900, int h = 550);

public slots:
    void create_map();
    void create_enemies();
};

#endif // GAME_H

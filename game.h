#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include<QList>
#include "Player.h"
#include "score.h"
#include "Jet.h"
#include "fuelindicator.h"

class Game : public QGraphicsView {
private:
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    FuelIndicator* fuelIndicator;
    const int height;
    const int width;
    int difficulty;
    int river_width;
    int framesPerSecond;
    bool is_finished;

public:
    Game(int w = 900, int h = 600);

public
    Q_SLOTS:
    void

    advance();

    void create_map();

    void create_enemies();

    //virtual void drawBackground(QPainter *painter, const QRectF &rect);
};

#endif // GAME_H

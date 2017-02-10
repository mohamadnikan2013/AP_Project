#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include<QList>
#include "Player.h"
#include "score.h"
#include "Jet.h"
#include "fuelindicator.h"
#include "score.h"
#include <QTimer>
#include "menu.h"
#include "Wall.h"

class Menu;
class Player;

class Game : public QGraphicsView {
    Q_OBJECT
private:
    QTimer *timer;
    QTimer *enemytimer;
    Menu* menu;
    bool ispaused;
    QGraphicsScene* scene;
    Player *player;
    Score *score;
//    QTimer* timer;
    FuelIndicator* fuelIndicator;
    const int height;
    const int width;
    int difficulty;
    int river_width;
    int framesPerSecond;
    bool is_finished;
    Wall* highestWall;

public:
    Game(int w = 900, int h = 600);
    void addScore(int x);
    void onFuel();
    void offFuel();
    ~Game();


public slots:
//    Q_SLOTS:

//    advance();

    void create_map();

    void create_enemies();

    void pause();
    void unPause();

    //virtual void drawBackground(QPainter *painter, const QRectF &rect);
};

#endif // GAME_H

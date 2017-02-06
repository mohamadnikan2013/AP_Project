#include "game.h"

Game::Game(int w, int h) : width(w), height(h)
{

    scene = new QGraphicsScene;
    scene->setSceneRect( 0 , 0 , width , height);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width , height);
    setScene(scene);
    player = new Player;
    player->setPos(rect().width()/2 , rect().height() - player->getHeight());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    score = new Score;

    scene->addItem(player);
    scene->addItem(score);


}

#include "game.h"
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <movingObject.h>
Game::Game(int w, int h) : width(w), height(h)
{
    int framesPerSecond = 30;
    //Object::setFramesPerSecond(framesPerSecond);
    scene = new QGraphicsScene;
    scene->setSceneRect( 0 , 0 , width , height);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width , height);
    setScene(scene);
    player = new Player(80);

    setBackgroundBrush(QBrush("blue"));
    player->setFramesPerSecond(framesPerSecond);
    MovingObject::setVYScreen(20);
    MovingObject::setAYScreen(10);
    MovingObject::setMaxVYScreen(80);
    MovingObject::setMinVYScreen(10);

    player->setPos(rect().width()*0.45 ,  rect().height() - player->getHeightScaled());
    qDebug() << rect().height();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    Jet* jet = new Jet(20);
    scene->addItem(jet);

    score = new Score;

    scene->addItem(player);
    scene->addItem(score);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000 / framesPerSecond);

}

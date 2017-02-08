#include "game.h"
#include "physics.h"
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <movingObject.h>
#include "Bullet.h"
#include "Baloon.h"
Game::Game(int w, int h) : width(w), height(h)
{
    int framesPerSecond = 30;
    scene = new QGraphicsScene;
    scene->setSceneRect( 0 , 0 , width , height);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width , height);
    setScene(scene);
    player = new Player(80, 10);

    setBackgroundBrush(QBrush("blue"));
    Physics::setFps(framesPerSecond);
    MovingObject::screenPhysics().setV(20);
    MovingObject::screenPhysics().setA(10);
    MovingObject::screenPhysics().setMaxV(80);
    MovingObject::screenPhysics().setMinV(10);


    player->setPos(rect().width()*0.45 ,  rect().height() - player->getHeight());
    qDebug() << player->x() << "  " << player->y();
    qDebug() << rect().height();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    Baloon* jet = new Baloon(20);
    scene->addItem(jet);

    score = new Score;

    scene->addItem(player);
    scene->addItem(score);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000 / framesPerSecond);
}

void Game::createMap(QGraphicsScene *scene, int y, int height, int road, int difficulty)
{

}

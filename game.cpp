#include "game.h"
#include "physics.h"
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <movingObject.h>
#include "Bullet.h"
#include "Baloon.h"
#include "Tanker.h"
#include "Helicopter.h"
#include "DepotFuel.h"

Game::Game(int w, int h) : width(w), height(h) {
    framesPerSecond = 30;
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, width, height);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width, height);
    setScene(scene);
    player = new Player(80, 10);

    setBackgroundBrush(QBrush("gray"));
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

//    Baloon* jet = new Baloon(20);
//    scene->addItem(jet);
//    EnemyObject *jet = new Jet(20);
//    jet->setPos(rect().width()*.2,rect().width()*.2);
//    jet->setFlag(QGraphicsItem::ItemIsFocusable);
//    jet->setFocus();
//    qDebug()<<jet->pos();

//    scene->addItem(jet);
    score = new Score;

    scene->addItem(player);
    scene->addItem(score);
//qDebug()<< random();
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(create_enemies()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(create_map()));
    timer->start(1000 / framesPerSecond);
}

void Game::create_enemies() {
    int rand = 2;
    EnemyObject *enemy;
    QList<QGraphicsItem *> colliding_items;
    switch (rand) {
    case 1:
        enemy = new Baloon();
        do {
         enemy->setPos(rect().width()*(0.2) ,  rect().height());
         colliding_items =   enemy->collidingItems();
        } while (!colliding_items.isEmpty());
        break;
    case 2:
        enemy = new Jet();
        enemy->setPos(rect().width()*(0.2) ,  rect().height());
        break;
    case 3:
        enemy = new Helicopter();
        enemy->setPos(rect().width()*(0.2) ,  rect().height());
        break;
    case 4:
        enemy = new Tanker();
        do {
         enemy->setPos(rect().width()*(0.2) ,  rect().height());
         colliding_items =   enemy->collidingItems();
        } while (!colliding_items.isEmpty());
        break;
    default:
        return;
    }
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(enemy);
}

void Game::create_map() {

}

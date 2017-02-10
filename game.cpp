#include "game.h"
#include "physics.h"
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <movingObject.h>
#include "Bullet.h"
#include "Baloon.h"
#include"Wall.h"
#include "Tanker.h"
#include "Helicopter.h"
#include "DepotFuel.h"

Game::Game(int w, int h) : width(w), height(h) {
    this->menu = new Menu(this);
    menu->hide();
    framesPerSecond = 30;
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, width, height);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width, height);
    setScene(scene);
    player = new Player(this, 80, 10);

    setBackgroundBrush(QBrush("blue"));
    Physics::setFps(framesPerSecond);
    MovingObject::screenPhysics().setV(20);
    MovingObject::screenPhysics().setA(10);
    MovingObject::screenPhysics().setMaxV(80);
    MovingObject::screenPhysics().setMinV(10);

    fuelIndicator = new FuelIndicator(framesPerSecond, 90);
    fuelIndicator->setPos(0, this->height - 90);
    scene->addItem(fuelIndicator);


    player->setPos(rect().width() / 2 - player->getWidth() / 2, (rect().height() - player->getHeight()) * 5 / 6);
    qDebug() << player->x() << "  " << player->y();
    qDebug() << rect().height();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    Wall *walll = new Wall(150, this->height+170);
    Wall *wallr = new Wall(150, this->height+170);
    walll->setPos(rect().width() - this->width, rect().height() - this->height-150);
    wallr->setPos(rect().width() - 150, rect().height() - this->height-150);
    scene->addItem(walll);
    scene->addItem(wallr);


    score = new Score;
    score->setPos(this->width - 80, this->height - 60);
    scene->addItem(score);

//    int rand1 = 10;
//    int rand2 = 20;
//    int height = 20;
//    Wall *walll = new Wall(rand1, height);
//    Wall *wallr = new Wall(rand2, height);
//    walll->setPos(rect().width() - this->width, rect().height() - this->height);
//    wallr->setPos(rect().width() - rand2, rect().height() - this->height);;
//    scene->addItem(walll);
//    scene->addItem(wallr);




//qDebug()<< qrand();

    QTimer *timer = new QTimer();
    QTimer *timer1 = new QTimer();
    QTimer *timer2 = new QTimer();
    timer1->start(3000);
    timer2->start(4000);
    QObject::connect(timer1, SIGNAL(timeout()), this, SLOT(create_map()));
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(create_enemies()));

    timer->start(1000 / framesPerSecond);

}
void Game::pause()
{
    ispaused = true;
    timer->stop();
    timer1->stop();
    menu->show();
    this->hide();
}

void Game::unPause()
{
    timer->start();
    timer1->start();
    ispaused = false;
    menu->hide();
    this->show();
}

void Game::create_enemies() {
    int myrand = qrand()%7;
    int speed = 20+qrand()%70;
    MovingObject *enemy;
    QList < QGraphicsItem * > colliding_items;
    switch (myrand) {
        case 1:
            enemy = new Baloon(speed);
             enemy->setPos(rect().width()-(qrand()%800), rect().height()-this->height);
            break;
        case 2:
            enemy = new Jet(speed);
             enemy->setPos(rect().width()-(qrand()%800), rect().height()-this->height);
            break;
        case 3:
            enemy = new Helicopter(speed);
            do {
                enemy->setPos(rect().width()-(qrand()%800), rect().height()-this->height);
                colliding_items = enemy->collidingItems();
            } while (!colliding_items.isEmpty());
            break;
        case 4:
            enemy = new Tanker(speed);
            do {
                enemy->setPos(rect().width()-(qrand()%800), rect().height()-this->height);
                colliding_items = enemy->collidingItems();
            } while (!colliding_items.isEmpty());
            break;
        case 5:
        enemy = new DepotFuel();
        do {
            enemy->setPos(rect().width()-(qrand()%800), rect().height()-this->height);
            colliding_items = enemy->collidingItems();
        } while (!colliding_items.isEmpty());
        break;
        default:
            return;
    }
    qDebug()<<myrand;
    this->scene->addItem(enemy);
}
void Game::create_map() {
    int rand1 = 100+qrand()%150;
    int rand2 = 100+qrand()%150;
    int height = 130;
    Wall *walll = new Wall(rand1, height);
    Wall *wallr = new Wall(rand2, height);
    walll->setPos(rect().width() - this->width, rect().height() - this->height-150);
    wallr->setPos(rect().width() - rand2, rect().height() - this->height-150);
    scene->addItem(walll);
    scene->addItem(wallr);
}

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

    fuelIndicator = new FuelIndicator(framesPerSecond, 90);
    fuelIndicator->setPos(0, this->height - 90);
    scene->addItem(fuelIndicator);


    player->setPos(rect().width() / 2 - player->getWidth() / 2, (rect().height() - player->getHeight()) * 5 / 6);
    qDebug() << player->x() << "  " << player->y();
    qDebug() << rect().height();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    Baloon *jet = new Baloon(20);
    scene->addItem(jet);
    jet->setPos(rect().width() * .2, rect().width() * .2);
    qDebug() << jet->pos();
//    Wall * wall = new Wall(150,10);
//    qDebug()<<"added";
//    wall->setPos(rect().width()-150,rect().height()-600);
//    wall->setFlag(QGraphicsItem::ItemIsFocusable);
//    wall->setFocus();
//    scene->addItem(jet);
//    scene->addItem(wall);
    score = new Score;
    score->setPos(this->width - 80, this->height - 60);

    scene->addItem(player);
    scene->addItem(score);


    int rand1 = 10;
    int rand2 = 20;
    int height = 20;
    Wall *walll = new Wall(rand1, height);
    Wall *wallr = new Wall(rand2, height);
    walll->setPos(rect().width() - this->width, rect().height() - this->height);
    wallr->setPos(rect().width() - rand2, rect().height() - this->height);;
    scene->addItem(walll);
    scene->addItem(wallr);




//qDebug()<< qrand();
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(create_enemies()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(create_map()));
    timer->start(1000 / framesPerSecond);
}
/*
void Game::advance() {
    qDebug() << "here";
    this->create_enemies();
}
*/
void Game::create_enemies() {
    int rand = 2;
    EnemyObject *enemy;
    QList < QGraphicsItem * > colliding_items;
    switch (rand) {
        case 1:
            enemy = new Baloon();
            do {
                enemy->setPos(rect().width() * (0.2), rect().height());
                colliding_items = enemy->collidingItems();
            } while (!colliding_items.isEmpty());
            break;
        case 2:
            enemy = new Jet();
            enemy->setPos(rect().width() * (0.2), rect().height());
            break;
        case 3:
            enemy = new Helicopter();
            enemy->setPos(rect().width() * (0.2), rect().height());
            break;
        case 4:
            enemy = new Tanker();
            do {
                enemy->setPos(rect().width() * (0.2), rect().height());
                colliding_items = enemy->collidingItems();
            } while (!colliding_items.isEmpty());
            break;
        default:
            return;
    }
//    player->setFlag(QGraphicsItem::ItemIsFocusable);
  //  player->setFocus();
    scene->addItem(enemy);
}
/*
void Game::drawBackground(QPainter *painter, const QRectF &rect)
{
    QPixmap pixmap(":/images/water.jpg");
    for(double x = 0; x < this->width; x += pixmap.width())
        for(double y = 0; y < this->height; y += pixmap.height())
            painter->drawPixmap(x, y, pixmap.width(), pixmap.height(), pixmap);
    static int num = 1;
    qDebug() << "background over " << num++;
}
*/
void Game::create_map() {
    int rand1 = 10;
    int rand2 = 20;
    int height = 20;
    Wall *walll = new Wall(rand1, height);
    Wall *wallr = new Wall(rand2, height);
    walll->setPos(rect().width() - this->width, rect().height() - this->height);
    wallr->setPos(rect().width() - rand2, rect().height() - this->height);
    scene->addItem(walll);
    scene->addItem(wallr);

}

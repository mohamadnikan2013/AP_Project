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
    setBackgroundBrush(QBrush("blue"));
    Physics::setFps(framesPerSecond);
    MovingObject::screenPhysics().setV(20);
    MovingObject::screenPhysics().setA(10);
    MovingObject::screenPhysics().setMaxV(80);
    MovingObject::screenPhysics().setMinV(10);

    fuelIndicator = new FuelIndicator(framesPerSecond, 90);
    fuelIndicator->setPos(0, this->height - 90);
    scene->addItem(fuelIndicator);

    player = new Player(this->fuelIndicator,this, 80, 10);
    player->setPos(rect().width() / 2 - player->getWidth() / 2, (rect().height() - player->getHeight()) * 5 / 6);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    Wall *walll = new Wall(150, this->height+170);
    Wall *wallr = new Wall(150, this->height+170);
    walll->setPos(rect().width() - this->width, rect().height() - this->height-150);
    wallr->setPos(rect().width() - 150, rect().height() - this->height-150);
    scene->addItem(walll);
    scene->addItem(wallr);

    this->highestWall = walll;


    score = new Score;
    score->setPos(this->width - 80, this->height - 60);
    scene->addItem(score);

    timer = new QTimer();
    enemytimer = new QTimer();
    enemytimer->start(2000);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(create_map()));
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    QObject::connect(enemytimer, SIGNAL(timeout()), this, SLOT(create_enemies()));

    timer->start(1000 / framesPerSecond);
}

void Game::addScore(int x)
{
    this->score->addScore(x);
}

void Game::onFuel()
{
    this->fuelIndicator->onDepotFuel();
}

void Game::offFuel()
{
    this->fuelIndicator->offDepotFuel();
}

Game::~Game()
{
    delete timer;
    delete enemytimer;
    delete menu;
    delete scene;
}
void Game::pause()
{
/*    ispaused = true;
    timer->stop();
    enemytimer->stop();
    menu->show();
    this->hide();*/

    this->game_over();
}

void Game::unPause()
{
    timer->start();
    enemytimer->start();
    ispaused = false;
    menu->hide();
    this->show();
}

void Game::create_enemies() {
    int myrand = qrand()%6;
    int speed = 20+qrand()%70;
    MovingObject *enemy;
    QList < QGraphicsItem * > colliding_items;
    switch (myrand) {
        case 1:
            enemy = new Baloon(speed);
            break;
        case 2:
            enemy = new Jet(speed);
            break;
        case 3:
            enemy = new Helicopter(speed);
            break;
        case 4:
            enemy = new Tanker(speed);
            break;
        case 5:
            enemy = new DepotFuel();
            break;
        default:
            return;
    }
    enemy->setPos(rect().width()-(qrand()%800), rect().height()-this->height);
    this->scene->addItem(enemy);
    if(myrand > 2)
    {
        do {
            enemy->setPos(qrand() %(this->width - 50), rect().height()-this->height);
            colliding_items = enemy->collidingItems();
        } while (!colliding_items.isEmpty());
    }
    qDebug()<< "random " << myrand;
}
void Game::create_map() {
    if(highestWall->y() < -100)
        return;
    int lWidth = 100 + qrand()%150;
    int rWidth = 100 + qrand()%150;
    int height = 50 + qrand() % 100;
    Wall *walll = new Wall(lWidth, height);
    Wall *wallr = new Wall(rWidth, height);
    walll->setPos(0, highestWall->y() - height);
    wallr->setPos(this->width - rWidth, highestWall->y() - height);

    highestWall = walll;
    scene->addItem(walll);
    scene->addItem(wallr);
}


void Game::game_over()
{
    this->scene->clear();
    _panel1 = new QGraphicsRectItem(0,0,800,600);
    _panel1->setBrush(QBrush(QImage(":/images/menu.png")));
    _panel1->setOpacity(0.15);
    this->scene->addItem(_panel1);

    _panel2 = new QGraphicsRectItem(300,200,200,200);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    _panel2->setBrush(brush);
    _panel2->setOpacity(0.75);
    this->scene->addItem(_panel2);

    _gameOvr =new QGraphicsTextItem(QString("GameOver"));
    QFont titleFont("comic sans", 15);
    _gameOvr->setFont(titleFont);
    int tXpos = rect().width()/2 - _gameOvr->boundingRect().width()/2;
    int tYpos = 195;
    _gameOvr->setPos(tXpos,tYpos);
    scene->addItem(_gameOvr);
    _playg = new QPushButton(QString("Play"));
    _playg->setGeometry(rect().width()/2 - 50,225,100,60);
    scene->addWidget(_playg);
//    connect(_playg,SIGNAL(clicked()),this,SLOT(start()));
    _cancelg = new QPushButton(QString("Quit"));
    _cancelg->setGeometry(rect().width()/2 - 50,315,100,60);
    scene->addWidget(_cancelg);
    connect(_cancelg,SIGNAL(clicked()),this,SLOT(close()));

    return;
}

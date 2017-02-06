#include "game.h"
#include <QDebug>
#include <QTimer>
#include <QObject>
Game::Game(int w, int h) : width(w), height(h)
{

    scene = new QGraphicsScene;
    scene->setSceneRect( 0 , 0 , width , height);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width , height);
    setScene(scene);
    player = new Player;
    player->setPos(rect().width()*0.45 ,  rect().height() - player->getHeightScaled());
    qDebug() << rect().height();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    score = new Score;

    scene->addItem(player);
    scene->addItem(score);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000 / 33);

}

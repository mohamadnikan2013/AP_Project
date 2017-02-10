#include "menu.h"

Menu::Menu( QWidget *parent)
{
    game = new Game(this);
    continu = new QPushButton("play");
    newGame = new QPushButton("option");
    quit = new QPushButton("Exit");
    QObject::connect(continu, SIGNAL(clicked()), game, SLOT(unPause()));
    QObject::connect(newGame, SIGNAL(clicked()), this, SLOT(buildNewGame()));
    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(quitGame()));

    layout = new QVBoxLayout;
    layout->addWidget(continu);
    layout->addWidget(newGame);
    layout->addWidget(quit);
    this->setLayout(layout);
    this->hide();
}

void Menu::buildNewGame()
{
    delete game;
    game = new Game;
}

void Menu::quitGame()
{
    delete Game;
    delete this;
    return;
}

#include "menu.h"

Menu::Menu(Game* game,  QWidget *parent)
{
    this->game = game;
    continu = new QPushButton("continu");
    newGame = new QPushButton("new game");
    quit = new QPushButton("Exit");
    QObject::connect(continu, SIGNAL(clicked()), game, SLOT(unPause()));
    QObject::connect(newGame, SIGNAL(clicked()), this, SLOT(buildNewGame()));
    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(quitGame()));

    layout = new QVBoxLayout;
    layout->addWidget(continu);
    layout->addWidget(newGame);
    layout->addWidget(quit);
    this->setLayout(layout);
    game->show();

    this->setVisible(false);
}

Menu::~Menu()
{
    delete layout;
    delete continu;
    delete newGame;
    delete quit;

}

void Menu::buildNewGame()
{
    delete game;
    game = new Game;
}

void Menu::quitGame()
{
    delete game;
    delete this;
    return;
}

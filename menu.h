#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>
#include "game.h"
class Game;

class Menu : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* layout;

    QPushButton* continu;
    QPushButton* newGame;
    QPushButton* quit;

public:
    explicit Menu(QWidget *parent = 0);
public slots:
    void buildNewGame();
    void quitGame();
};

#endif // MENU_H

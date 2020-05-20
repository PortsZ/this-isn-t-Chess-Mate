#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QMouseEvent>
#include "board.h"
#include "tower.h"
#include "bishop.h"
#include "horse.h"
#include "queen.h"
#include <QLabel>
#include <QFont>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QMediaPlayer>


class GameWindow : public QMainWindow
{
    Q_OBJECT
    bool addTowerClicked = false, addBishopClicked = false, addHorseClicked = false, addQueenClicked = false, paintAddableArea=false;
    int boardPosX, boardPosY;

public:  
    GameWindow();
    void setAddTowerClicked(bool state);
    bool getAddTowerClicked();
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *event) override;

    Board *chessBoard;
    Tower *tower;
    Bishop *bishop;
    Horse *horse;
    Queen *queen;

    QPushButton *addTowerButton, *addBishopButton, *addQueenButton, *addHorseButton, *loadGameButton, *saveGameButton, *kageBunshin;
    QFont chesterfield, DashDemo, DashDemo2, GrindAndDeath_Demo;
    QLabel *gameName, *gameNameShadow, *removeLabel, *intro;
    QMediaPlayer *jutsu, *select;

private slots:
    void addTower();
    void addBishop();
    void addHorse();
    void addQueen();

    void handleSaveGameButton();
    void handleSaveAnimation();
    void handleLoadGameButton();
    void handleKageBunshin();
    void songStart();

};

#endif // GAMEWINDOW_H

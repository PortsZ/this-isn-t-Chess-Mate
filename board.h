#ifndef BOARD_H
#define BOARD_H

#include <QPainter>
#include <QPaintEvent>
#include <QString>
#include <vector>
#include "piece.h"
using namespace std;


class Board {

    bool checked=false;
    Board();
    Board(const Board &b);
    Board operator=(Board b);
    static Board *instance;

public:
    vector <Piece *> pieces;
    static Board *getInstance();
    bool hasPiece(int x, int y);
    bool getChecked();
    void setChecked(bool state);
    void insertPiece(Piece *piece);
    void removePiece(int i);

    void drawMap(QPainter &painter);
    void drawAddableArea(QPainter &painter);
};

#endif // BOARD_H

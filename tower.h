#ifndef TOWER_H
#define TOWER_H

#include "piece.h"
#include <QPainter>
#include <QPaintEvent>
#include <QFont>
#include "board.h"

class Tower : public Piece{

public:
    Tower();
    ~Tower();
    Tower(int x, int y);
    int getPosX();
    int getPosY();
    void drawPiece(QPainter &painter);
    void drawMoveableArea(QPainter &painter, Board *board);
    bool movePiece(int x, int y, Board *board);
};

#endif // TOWER_H

#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include <QPainter>
#include <QPaintEvent>
#include <QFont>
#include "board.h"

class Bishop: public Piece{

public:
    Bishop();
    Bishop(int x, int y);
    int getPosX();
    int getPosY();
    void drawPiece(QPainter &painter);
    void drawMoveableArea(QPainter &painter, Board *board);
    bool movePiece(int x, int y, Board *board);
};

#endif // BISHOP_H

#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include <QPainter>
#include <QPaintEvent>
#include <QFont>
#include "board.h"

class Queen : public Piece{

public:
    Queen();
    Queen(int x, int y);
    //void setPiecePos(int x, int y, Board *board);
    int getPosX();
    int getPosY();
    void drawPiece(QPainter &painter);
    void drawMoveableArea(QPainter &painter, Board *board);
    bool movePiece(int x, int y, Board *board);
};

#endif // QUEEN_H

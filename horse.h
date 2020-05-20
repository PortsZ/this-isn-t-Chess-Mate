#ifndef HORSE_H
#define HORSE_H

#include "piece.h"
#include <QPainter>
#include <QPaintEvent>
#include <QFont>
#include "board.h"

class Horse : public Piece{
public:
    Horse();
    Horse(int x, int y);
    int getPosX();
    int getPosY();
    void drawPiece(QPainter &painter);
    void drawMoveableArea(QPainter &painter, Board *board);
    bool movePiece(int x, int y, Board *board);
};

#endif // HORSE_H

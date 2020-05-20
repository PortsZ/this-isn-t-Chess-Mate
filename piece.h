#ifndef PIECE_H
#define PIECE_H
#include <QMessageBox>
#include <QPaintEvent>
#include <QMouseEvent>
#include <string>
using namespace std;

class Board;

class Piece {
protected:
    int posX, posY, type;
    bool visible = false, movement = false, selected=false;
public:
    Piece();
    virtual ~Piece();
    void setVisible(bool state);
    bool getVisible();
    void setMovement(bool state);
    bool getMovement();
    void setSelected(bool state);
    bool getSelected();
    void setType(int state);
    int getType();
    virtual void setPiecePos(int x, int y, Board *board);
    virtual int getPosX();
    virtual int getPosY();
    virtual void drawPiece(QPainter &painter)=0;
    virtual void drawMoveableArea(QPainter &painter, Board *board)=0;
    virtual bool movePiece(int x, int y, Board *board)=0;


};

#endif // PIECE_H

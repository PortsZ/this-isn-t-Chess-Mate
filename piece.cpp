#include "piece.h"
#include "board.h"
#include <QMessageBox>

Piece::Piece()
{

}
Piece::~Piece(){}
int Piece::getPosX(){return 0;}
int Piece::getPosY(){return 0;}

bool Piece::getVisible(){
    return visible;
}
void Piece::setVisible(bool state){
    visible=state;
}

void Piece::setMovement(bool state){
    movement=state;
}
bool Piece::getMovement(){
    return movement;
}

void Piece::setSelected(bool state){
    selected=state;
}
bool Piece::getSelected(){
    return selected;
}

void Piece::setType(int state){
    type=state;
}
int Piece::getType(){
    return type;
}



void Piece::setPiecePos(int x, int y, Board *board){

    if(movePiece(x,y,board)==true){
        if(board->hasPiece(x,y)==true){
            for (unsigned int i=0;i<board->pieces.size();i++) {
                if(board->pieces[i]->getPosX()==x and board->pieces[i]->getPosY()==y and board->pieces[i]->getSelected()==false)
                board->removePiece(int (i));
            }
        }
        posX=x;
        posY=y;
    }
}







#include "queen.h"
#include "piece.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QLabel>
#include <QStandardPaths>
#include <QString>

//------------Constructors-------------------

Queen::Queen() : Piece()
{
    posX=0;
    posY=0;
    setType(4);

}
Queen::Queen(int x, int y) : Piece()
{
    posX=x;
    posY=y;
    setType(4);
}

//-----------------DrawMethods--------------------------

void Queen::drawPiece(QPainter &painter){
    QBrush blackBrush(Qt::black);
    painter.setBrush(blackBrush);
    QString docs=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    painter.drawImage(QRect(100+100*getPosX(), 100+100*getPosY(), 100, 100), QImage(docs.append("/imagens/dama.png")));
}

void Queen::drawMoveableArea(QPainter &painter, Board *board){
    QBrush brush("#69ff61");
    QBrush brushRed(Qt::red);
    QColor enemycolor = Qt::red;
    enemycolor.setAlphaF(0.7);
    QBrush enemy(enemycolor);
    QBrush brushCyan(Qt::cyan);

    painter.setBrush(brush);
    for(int i=0;i<8;i++){
        for (int j=0;j<8;j++) {

            if(movePiece(i, j,board)==true){
                if(board->hasPiece(i, j) and (i!=getPosX() or j!=getPosY())){
                    painter.setBrush(enemy);
                    painter.drawRect(QRect(100+100*i, 100+100*j, 100, 100));
                }else{
                    painter.setBrush(brush);
                    painter.drawRect(QRect(100+100*i, 100+100*j, 100, 100));
                }
            }
        }
        painter.setBrush(brushCyan);
        painter.drawRect(QRect(100+100*getPosX(), 100+100*getPosY(), 100, 100));
    }

    painter.setBrush(brushRed);
    painter.drawRect(QRect(100, 900, 800, 200));



}

//-----------------PiecePosition----------------------

int Queen::getPosX(){
    return posX;
}

int Queen::getPosY(){
    return posY;
}

//------------------MovePiece--------------------------

bool Queen::movePiece(int x, int y, Board *board){


    if(x == getPosX() and y == getPosY())
        return false;


    //ESQUERDA
    if(x<getPosX() and y==getPosY()){
        for(int i = getPosX()-1; i>=0; i--){
            if(board->hasPiece(i, getPosY()) == true and i>x){
                return false;
            }
        }
        return true;
    }

    // DIREITA
    if(getPosX()<x and y==getPosY()){
        for(int i = getPosX()+1; i<8; i++){
            if(board->hasPiece(i, getPosY()) == true and i<x){
                return false;
            }
        }
        return true;
    }

    // CIMA
    if(getPosX()==x and y<getPosY()){
        for(int j = getPosY()-1; j>=0; j--){
            if(board->hasPiece(getPosX(), j) == true and j>y){
                return false;
            }
        }
        return true;
    }

    // BAIXO

    if(getPosX()==x and y>getPosY()){
        for(int j = getPosY()+1; j<8; j++){
            if(board->hasPiece(getPosX(), j) == true and j<y){

                return false;
            }
        }
        return true;
    }

    //--------------------DiagonalEsquerdaSuperior---------------------------------
    if(x<getPosX() and y<getPosY()){
        if((x - y) == (getPosX()-getPosY())){
            for(int i = 1; i<8; i++){
                if((getPosX()-i)>=0 and (getPosY()-i)>=0){
                    if(board->hasPiece((getPosX()-i), (getPosY()-i)) == true and x<(getPosX()-i)){
                        return false;
                    }
                }
            }
            return true;
        }
    }
    //-----------------------------------------------------------------------------

    //--------------------DiagonalEsquerdaInferior---------------------------------
    if(x<getPosX() and y>getPosY()){
        if((x + y) == (getPosX()+getPosY())){
            for(int i = 1; i<8; i++){
                if((getPosX()-i)>=0 and (getPosY()+i)<8){
                    if(board->hasPiece((getPosX()-i), (getPosY()+i)) == true and x<(getPosX()-i))                        {
                        return false;
                    }
                }
            }
            return true;
        }

    }
    //-----------------------------------------------------------------------------

    //--------------------DiagonalDireitaInferior----------------------------------
    if(x>getPosX() and y>getPosY()){
        if((x - y) == (getPosX()-getPosY())){
            for(int i = 1; i<8; i++){
                if((getPosX()+i)<8 and (getPosY()+i)<8){
                    if(board->hasPiece((getPosX()+i), (getPosY()+i)) == true and x>(getPosX()+i))                        {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    //-----------------------------------------------------------------------------

    //--------------------DiagonalDireitaSuperior---------------------------------
    if(x>getPosX() and y<getPosY()){
        if((x + y) == (getPosX()+getPosY())){
            for(int i = 1; i<8; i++){
                if((getPosX()+i)<8 and (getPosY()-i)>=0){
                    if(board->hasPiece((getPosX()+i), (getPosY()-i)) == true and x>(getPosX()+i))                        {
                        return false;
                    }
                }
            }
            return true;
        }

    }
    //-----------------------------------------------------------------------------


    return  false;
}












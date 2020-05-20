#include "tower.h"
#include "piece.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QLabel>
#include <QStandardPaths>
#include <QString>

//------------Constructors-------------------

Tower::Tower() : Piece()
{
    posX=0;
    posY=0;
    setType(1);

}
Tower::~Tower(){}
Tower::Tower(int x, int y) : Piece()
{
    posX=x;
    posY=y;
    setType(1);
}

//-----------------DrawMethods--------------------------

void Tower::drawPiece(QPainter &painter){
    QBrush blackBrush(Qt::black);
    painter.setBrush(blackBrush);
    QString docs=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    painter.drawImage(QRect(100+100*getPosX(), 100+100*getPosY(), 100, 100), QImage(docs.append("/imagens/torre.png")));
}

void Tower::drawMoveableArea(QPainter &painter, Board *board){
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

int Tower::getPosX(){
    return posX;
}

int Tower::getPosY(){
    return posY;
}

//------------------MovePiece--------------------------

bool Tower::movePiece(int x, int y, Board *board){

    // Pra cima --------------------------------------
    if(getPosX()==x and y<getPosY()){
        for(int i=getPosY()-1;i>=0;i--){
            if(board->hasPiece(getPosX(), i)==true and i>y){
                return false;
            }
        }
    }
    //------------------------------------------------

    //Pra-Baixo---------------------------------------
    if(getPosX()==x and y>getPosY()){
        for(int i=getPosY()+1;i<8;i++){
            if(board->hasPiece(getPosX(), i)==true and i<y){
                return false;
            }
        }
    }
    //------------------------------------------------

    //Pra-esquerda------------------------------------
    if(getPosY()==y and x<getPosX()){
        for(int i=getPosX()-1;i>=0;i--){
            if(board->hasPiece(i, getPosY())==true and i>x){
                return false;
            }
        }
    }
    //------------------------------------------------

    //Pra-direita-------------------------------------
    if(getPosY()==y and x>getPosX()){
        for(int i=getPosX()+1;i<8;i++){
            if(board->hasPiece(i, getPosY())==true and i<x){
                return false;
            }
        }
    }
    //------------------------------------------------

    if(x != getPosX() and y != getPosY()){
        return false;
    }

    return true;
}












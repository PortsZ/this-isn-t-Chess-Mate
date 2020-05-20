#include "bishop.h"
#include "piece.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QLabel>
#include <QStandardPaths>
#include <QString>

//------------Constructors-------------------

Bishop::Bishop() : Piece()
{
    posX=0;
    posY=0;
    setType(2);

}
Bishop::Bishop(int x, int y) : Piece()
{
    posX=x;
    posY=y;
    setType(2);
}

//-----------------DrawMethods--------------------------

void Bishop::drawPiece(QPainter &painter){
    QBrush blackBrush(Qt::black);
    painter.setBrush(blackBrush);
    QString docs=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    painter.drawImage(QRect(100+100*getPosX(), 100+100*getPosY(), 100, 100), QImage(docs.append("/imagens/bispo.png")));
}

void Bishop::drawMoveableArea(QPainter &painter, Board *board){
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



int Bishop::getPosX(){
    return posX;
}

int Bishop::getPosY(){
    return posY;
}

//------------------MovePiece--------------------------

bool Bishop::movePiece(int x, int y, Board *board){


    if(x == getPosX() and y == getPosY())
        return false;

    //DIAGONAL ESQUERDA SUPERIOR
    if(x<getPosX() and y<getPosY())
    {
        if((x - y) == (getPosX()-getPosY()))
        {
            for(int i = 1; i<8; i++)
            {
                if((getPosX()-i)>=0 and (getPosY()-i)>=0)
                {
                    if(board->hasPiece((getPosX()-i), (getPosY()-i)) == true and x<(getPosX()-i))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    //DIAGONAL DIREITA INFERIOR
    if(x>getPosX() and y>getPosY())
    {
        if((x - y) == (getPosX()-getPosY()))
        {
            for(int i = 1; i<8; i++)
            {
                if((getPosX()+i)<8 and (getPosY()+i)<8)
                {
                    if(board->hasPiece((getPosX()+i), (getPosY()+i)) == true and x>(getPosX()+i))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    //DIAGONAL ESQUERDA SUPERIOR
    if(x>getPosX() and y<getPosY())
    {
        if((x + y) == (getPosX()+getPosY()))
        {
            for(int i = 1; i<8; i++)
            {
                if((getPosX()+i)<8 and (getPosY()-i)>=0)
                {
                    if(board->hasPiece((getPosX()+i), (getPosY()-i)) == true and x>(getPosX()+i))
                    {
                        return false;
                    }
                }
            }
            return true;
        }

    }


    //DIAGONAL ESQUERDA INFERIOR
    if(x<getPosX() and y>getPosY())
    {
        if((x + y) == (getPosX()+getPosY()))
        {
            for(int i = 1; i<8; i++)
            {
                if((getPosX()-i)>=0 and (getPosY()+i)<8)
                {
                    if(board->hasPiece((getPosX()-i), (getPosY()+i)) == true and x<(getPosX()-i))
                    {
                        return false;
                    }
                }
            }
            return true;
        }

    }

    return  false;
}


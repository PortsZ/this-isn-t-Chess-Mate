#include "horse.h"

#include "piece.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QLabel>
#include <QStandardPaths>
#include <QString>

//------------Constructors-------------------

Horse::Horse() : Piece()
{
    posX=0;
    posY=0;
    setType(3);

}
Horse::Horse(int x, int y) : Piece()
{
    posX=x;
    posY=y;
    setType(3);
}

//-----------------DrawMethods--------------------------

void Horse::drawPiece(QPainter &painter){
    QBrush blackBrush(Qt::black);
    painter.setBrush(blackBrush);
    QString docs=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    painter.drawImage(QRect(100+100*getPosX(), 100+100*getPosY(), 100, 100), QImage(docs.append("/imagens/cavalo.png")));
}

void Horse::drawMoveableArea(QPainter &painter, Board *board){
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



int Horse::getPosX(){
    return posX;
}

int Horse::getPosY(){
    return posY;
}

//------------------MovePiece--------------------------

bool Horse::movePiece(int x, int y, Board *board){

    //L SUPERIOR ESQUERDO EM PE
        if(x>=0 and y>=0)
        {
            if((x==(getPosX()-1))and(y==(getPosY()-2)))
                return true;
        }
        //L SUPERIOR ESQUERDO EM deitado
            if(x>=0 and y>=0)
            {
                if((x==(getPosX()-2))and(y==(getPosY()-1)))
                    return true;
            }


        //L SUPERIOR DIREITO DEITADO
        if(x<8 and y>=0)
        {
            if((x==(getPosX()+2))and(y==(getPosY()-1)))
                return true;
        }

        //L SUPERIOR DIREITO EM PE
        if(x<8 and y>=0)
        {
            if((x==(getPosX()+1))and(y==(getPosY()-2)))
                return true;
        }

        //L INFERIOR ESQUERDO DEITADO
        if(x>=0 and y<8)
        {
            if((x==(getPosX()-2))and(y==(getPosY()+1)))
                return true;
        }


        //L INFERIOR ESQUERDO EM PE
        if(x>=0 and y<8)
        {
            if((x==(getPosX()-1))and(y==(getPosY()+2)))
                return true;
        }

        //L INFERIOR DIREITO DEITADO
        if(x<8 and y<8)
        {
            if((x==(getPosX()+2))and(y==(getPosY()+1)))
                return true;
        }

        //L INFERIOR DIREITO EM PE
        if(x<8 and y<8)
        {
            if((x==(getPosX()+1))and(y==(getPosY()+2)))
                return true;

        }

        return false;
}


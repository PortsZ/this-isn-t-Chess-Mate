#include "board.h"

//--------------Constructor------------------------
Board::Board()
{


}

Board *Board::getInstance(){
    if (instance == NULL)
               instance = new Board();
           return instance;
}

Board *Board::instance = NULL;

//-------------------------------------------------

//---------------PieceManagementMethods---------------------

void Board::insertPiece(Piece *piece){
    pieces.push_back(piece);
    piece->setVisible(true);

}

void Board::removePiece(int i){
    pieces.erase(pieces.begin()+i);
}

//----------------------------------------------------------

//----------------------------------------DrawMethods------------------------------------------------
void Board::drawMap(QPainter &painter){
    QColor darkColor = "#5a0061";
    darkColor.setAlphaF(0.8);
    QColor lightColor = "#ff00e6";
    lightColor.setAlphaF(0.8);
    QBrush light(lightColor);
    QBrush dark(darkColor);
    QPen test("#00eaff");
    test.setWidth(2);
    painter.setPen(test);

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i%2==0) && (j%2==0))
                painter.setBrush(light);
            else if((i%2!=0) && (j%2!=0))
                painter.setBrush(light);
            else {
                painter.setBrush(dark);

            }
            painter.drawRect(QRect(100+100*i, 100+100*j, 100, 100));

        }
    }

}

void Board::drawAddableArea(QPainter &painter){//desenha a area de pecas que pode adicionar
    QBrush b1("#ff00b7");

    for(int i=0;i<8;i++){
        for (int j=0;j<8;j++) {
            if(hasPiece(i, j)==false){
                painter.setBrush(b1);
                painter.drawRect(QRect(100+100*i, 100+100*j, 100, 100));
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------

//-------------------VerificationMethods------------------------
bool Board::hasPiece(int x, int y){
    for(unsigned int i=0;i<pieces.size();i++){
        if(pieces[i]->getPosX()==x and pieces[i]->getPosY()==y) {
            return true;
        }
    }
    return false;
}

bool Board::getChecked(){
    return checked;
}

void Board::setChecked(bool state){
    checked=state;
}
//------------------------------------------------------------------

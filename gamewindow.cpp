#include "gamewindow.h"
#include "board.h"
#include <QPushButton>
#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStandardPaths>
#include <QPixmap>
#include <QMediaPlayer>
#include <QMultimedia>
#include <QtMultimediaWidgets>
#include <windows.h>

#define OOB 404

GameWindow::GameWindow() : QMainWindow(){

    chessBoard = Board::getInstance();
    //---------Window-------------
    QString assets = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    assets.append("/imagens/background.png");
    QPixmap background(assets);
    this->setFixedSize(1920,1080);
    background = background.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
    //----------------------------


    //------------LOGO------------

    QFont chesterfield("chesterfield");
    chesterfield.setPixelSize(50);
    QFont GrindAndDeath_Demo("GrindAndDeath_Demo");
    GrindAndDeath_Demo.setPixelSize(50);
    QFont DashDemo("DashDemo");
    DashDemo.setPixelSize(35);
    QFont DashDemo2("DashDemo");
    DashDemo2.setPixelSize(36);

    //----------------------------
    gameNameShadow = new QLabel("CHESS MATE", this);
    gameNameShadow->setStyleSheet(
                "color: #8500ad;"

                );
    gameNameShadow->setAlignment(Qt::AlignLeft);
    gameNameShadow->setFont(DashDemo2);
    gameNameShadow->setGeometry(434, 11, 200, 55);
    //----------------------------

    gameName = new QLabel("CHESS MATE", this);
    gameName->setStyleSheet(
                "color: #fff;"
                );
    gameName->setAlignment(Qt::AlignLeft);
    gameName->setFont(DashDemo);
    gameName->setGeometry(435, 10, 200, 50);

    //----------------------------



    //Buttons
    //------------------------------------------------------------------------------------
    loadGameButton = new QPushButton("Load game", this);
    loadGameButton->setStyleSheet(
                "background-color: #00eaff;"
                "border-width: 2px;"
                "border-style: solid;"
                "border-color: #ff00e6;"
                "border-radius: 5px;"
                "font-weight: bold;"
                "font-size: 18px;"
                );
    loadGameButton->setFont(GrindAndDeath_Demo);
    loadGameButton->setGeometry(270, 35, 110, 50);
    connect(loadGameButton, SIGNAL (released()), this, SLOT (handleLoadGameButton()));
    //------------------------------------------------------------------------------------
    saveGameButton = new QPushButton("Save game", this);
    saveGameButton->setStyleSheet(
                "background-color: #00eaff;"
                "border-width: 2px;"
                "border-style: solid;"
                "border-color: #ff00e6;"
                "border-radius: 5px;"
                "font-weight: bold;"
                "font-size: 18px;"
                );
    saveGameButton->setGeometry(660, 35, 110, 50);
    saveGameButton->setFont(GrindAndDeath_Demo);
    connect(saveGameButton, SIGNAL(pressed()), this, SLOT (handleSaveAnimation()));
    connect(saveGameButton, SIGNAL (released()), this, SLOT (handleSaveGameButton()));
    //------------------------------------------------------------------------------------


    //--------RemovePieceLabel------------------------------

    removeLabel=new QLabel("Remove Area", this);
    removeLabel->setGeometry(440, 900, 0, 0);
    removeLabel->setStyleSheet("background-color: #ff0000;");
    removeLabel->setAlignment(Qt::AlignCenter);
    chesterfield.setPixelSize(50);
    removeLabel->setFont(DashDemo);


    //------------------------------------------------------

    //-------------------BUTTON ADD TOWER--------------
    addTowerButton = new QPushButton("ADD TOWER", this);
    addTowerButton->setStyleSheet(
                "background-color: #00eaff;"
                "border-width: 2px;"
                "border-style: solid;"
                "border-color: #ff00e6;"
                "border-radius: 5px;"
                "font-weight: bold;"
                "font-size: 18px;"
                );
    addTowerButton->setGeometry(1000, 100, 120, 50);
    addTowerButton->setFont(GrindAndDeath_Demo);
    connect(addTowerButton, SIGNAL (released()), this, SLOT(addTower()));

    //-------------------------------------------------------
    //-------------------BUTTON ADD BISHOP--------------
    addBishopButton = new QPushButton("ADD BISHOP", this);
    addBishopButton->setStyleSheet(
                "background-color: #00eaff;"
                "border-width: 2px;"
                "border-style: solid;"
                "border-color: #ff00e6;"
                "border-radius: 5px;"
                "font-weight: bold;"
                "font-size: 18px;"
                );
    addBishopButton->setGeometry(1000, 200, 120, 50);
    addBishopButton->setFont(GrindAndDeath_Demo);
    connect(addBishopButton, SIGNAL (released()), this, SLOT(addBishop()));

    //-------------------------------------------------------
    //-------------------BUTTON ADD QUEEN--------------
    addQueenButton = new QPushButton("ADD QUEEN", this);
    addQueenButton->setStyleSheet(
                "background-color: #00eaff;"
                "border-width: 2px;"
                "border-style: solid;"
                "border-color: #ff00e6;"
                "border-radius: 5px;"
                "font-weight: bold;"
                "font-size: 18px;"
                );
    addQueenButton->setGeometry(1000, 400, 120, 50);
    addQueenButton->setFont(GrindAndDeath_Demo);
    connect(addQueenButton, SIGNAL (released()), this, SLOT(addQueen()));

    //-------------------------------------------------------
    //-------------------BUTTON ADD HORSE--------------
    addHorseButton = new QPushButton("ADD HORSE", this);
    addHorseButton->setStyleSheet(
                "background-color: #00eaff;"
                "border-width: 2px;"
                "border-style: solid;"
                "border-color: #ff00e6;"
                "border-radius: 5px;"
                "font-weight: bold;"
                "font-size: 18px;"
                );
    addHorseButton->setGeometry(1000, 300, 120, 50);
    addHorseButton->setFont(GrindAndDeath_Demo);
    connect(addHorseButton, SIGNAL (released()), this, SLOT(addHorse()));

    //-------------------BUTTONKAGEBUNSHIN--------------
    kageBunshin = new QPushButton("Secret Jutsu!", this);
    kageBunshin->setStyleSheet(
                "background-color: #00eaff;"
                "border-width: 2px;"
                "border-style: solid;"
                "border-color: #ff00e6;"
                "border-radius: 5px;"
                "font-weight: bold;"
                "font-size: 18px;"
                );
    jutsu = new QMediaPlayer(this);
    select= new QMediaPlayer(this);
    kageBunshin->setGeometry(1000, 500, 120, 50);
    kageBunshin->setFont(GrindAndDeath_Demo);
    connect(kageBunshin, SIGNAL (pressed()), this, SLOT(songStart()));


    //-------------------------------------------------------
}

//-----------------------------------------------
void GameWindow::addTower(){
    addTowerClicked=true;
    paintAddableArea=true;
    addTowerButton->setGeometry(1015, 110, 100, 35);
    QString assets = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    select->setMedia(QUrl::fromLocalFile(assets.append("/imagens/select.mp3")));
    select->setVolume(30);
    select->play();
    this->update();
}

void GameWindow::addBishop(){
    addBishopClicked=true;
    paintAddableArea=true;
    addBishopButton->setGeometry(1015, 210, 100, 35);
    QString assets = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    select->setMedia(QUrl::fromLocalFile(assets.append("/imagens/select.mp3")));
    select->setVolume(30);
    select->play();
    this->update();
}

void GameWindow::addHorse(){
    addHorseClicked=true;
    paintAddableArea=true;
    addHorseButton->setGeometry(1015, 310, 100, 35);
    QString assets = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    select->setMedia(QUrl::fromLocalFile(assets.append("/imagens/select.mp3")));
    select->setVolume(30);
    select->play();
    this->update();
}

void GameWindow::addQueen(){
    addQueenClicked=true;
    paintAddableArea=true;
    addQueenButton->setGeometry(1015, 410, 100, 35);
    QString assets = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    select->setMedia(QUrl::fromLocalFile(assets.append("/imagens/select.mp3")));
    select->setVolume(30);
    select->play();
    this->update();
}

void GameWindow::handleSaveAnimation(){
    saveGameButton->setGeometry(670, 40, 100, 35);
}
//-----------------------------------------------

void GameWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    chessBoard->drawMap(painter);

    //---------------------------addableArea----------------------
    if(paintAddableArea==true){
        chessBoard->drawAddableArea(painter);
        paintAddableArea=false;
    }
    //------------------------------------------------------------

    //-------------------MovePiece--------------------------------
    if(chessBoard->getChecked()==true){
        for(unsigned int i=0;i<chessBoard->pieces.size();i++){
            if(chessBoard->pieces[i]->getMovement()==true){
                chessBoard->pieces[i]->drawMoveableArea(painter, chessBoard);
                chessBoard->pieces[i]->drawPiece(painter);
                removeLabel->setGeometry(400, 950, 200, 50);
                this->update();
            }
        }

    }
    //------------------------------------------------------------

    //----------------------drawPiecesOnTheBoard------------------
    for(unsigned int i=0;i<chessBoard->pieces.size();i++){
        if(chessBoard->pieces[i]->getVisible() == true){
            chessBoard->pieces[i]->drawPiece(painter);
        }
    }

}

void GameWindow::mousePressEvent(QMouseEvent *event){
    QWidget::mousePressEvent(event);


    boardPosX = event->x();
    boardPosY = event->y();

    boardPosX = (boardPosX/100)-1;
    boardPosY = (boardPosY/100)-1;

    //------------------------??--------------------------
    if((boardPosX==3 or boardPosX==4) and (boardPosY==-1 or boardPosY==-2)){
        chessBoard->pieces.clear();
    }
    //----------------------------------------------------

    //-------------------addTheTowerToBoard-----------------------------------

    if(addTowerClicked==true){

        if(boardPosX > 7 || boardPosX < 0 || boardPosY > 7 || boardPosY < 0){
            QMessageBox err;
            err.setText("Can't put piece out of the chess board");
            err.exec();
            addTowerButton->setGeometry(1000, 100, 120, 50);
            addTowerClicked=false;
            return;
        }

        if(chessBoard->hasPiece(boardPosX, boardPosY)==false){
            tower = new Tower(boardPosX, boardPosY);
            chessBoard->insertPiece(tower);
            addTowerClicked=false;
            addTowerButton->setGeometry(1000, 100, 120, 50);
            this->update();
            boardPosX=8;
            boardPosY=8;
        }else{
            QMessageBox pecaExistente;
            pecaExistente.setText("already has a piece in here");
            pecaExistente.exec();
            addTowerClicked=false;
            addTowerButton->setGeometry(1000, 100, 120, 50);
            return;
        }
    }

    //------------------------------------------------------------------------

    //-------------------addTheBishopToBoard-----------------------------------

    if(addBishopClicked==true){

        if(boardPosX > 7 || boardPosX < 0 || boardPosY > 7 || boardPosY < 0){//do trycatch
            QMessageBox err;
            err.setText("Can't put piece out of the chess board");
            err.exec();
            addBishopClicked=false;
            addBishopButton->setGeometry(1000, 200, 120, 50);
            return;
        }

        if(chessBoard->hasPiece(boardPosX, boardPosY)==false){
            bishop = new Bishop(boardPosX, boardPosY);
            chessBoard->insertPiece(bishop);
            addBishopClicked=false;
            addBishopButton->setGeometry(1000, 200, 120, 50);
            this->update();
            boardPosX=8;
            boardPosY=8;
        }else{
            QMessageBox pecaExistente;
            pecaExistente.setText("already has a piece in here");
            pecaExistente.exec();
            addBishopClicked=false;
            addBishopButton->setGeometry(1000, 200, 120, 50);
            return;
        }
    }

    //------------------------------------------------------------------------

    //-------------------addTheHorseToBoard-----------------------------------

    if(addHorseClicked==true){

        if(boardPosX > 7 || boardPosX < 0 || boardPosY > 7 || boardPosY < 0){//do trycatch
            QMessageBox err;
            err.setText("Can't put piece out of the chess board");
            addHorseButton->setGeometry(1000, 300, 120, 50);
            err.exec();
            addHorseClicked=false;
            return;
        }

        if(chessBoard->hasPiece(boardPosX, boardPosY)==false){
            horse = new Horse(boardPosX, boardPosY);
            chessBoard->insertPiece(horse);
            addHorseButton->setGeometry(1000, 300, 120, 50);
            addHorseClicked=false;
            this->update();
            boardPosX=8;
            boardPosY=8;
        }else{
            QMessageBox pecaExistente;
            pecaExistente.setText("already has a piece in here");
            pecaExistente.exec();
            addHorseButton->setGeometry(1000, 300, 120, 50);
            addHorseClicked=false;
            return;
        }
    }

    //------------------------------------------------------------------------

    //-------------------addTheQueenToBoard-----------------------------------

    if(addQueenClicked==true){

        try {
            if(boardPosX > 7 || boardPosX < 0 || boardPosY > 7 || boardPosY < 0)
                throw OOB;
        } catch (int error) {
            if(error==OOB){
                QMessageBox err;
                err.setText("Can't put piece out of the chess board");
                err.exec();
                addQueenClicked=false;
                addQueenButton->setGeometry(1000, 400, 120, 50);
                return;
            }

        }


        if(chessBoard->hasPiece(boardPosX, boardPosY)==false){
            queen = new Queen(boardPosX, boardPosY);
            chessBoard->insertPiece(queen);
            addQueenClicked=false;
            addQueenButton->setGeometry(1000, 400, 120, 50);
            this->update();
            boardPosX=8;
            boardPosY=8;
        }else{
            QMessageBox pecaExistente;
            pecaExistente.setText("already has a piece in here");
            pecaExistente.exec();
            addQueenClicked=false;
            addQueenButton->setGeometry(1000, 400, 120, 50);
            return;
        }
    }

    //------------------------------------------------------------------------

    //-------MovPiece-Start---------------------------------------------------------------------
    if(chessBoard->getChecked()==false and chessBoard->hasPiece(boardPosX, boardPosY)){
        chessBoard->setChecked(true);
        for(unsigned int i=0;i<chessBoard->pieces.size();i++){
            if(chessBoard->pieces[i]->getPosX()==boardPosX and chessBoard->pieces[i]->getPosY()==boardPosY){
                chessBoard->pieces[i]->setSelected(true);
                chessBoard->pieces[i]->setMovement(true);
            }
        }

    }
    else{
        for(unsigned int i=0;i<chessBoard->pieces.size();i++){
            if(chessBoard->pieces[i]->getMovement()==true ){
                chessBoard->pieces[i]->setMovement(false);

                if(boardPosX<0 or boardPosY<0 or boardPosX>=8){
                    QMessageBox err;
                    err.setText("Can't move piece out of the board");
                    err.exec();

                }
                else if(boardPosX>=0 and boardPosX <=7 and boardPosY>7 and boardPosY<=9 ){
                    chessBoard->removePiece(int (i));
                    this->update();
                }


                else{
                    chessBoard->pieces[i]->setPiecePos(boardPosX, boardPosY, chessBoard);
                    chessBoard->pieces[i]->setSelected(false);

                }
            }
            chessBoard->setChecked(false);
            removeLabel->setGeometry(440, 1000, 0, 0);
        }
    }
    //--------MovPiece-End----------------------------------------------------------------------
    this->update();
}


void GameWindow::handleSaveGameButton(){
    saveGameButton->setGeometry(660, 35, 110, 50);
    QString fileName= QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    fileName.append("/gamesave.cmdata");

    FILE *saveFile;
    const char *aux = (const char*)malloc(fileName.size()*sizeof (char));
    aux = fileName.toStdString().c_str();

    saveFile = fopen(aux, "w+");


    for (int i=0;i<8;i++) {
        for(int j=0;j<8;j++){
            if(chessBoard->hasPiece(i, j)==true){
                for(unsigned int k=0;k<chessBoard->pieces.size();k++){
                    if(chessBoard->pieces[k]->getPosX()==i and chessBoard->pieces[k]->getPosY()==j)
                        fprintf(saveFile,"%d", chessBoard->pieces[k]->getType());
                }
            }
            else{
                fprintf(saveFile,"%d", 0);
            }
        }
    }

    fclose(saveFile);
    QMessageBox savedGame;
    savedGame.setGeometry(750,35,500,500);
    savedGame.setText("Game Saved in /Documents/gamesave.cmdata!");
    savedGame.exec();

}

void GameWindow::handleLoadGameButton(){
    QString docPath= QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString fileName = QFileDialog::getOpenFileName(this, "Load Game", docPath.append("/gamesave.cmdata"), "ChessMate Game save (*.cmdata)");
    const char *aux = (const char*)malloc(fileName.size()*sizeof (char));
    aux = fileName.toStdString().c_str();
    FILE *loadFile;
    loadFile = fopen(aux, "r");

    if (loadFile!=nullptr){
        chessBoard->pieces.clear();

        for(int i=0;i<8;i++){
            for(int j=0;j<8; j++){

                int pieceTest=fgetc(loadFile);
                switch (pieceTest) {
                case '0':
                    break;
                case '1':
                    tower = new Tower(i, j);
                    chessBoard->insertPiece(tower);
                    this->update();
                    break;
                case '2':
                    bishop = new Bishop(i, j);
                    chessBoard->insertPiece(bishop);
                    this->update();
                    break;
                case '3':
                    horse = new Horse(i, j);
                    chessBoard->insertPiece(horse);
                    this->update();
                    break;
                case '4':
                    queen = new Queen(i, j);
                    chessBoard->insertPiece(queen);
                    this->update();
                    break;
                default:
                    break;
                }
            }
        }


    }
    else{
        QMessageBox err;
        err.setText("Save is Empty");
        err.setGeometry(100, 35, 80, 30);
        err.exec();
    }
    fclose(loadFile);
}

void GameWindow::songStart(){
    QString assets = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    jutsu->setMedia(QUrl::fromLocalFile(assets.append("/imagens/jutsu.mp3")));
    jutsu->setVolume(50);
    jutsu->play();
    for(unsigned int k=0;k<chessBoard->pieces.size();k++){
        if(chessBoard->pieces[k]->getType()==4){
            handleKageBunshin();
            break;
        }else{
            continue;
        }
    }
}

void GameWindow::handleKageBunshin(){
    Sleep(4550);
    chessBoard->pieces.clear();


    for(int i=0;i<8;i++){
        for(int j=0;j<8; j++){
            queen = new Queen(i, j);
            chessBoard->insertPiece(queen);
            this->update();
        }
    }


}


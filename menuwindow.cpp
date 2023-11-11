#include "menuwindow.h"
#include "gamewindow.h"
#include <QFont>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QString>
//#include <windows.h>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <synchapi.h>

MenuWindow::MenuWindow(QWidget *parent) : QMainWindow(parent){
    QFont chesterfield("chesterfield");
    chesterfield.setPixelSize(50);
    QFont GrindAndDeath_Demo("GrindAndDeath_Demo");
    GrindAndDeath_Demo.setPixelSize(50);
    QFont DashDemo("DashDemo");
    DashDemo.setPixelSize(50);
    QFont DashDemo2("DashDemo");
    DashDemo2.setPixelSize(51);


    this->setFixedSize(800, 700);
    //---------Window-------------
    QString assets = QDir::currentPath() + "/assets";
    assets.append("/background.png");
    QPixmap background(assets);
    background = background.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    //----------------------------

    //----------------------------------------Definicao-da-janela-e-fonte----------------

    //-----------------------------------------LOGO---------------------------------------
    gameNameShadow = new QLabel("CHESS MATE", this);
    gameNameShadow->setStyleSheet(
                "color: #8500ad;"

                );
    gameNameShadow->setAlignment(Qt::AlignCenter);
    gameNameShadow->setFont(DashDemo2);
    gameNameShadow->setGeometry(254, 253, 300, 76);

    //-----------------------------------------     ---------------------------------------
    gameName = new QLabel("CHESS MATE", this);
    gameName->setStyleSheet(
                "color: #fff;"
                );
    gameName->setGeometry(250, 250, 300, 75);
    gameName->setAlignment(Qt::AlignCenter);
    gameName->setFont(DashDemo);

    //-----------------------------------------LOGO---------------------------------------

    StartGameButton = new QPushButton("Start Game", this);
    StartGameButton->setFont(GrindAndDeath_Demo);
    StartGameButton->setStyleSheet(
                "background-color: #00eaff;"
                "border-width: 2px;"
                "border-style: solid;"
                "border-color: #ff00e6;"
                "border-radius: 5px;"
                "font-weight: bold;"
                "font-size: 30px;"
                );
    StartGameButton->setGeometry(300, 395, 200, 70);
    connect(StartGameButton, SIGNAL (pressed()), this, SLOT (handleAnimations()));
    connect(StartGameButton, SIGNAL (released()), this, SLOT (handleNewGameButton()));
//---------------------------------------------------------------------------------------




}

void MenuWindow::handleAnimations(){
    StartGameButton->setGeometry(315, 410, 175, 60);

}

void MenuWindow::handleNewGameButton(){
    StartGameButton->setGeometry(300, 395, 200, 70);
    playOP();
}
void MenuWindow::playOP(){
    QString assetsPath = QDir::currentPath() + "/assets";
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(assetsPath.append("/op.mp3")));
    audioOutput->setVolume(30);
    player->play();


    startGame();
}
void MenuWindow::startGame(){
    Sleep(2500);
    GameWindow *newGame = new GameWindow;
    newGame->showFullScreen();
}

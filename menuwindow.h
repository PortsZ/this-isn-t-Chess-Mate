#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QFileDialog>
#include <QString>

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
     explicit MenuWindow(QWidget *parent = nullptr);
    void startGame();
private:
    QFont chesterfield;
    QFont DashDemo, DashDemo2, GrindAndDeath_Demo;
    QLabel *gameName, *gameNameShadow;
    QPushButton *StartGameButton;
private slots:
    void handleNewGameButton();
    void handleAnimations();
    void playOP();
};

#endif // MENUWINDOW_H

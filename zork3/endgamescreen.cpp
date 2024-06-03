#include "endgamescreen.h"
#include "ui_endgamescreen.h"
#include "timer.h"
#include <iostream>
using namespace std;

endGameScreen::endGameScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::endGameScreen)
{
    ui->setupUi(this);
    isGameOver = false;
}

endGameScreen::~endGameScreen()
{
    delete ui;
}


void endGameScreen:: setScreen(bool won)
{
    if(!isGameOver){
    if(won){
        QPixmap backgroundImage(":/ISEFreedom.png");
        ui->label->setPixmap(backgroundImage);
        ui->label->setScaledContents(true);
        isGameOver = true;
    }
    else{

        QPixmap backgroundImage(":/ISEDishwasher.png");
        ui->label->setPixmap(backgroundImage);
        ui->label->setScaledContents(true);
        isGameOver = true;

    }}



}
void endGameScreen::closeEvent(QCloseEvent *event) {
    // Perform any necessary cleanup or state saving here

    // Exit the application
    QApplication::exit();

    // Call the base class implementation
    QWidget::closeEvent(event);
}


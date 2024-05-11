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
}

endGameScreen::~endGameScreen()
{
    delete ui;
}

void endGameScreen::handleTimerUp(){
    setScreen(false);
}






void endGameScreen:: setScreen(bool won)
{
    if(won){
        cout<<"WON"<<endl;
        // ui->label->setStyleSheet("{background-color:red}");
        //QPixmap backgroundImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/Keycard.png");

        QPixmap backgroundImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/gameWon.jpg");
        ui->label->setPixmap(backgroundImage);
        ui->label->setScaledContents(true);


    }
    else{

        QPixmap backgroundImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/gameLost.jpg");
        ui->label->setPixmap(backgroundImage);
        ui->label->setScaledContents(true);

    }
    // this->show();
    // mainWindow->game->hide();

}



// #include "endgamescreen.h"
// #include "ui_endgamescreen.h"
// #include "timer.h"

// endGameScreen::endGameScreen(QWidget *parent, Timer *timer)
// {
//     ui->setupUi(this);
//     connect(timer, &Timer::timeEnded, this, &endGameScreen::handleTimerUp());
// }

// endGameScreen::~endGameScreen()
// {
//     delete ui;
// }

// void endGameScreen::handleTimerUp(){
//     setScreen(false);
// }






// void endGameScreen:: setScreen(bool won)
// {
//     if(won){
//         QPixmap backgroundImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/gameWon.jpg");
//         ui->label->setPixmap(backgroundImage);
//         ui->label->setScaledContents(true);


//     }
//     else{

//         QPixmap backgroundImage("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/gameLost.jpg");
//         ui->label->setPixmap(backgroundImage);
//         ui->label->setScaledContents(true);

//     }
//     this->show();
//     // mainWindow->game->hide();

// }



#include "endgamescreen.h"
#include "ui_endgamescreen.h"

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

void endGameScreen:: setScreen(std::string path){
    QPixmap label(QString::fromStdString(path));
}

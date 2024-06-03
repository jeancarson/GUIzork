#include "guide.h"
#include "ui_guide.h"
#include <QLayout>
#include "endgamescreen.h"
//this is done like this so the map is using the same Gamesetup object as the main game window, ie, it has access to current room
//In time will probably make maingamewindow do the same, and game set up is instansiated form mainwindow

Guide::Guide(GameSetUp *gameSetup, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Guide)
    , m_gameSetup(gameSetup)
    , parent(parent)
{
    ui->setupUi(this);
    setLocationYOUareHERE();

    timerText = gameSetup->getTimer();

    connect(timerText, &Timer::timeUpdated, this, &Guide::updateTimerDisplay);
    connect(timerText, &Timer::timeEnded, this, &Guide::handleTimerEnded);

    updateTimerDisplay();
}




Guide::~Guide()
{
    delete ui;
}
void Guide::updateTimerDisplay() {
    ui->TimerDisplay->display(timerText->timeLeft);
}



void Guide::handleTimerEnded(){
    this->hide();
    }

void Guide::updateBackgroundImage(){
    std::array<int, 3> floor = m_gameSetup->getCurrentRoom()->getCoordinates();
    QPixmap backgroundImage;

    switch (floor[2]){
    case 0:
        backgroundImage = QPixmap(QString::fromStdString(":/groundfloormap.png"));
        break;
    case 1:
        backgroundImage = QPixmap(QString::fromStdString(":/ISEFloor1Map.png"));
        break;
    case 2:
    default:
        // Handle default case if necessary
        break;
    }

    ui->BackgroundImage->setPixmap(backgroundImage);
    ui->BackgroundImage->setScaledContents(true);
}


void Guide :: setLocationYOUareHERE(){
    int xCoordinate = m_gameSetup->getCurrentRoom()->getCoordinates()[0];
    int yCoordinate = m_gameSetup ->getCurrentRoom()->getCoordinates()[1];
    ui->DOT->setGeometry(xCoordinate, yCoordinate, 30, 30);
}

void Guide::on_CloseGuide_clicked()
{
    parent->show();
    this->hide();
}


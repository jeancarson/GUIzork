#include "guide.h"
#include "ui_guide.h"
#include "gamesetup.h"

//this is done like this so the map is using the same Gamesetup object as the main game window, ie, it has access to current room


//In time will probably make maingamewindow do the same, and game set up is instansiated form mainwindow

Guide::Guide(GameSetUp *gameSetup, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Guide)
    , m_gameSetup(gameSetup) // Initialize m_gameSetup member variable
{
    ui->setupUi(this);
}



Guide::~Guide()
{
    delete ui;
}

void Guide::updateBackgroundImage(){
    std::array<int, 3> floor = m_gameSetup->getCurrentRoom()->getCoordinates();
    QPixmap backgroundImage;

    switch (floor[2]){
    case 0:
        backgroundImage = QPixmap(QString::fromStdString("path to floor 0")); // Load image into QPixmap
        break;
    case 1:
        backgroundImage = QPixmap(QString::fromStdString("path to floor 1")); // Load image into QPixmap
        break;
    case 2:
        backgroundImage = QPixmap(QString::fromStdString("path to floor 2")); // Load image into QPixmap
        break;
    default:
        // Handle default case if necessary
        break;
    }

    ui->BackgroundImage->setPixmap(backgroundImage);
    ui->BackgroundImage->setScaledContents(true);

}
void Guide :: setLocationYOUareHERE(){

}

// void mapa:: setLocationYOUareHERE(){
//     //there is a label called DOT - we want to set the location of the dot
//     int xCoordinate = currentRoom->getCoordinates[0];
//     int yCoordinate = currentRoom->getCoordinates[1];
//     DOT set location (xCoordinate, YCoordinate);
// }

// void mapa::updateBackgroundImage() {
//     int floor = gameSetUp->getCurrentRoom()->getCordinates[2];
//     switch (floor){
//     case 0:
//         QPixmap backgroundImage(QString::fromStdString("path to floor 0")); // Load image into QPixmap
//     case 1:
//         QPixmap backgroundImage(QString::fromStdString("path to floor 1")); // Load image into QPixmap
//     case 2:
//         QPixmap backgroundImage(QString::fromStdString("path to floor 2")); // Load image into QPixmap

//     }
//     ui->label->setPixmap(backgroundImage);
//     ui->label->setScaledContents(true);
// }

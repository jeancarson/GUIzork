#include "guide.h"
#include "ui_guide.h"
#include "gamesetup.h"

//this is done like this so the map is using the same Gamesetup object as the main game window, ie, it has access to current room


//In time will probably make maingamewindow do the same, and game set up is instansiated form mainwindow

Guide::Guide(GameSetUp *gameSetup, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Guide)
    , m_gameSetup(gameSetup)
    , parent(parent) // Initialize parent member variable
{
    ui->setupUi(this);
    setLocationYOUareHERE();
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
        backgroundImage = QPixmap(QString::fromStdString("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/guideLevel1.jpg")); // Load image into QPixmap
        break;
    case 1:
        backgroundImage = QPixmap(QString::fromStdString("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/guideLevel2.png")); // Load image into QPixmap
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
    /*
     *
     * Coordinates = currentRoom.getCoordinates();
     * DOT.location = (coordinates[0], coordinates[1];
     *
     * */
}






void Guide::on_CloseGuide_clicked()
{
    parent->show();
    this->hide();
}


#include "maingamewindow.h"
#include "ui_maingamewindow.h"
#include "gamesetup.h"
#include <QWidget>

mainGameWindow::mainGameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainGameWindow)
{
    ui->setupUi(this);


    gameSetup = new GameSetUp(); // Initialize GameSetUp instance
    gameSetup->createRooms();

    updateBackgroundImage();}

mainGameWindow::~mainGameWindow()
{
    delete ui;
    delete gameSetup;
}



void mainGameWindow::updateBackgroundImage() {
    // Get the path to the image from the current room
    string path = gameSetup->getCurrentRoom().getPathToImage();
    QPixmap backgroundImage(QString::fromStdString(path)); // Load image into QPixmap

    // Set the QPixmap as the label's pixmap
    ui->label->setPixmap(backgroundImage);
    ui->label->setScaledContents(true); // Optional: Scale the image to fit the label
}


void mainGameWindow::on_inventoryToggle_clicked()
{
    qDebug() << "Toggle button clicked";
    if (InventoryWidget->isVisible()){
        qDebug() << "InventoryWidget is visible, hiding...";
        InventoryWidget->hide();
    }
    else{
        qDebug() << "InventoryWidget is not visible, showing...";
        InventoryWidget->show();
    }
}
// Function to update background image

void mainGameWindow::on_NORTH_clicked()
{
    //call go() function with parameter "NORTH"
    //this might be currentroom.go("NORTH")
    //or move
    //idk
    gameSetup->move("north");
    updateBackgroundImage();



}


void mainGameWindow::on_WEST_clicked()
{
    //call go() function with parameter "WEST"
    gameSetup ->move ("west");
    updateBackgroundImage();
}


void mainGameWindow::on_SOUTH_clicked()
{
    //call go() function with parameter "SOUTH"
    gameSetup -> move ("south");
    updateBackgroundImage();


}
//set checks here to make sure that direction is not null - if it is, dont let that button do anything



void mainGameWindow::on_EAST_clicked()
{
    //call go() function with parameter "EAST"
    gameSetup -> move ("east");
    updateBackgroundImage();

}




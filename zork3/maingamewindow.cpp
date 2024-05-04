#include "maingamewindow.h"
#include "ui_maingamewindow.h"
#include "gamesetup.h"
#include <QWidget>
#include "guide.h"
#include <iostream>
using namespace std;
mainGameWindow::mainGameWindow(QWidget *parent, GameSetUp *preGameSetup)
    : QMainWindow(parent)
    , ui(new Ui::mainGameWindow)
{
    ui->setupUi(this);
    // Ensure preGameSetup is not null before assigning it to gameSetup
    if (preGameSetup == nullptr) {
        cout <<"GAMESET UP IS NULL";
    }
    cout<<"BEFORE INITIALISNG SETUP"<<endl;
    gameSetup = preGameSetup; // Initialize GameSetUp instance
    cout<<gameSetup->getCurrentRoom()->getPathToImage()<<endl;

    cout<<"AFTER INITIALISING SETUP"<<endl;
    //Problem 1 - getting path to image
    //Problem 2 -> getting exits//something in move method
    cout<<gameSetup->getCurrentRoom()->getPathToImage()<<endl;
//     gameSetup->createRooms();
    updateBackgroundImage();
}


mainGameWindow::~mainGameWindow()
{
    delete ui;
    //commenting this out for debugging
    // delete gameSetup;
}



void mainGameWindow::updateBackgroundImage() {
    string path = gameSetup->getCurrentRoom()->getPathToImage();
    QPixmap backgroundImage(QString::fromStdString(path)); // Load image into QPixmap

    ui->label->setPixmap(backgroundImage);
    ui->label->setScaledContents(true);
    setButtonColor(ui->NORTH, gameSetup->getCurrentRoom()->getNextRoom("north"));
    setButtonColor(ui->WEST, gameSetup->getCurrentRoom()->getNextRoom("west"));
    setButtonColor(ui->EAST, gameSetup->getCurrentRoom()->getNextRoom("east"));
    setButtonColor(ui->SOUTH, gameSetup->getCurrentRoom()->getNextRoom("south"));
    // cout<<"BACKGROUND SUPPOSEDLY UPDATED"<<endl;



}
void mainGameWindow ::setButtonColor(QPushButton *button, Room *exitRoom) {
    if (exitRoom == nullptr) {
        // Set button color to grey
        button->setStyleSheet("background-color: grey;");
    } else {
        // Set button color to red
        button->setStyleSheet("background-color: red;");
    }
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

void mainGameWindow::on_NORTH_clicked()
{

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
    gameSetup -> move ("south");
    updateBackgroundImage();


}



void mainGameWindow::on_EAST_clicked()
{
    gameSetup -> move ("east");
    updateBackgroundImage();

}





void mainGameWindow::on_OpenGuide_clicked()
{
    guide = new Guide(gameSetup, this);

    guide->show();
    guide->updateBackgroundImage();

    this -> hide();
}


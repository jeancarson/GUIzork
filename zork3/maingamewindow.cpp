#include "maingamewindow.h"
#include "ui_maingamewindow.h"
#include "gamesetup.h"
#include <QWidget>
#include "guide.h"
#include <iostream>
#include <QLayout>
#include <QPixmap>

#include <cstdlib>

using namespace std;
mainGameWindow::mainGameWindow(QWidget *parent, GameSetUp *preGameSetup)
    : QMainWindow(parent)
    , ui(new Ui::mainGameWindow)
    , gameSetup(preGameSetup)
    //, timerWidget(timer)
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

    cout<<gameSetup->getCurrentRoom()->getPathToImage()<<endl;
    updateBackgroundImage();
    timerWidget = gameSetup->getTimer();
    auto layout= new QVBoxLayout();
    layout->addWidget(timerWidget);
    ui->forTheTIMER->setLayout(layout);



    // QPixmap slot1Image("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/Keycard.png");
    // ui->slot1->setIcon(slot1Image);
    // ui->slot1->setIconSize(ui->slot1->size());


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


    if(gameSetup->getCurrentRoom()->getItemsInRoom().size()>0){
        QPixmap item(gameSetup->getCurrentRoom()->getItemsInRoom()[0].getPathToImage());
        // string sss = "C:Users/jeanl/College/Blocks/Block/4/C++/GUIzork/zork3/Keycard.png";
        // QPixmap item ("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/Keycard.png");
        ui->itemInRoom->setIcon(item);
        ui->itemInRoom->setIconSize(ui->itemInRoom->size());
    }
    else{
        QPixmap item("");
        ui->itemInRoom->setIcon(item);
        ui->itemInRoom->setIconSize(ui->itemInRoom->size());
    }


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







// void mainGameWindow::on_inventoryToggle_clicked()
// {
//     qDebug() << "Toggle button clicked";
//     if (InventoryWidget->isVisible()){
//         cout<< "InventoryWidget is visible, hiding..."<<endl;
//         // InventoryWidget->hide();
//     }
//     else{
//         cout<< "InventoryWidget is not visible, showing..."<<endl;
//         // InventoryWidget->show();
//     }
// }

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
    guide = new Guide(gameSetup, this, timerWidget);

    guide->show();
    guide->updateBackgroundImage();

    this -> hide();
}

bool isSlot1Yellow = false;
bool isSlot2Yellow = false;


void mainGameWindow::on_slot1_clicked()
{
    if(!isSlot1Yellow){
        ui->backgroundSlot1->setStyleSheet("background-color:yellow;");
        ui->backgroundSlot2->setStyleSheet("");
        isSlot1Yellow =true;
        isSlot2Yellow = false;
        gameSetup->setCurrentItem(gameSetup->getItemsBackEnd()[0]);
        // this->selectedItem = first item in backend inventory

    }
    else{
        ui->backgroundSlot1->setStyleSheet("");
        isSlot1Yellow = false;
        gameSetup->setCurrentItem(null);

        //this->selectedItem = null
    }
}


void mainGameWindow::on_slot2_clicked()
{
    if(!isSlot2Yellow){
        ui->backgroundSlot2->setStyleSheet("background-color:yellow;");
        ui->backgroundSlot1->setStyleSheet("");
        isSlot2Yellow =true;
        isSlot1Yellow = false;
        gameSetup->setCurrentItem(gameSetup->getItemsBackEnd()[1]);

    }
    else{
        ui->backgroundSlot2->setStyleSheet("");
        isSlot2Yellow = false;

    }
}


void mainGameWindow::updateInventory() {
    vector<Item> inventory = gameSetup->getItemsBackEnd();

    if (!inventory.empty()) {
        QPixmap slot1Image(inventory[0].getPathToImage());
        ui->slot1->setIcon(slot1Image);
        ui->slot1->setIconSize(ui->slot1->size());
        if (inventory.size() > 1) {
            QPixmap slot2Image(inventory[1].getPathToImage());
            ui->slot2->setIcon(slot2Image);
            ui->slot2->setIconSize(ui->slot2->size());
        }
        else{ui->slot2->setIcon(QIcon());}
    }
    else{
        ui->slot1->setIcon(QIcon());
        ui->slot2->setIcon(QIcon());
    }
}


void mainGameWindow::on_itemInRoom_clicked()
{

    if(!ui->itemInRoom->icon().isNull() && gameSetup->getItemsBackEnd().size() <2){
        Item theItem = gameSetup->getCurrentRoom()->getItemsInRoom()[0];
        gameSetup->getInventory()->addToInventory(theItem);
        gameSetup->getCurrentRoom()->removeItemFromRoom(theItem);
        updateBackgroundImage();
        updateInventory();

        //change location of next object
        int lowerBound = 50;
        int upperBound = 500;

        int randomNumber1 = lowerBound + std::rand() % (upperBound - lowerBound + 1);
        int randomNumber2 = lowerBound + std::rand() % (upperBound - lowerBound + 1);
        ui->itemInRoom->setGeometry(randomNumber1, randomNumber2, 50, 50);
    }

}


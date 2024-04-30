#include "maingamewindow.h"
#include "ui_maingamewindow.h"
#include "gamesetup.h"
#include "room.h"
#include <iostream>
#include <QWidget>

mainGameWindow::mainGameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainGameWindow)
{
    ui->setupUi(this);
    InventoryWidget = new QWidget(this); // Initialize InventoryWidget
    connect(ui->inventoryToggle, &QPushButton::clicked, this, &mainGameWindow::on_inventoryToggle_clicked);
    gameSetup = new GameSetUp(); // Initialize GameSetUp instance
    gameSetup->createRooms();
    cout<<"got to here2" <<endl;
    QString imagePath = ":frontDoorGeneric.jpg";

    // QString imagePath = QString::fromStdString(gameSetup->getCurrentRoom().getPathToImage());
    QString styleSheet = QString("background-image: url(%1);").arg(imagePath);
    this->setStyleSheet(styleSheet);
}

mainGameWindow::~mainGameWindow()
{
    delete ui;
    delete gameSetup; // Remember to free memory

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
    //call go() function with parameter "NORTH"
    //this might be currentroom.go("NORTH")
    //or move
    //idk
    gameSetup->move("north");

}


void mainGameWindow::on_WEST_clicked()
{
    //call go() function with parameter "WEST"
    gameSetup ->move ("west");
}


void mainGameWindow::on_SOUTH_clicked()
{
    //call go() function with parameter "SOUTH"
    gameSetup -> move ("south");

}
//set checks here to make sure that direction is not null - if it is, dont let that button do anything



void mainGameWindow::on_EAST_clicked()
{
    //call go() function with parameter "EAST"
    gameSetup -> move ("east");
}


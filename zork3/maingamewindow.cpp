#include "maingamewindow.h"
#include "ui_maingamewindow.h"
#include <QWidget>

mainGameWindow::mainGameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainGameWindow)
{
    ui->setupUi(this);
    InventoryWidget = new QWidget(this); // Initialize InventoryWidget
    connect(ui->inventoryToggle, &QPushButton::clicked, this, &mainGameWindow::on_inventoryToggle_clicked);

}

mainGameWindow::~mainGameWindow()
{
    delete ui;
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
}


void mainGameWindow::on_WEST_clicked()
{
    //call go() function with parameter "WEST"

}


void mainGameWindow::on_SOUTH_clicked()
{
    //call go() function with parameter "SOUTH"

}


void mainGameWindow::on_EAST_clicked()
{
    //call go() function with parameter "EAST"

}


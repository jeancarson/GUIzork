#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "maingamewindow.h"
#include "gamesetup.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameSetup = new GameSetUp();
    // cout<<"JUST before creating rooms in mainwindow"<<endl;
    gameSetup->createRooms();
    //the below appears to not be null anyways
    // cout << gameSetup ->getCurrentRoom()<<endl;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    mainGameWindow *game = new mainGameWindow(nullptr, gameSetup);
    game->show();
    this->hide();
}



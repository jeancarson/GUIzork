#include "mainwindow.h"
#include "./ui_mainwindow.h"
// #include "gamesetup.h"
// #include "maingamewindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap backgroundImage;
    ui->label->setPixmap(QString::fromStdString(":/ISEWelcome.png"));
    ui->label->setScaledContents(true);




}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{    // mainGameWindow *game = new mainGameWindow(nullptr, gameSetup, getTimer());

    gameSetup = new GameSetUp();
    cout<<"game set up complete"<<endl;
    // Pass the Timer object to the constructors of both windows
    timer = gameSetup->getTimer();
    game = new mainGameWindow(nullptr, gameSetup);
    guide = new Guide(gameSetup, nullptr);



    timer->start(1);
    game->show();
    this->hide();
}



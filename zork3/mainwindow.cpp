#include "mainwindow.h"
#include "./ui_mainwindow.h"
// #include "gamesetup.h"
// #include "maingamewindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game(nullptr)
    , gameSetup(nullptr)
    , timer(nullptr)
{
    ui->setupUi(this);

    ui->label->setPixmap(QString::fromStdString(":/ISEWelcome.png"));
    ui->label->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete game;
    delete gameSetup;
    delete ui;
}

void MainWindow::on_start_clicked()
{
    gameSetup = new GameSetUp();
    timer = gameSetup->getTimer();
    game = new mainGameWindow(nullptr, gameSetup);



    timer->start(1);
    game->show();
    this->hide();
}



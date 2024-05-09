#include "timer.h"
#include "ui_timer.h"
#include <QTimer>
#include <QLCDNumber>
#include <iostream>
#include "mainwindow.h"
using namespace std;
Timer::Timer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Timer)
{
    ui->setupUi(this);
    // int noMinutes = 6;
    // start(noMinutes);
}

Timer::~Timer()
{
    delete ui;
}

//Initialize "countdown" label text

//Connect timer to slot so it gets updated

//It is started with a value of 1000 milliseconds, indicating that it will time out every second.

void Timer::start(int duration) {
    remainingTime = duration * 60;
    cout<<remainingTime<<endl;
    updateDisplay(remainingTime);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Timer::updateTimer); // Connect timeout signal to updateTimer slot
    timer->start(1000); // Update display every second
}
void Timer::updateTimer() {
    remainingTime--; // Decrease remaining time
    updateDisplay(remainingTime); // Update display
    if (remainingTime <= 0) {
        timer->stop();
        kickPlayer();
        //TODO this will go to lose screen
    }
}


void Timer::updateDisplay(int seconds){
    int properMinutes = (seconds/60);
    int properSeconds = (seconds % 60);
    QString stringMinutes;
    QString stringSeconds;
    if (properMinutes <10){
        stringMinutes = "0" + QString::number(properMinutes);
    }
    else{
        stringMinutes = QString::number(properMinutes);
    }
    if (properSeconds <10){
        stringSeconds = "0" + QString::number(properSeconds);
    }
    else{
        stringSeconds = QString::number(properSeconds);
    }
    QString newTime = stringMinutes + ":" + stringSeconds;

    ui->TimerDisplay->display(newTime);
}


void Timer::kickPlayer(){
    endGameScreen end;
    end.setScreen("C:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/gameLost.jpg") ;
}

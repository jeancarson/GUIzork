#include "timer.h"
#include "ui_timer.h"
#include <QTimer>
#include <QLCDNumber>
#include <iostream>
using namespace std;

Timer::Timer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Timer)

{
    ui->setupUi(this);
}

Timer::~Timer()
{
    delete ui;
}


void Timer::start(int duration) {
    remainingTime = duration * 60;
    timeLeft = timeToString(remainingTime);
    emit timeUpdated();
    timer = new QTimer(this);
    // Connect timeout signal to updateTimer slot
    connect(timer, &QTimer::timeout, this, &Timer::updateTimer);
    timer->start(1000);
}

void Timer::updateTimer() {
    remainingTime--;
    timeLeft = timeToString(remainingTime);

    emit timeUpdated();
    if (remainingTime <= 0) {
        timer->stop();
        //mainGameWindow and Guide can connect a slot to this signal
        emit timeEnded();
    }
    if (remainingTime <= 50) {
        //mainGameWindow and Guide can connect a slot to this signal

        emit hurryUp();
    }
}

QString Timer::timeToString(int seconds) {
    int properMinutes = (seconds / 60);
    int properSeconds = (seconds % 60);
    QString stringMinutes = properMinutes < 10 ? "0" + QString::number(properMinutes) : QString::number(properMinutes);
    QString stringSeconds = properSeconds < 10 ? "0" + QString::number(properSeconds) : QString::number(properSeconds);
    QString newTime = stringMinutes + ":" + stringSeconds;
    return newTime;
}


QTimer* Timer::getTimer(){
    return timer;
}

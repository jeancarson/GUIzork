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
    cout << remainingTime << endl;
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
        emit timeEnded();
    }
    if (remainingTime <= 50) {
        emit hurryUp();
    }
}

void Timer::updateDisplay(int seconds) {
    int properMinutes = (seconds / 60);
    int properSeconds = (seconds % 60);
    QString stringMinutes = properMinutes < 10 ? "0" + QString::number(properMinutes) : QString::number(properMinutes);
    QString stringSeconds = properSeconds < 10 ? "0" + QString::number(properSeconds) : QString::number(properSeconds);
    QString newTime = stringMinutes + ":" + stringSeconds;

    ui->TimerDisplay->display(newTime);
}

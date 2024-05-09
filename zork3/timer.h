#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QTimer>
#include "endgamescreen.h"

namespace Ui {
class Timer;
}

class Timer : public QWidget
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();
    void start(int duration);
    void kickPlayer();


private:
    Ui::Timer *ui;
    int noMinutes;
    void updateDisplay(int seconds);
    void updateTimer();
    int remainingTime;
    QTimer *timer;
    endGameScreen end;

};

#endif // TIMER_H

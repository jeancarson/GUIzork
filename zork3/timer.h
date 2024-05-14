#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QTimer>

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

signals:
    void timeEnded();
    void hurryUp();
private:
    Ui::Timer *ui;
    int noMinutes;
    void updateDisplay(int seconds);
    void updateTimer();
    int remainingTime;
    QTimer *timer;
    // endGameScreen *endScreen;

};

#endif // TIMER_H

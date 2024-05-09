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


private:
    Ui::Timer *ui;
    int noMinutes;
    void updateDisplay(int seconds);
    void updateTimer();
    int remainingTime;
    QTimer *timer;
};

#endif // TIMER_H
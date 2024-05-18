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

private slots:
    void updateTimer();

private:
    Ui::Timer *ui;
    int noMinutes;
    void updateDisplay(int seconds);
    int remainingTime;
    QTimer *timer;

    // Declare mainGameWindow as a friend
    friend class mainGameWindow;
};

#endif // TIMER_H

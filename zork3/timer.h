#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QTimer>
#include <QString>
using namespace std;
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
    QTimer* getTimer();

signals:
    void timeEnded();
    void hurryUp();
    void timeUpdated();


private:
    Ui::Timer *ui;
    int noMinutes;
    QString timeToString(int seconds);
    int remainingTime;
    QTimer *timer;
    QString timeLeft;
    void updateTimer();


    // Friendship, so it is possible to have the same time show in two different windows
    friend class mainGameWindow;
    friend class Guide;
};

#endif // TIMER_H

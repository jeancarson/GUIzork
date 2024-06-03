#ifndef ENDGAMESCREEN_H
#define ENDGAMESCREEN_H

#include <QMainWindow>
#include <QWidget>
#include "timer.h"

namespace Ui {
class endGameScreen;
}

class endGameScreen : public QMainWindow
{
    Q_OBJECT

public:
    endGameScreen(QWidget *parent);
    ~endGameScreen();
    void setScreen(bool won);
    void closeEvent(QCloseEvent *event) override;


private:
    Ui::endGameScreen *ui;
    bool isGameOver;

private slots:
    void handleTimerUp();
};

#endif // ENDGAMESCREEN_H

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


private:
    Ui::endGameScreen *ui;
    bool isGameOver;
    void closeEvent(QCloseEvent *event) override;

};

#endif // ENDGAMESCREEN_H

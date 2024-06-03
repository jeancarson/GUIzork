#ifndef GUIDE_H
#define GUIDE_H
#include "gamesetup.h"
#include <QMainWindow>
#include "Timer.h"
using namespace GameSetup;

namespace Ui {
class Guide;
}

class Guide : public QMainWindow
{
    Q_OBJECT

public:
    explicit Guide(GameSetUp *gameSetup, QWidget *parent = nullptr);
    ~Guide();
    //moving the red dot on map
    void setLocationYOUareHERE();
    //setting which map depending on floor
    void updateBackgroundImage();

private slots:
    void on_CloseGuide_clicked();

private:
    GameSetUp* m_gameSetup;
    Timer *timerText;
    QWidget *parent;
    Ui::Guide *ui;
    void updateTimerDisplay();
    void handleTimerEnded();




};

#endif // GUIDE_H

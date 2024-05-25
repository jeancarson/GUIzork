#ifndef GUIDE_H
#define GUIDE_H
#include "gamesetup.h"
#include <QMainWindow>
#include "Timer.h"
using namespace GameSetup;

namespace Ui {
class Guide;
}
// Guide::Guide(GameSetUp *gameSetup, QWidget *parent)

class Guide : public QMainWindow
{
    Q_OBJECT

public:
    explicit Guide(GameSetUp *gameSetup, QWidget *parent = nullptr);

    ~Guide();
    void setLocationYOUareHERE();
    void updateBackgroundImage();

private slots:
    void on_CloseGuide_clicked();

private:
    GameSetUp* m_gameSetup;
    Timer *timerText;
    QWidget *parent;
    Ui::Guide *ui;
    void updateTimerDisplay();




};

#endif // GUIDE_H

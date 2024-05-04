#ifndef GUIDE_H
#define GUIDE_H
#include "gamesetup.h"
#include <QMainWindow>

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

private:
    GameSetUp *m_gameSetup; // Use the correct variable name here

    Ui::Guide *ui;
    void setLocationYOUareHERE();
    void updateBackgroundImage();

};

#endif // GUIDE_H

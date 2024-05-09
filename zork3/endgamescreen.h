#ifndef ENDGAMESCREEN_H
#define ENDGAMESCREEN_H

#include <QMainWindow>
#include <string>
using namespace std;
namespace Ui {
class endGameScreen;
}

class endGameScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit endGameScreen(QWidget *parent = nullptr);
    ~endGameScreen();
    void setScreen(string path);

private:
    Ui::endGameScreen *ui;
};

#endif // ENDGAMESCREEN_H

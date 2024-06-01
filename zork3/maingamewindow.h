#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>
#include "gamesetup.h"
#include "endgamescreen.h"
#include "anxiouscharacter.h"
#include "timer.h"
#include <QPushButton>
#include "guide.h"
#include "logger.h"

namespace Ui {

class mainGameWindow;}
//Bit Fields/ Bit Structures
struct GameFlags {
    //2 flags = 2 bits (3 flags = 3 bits)
    unsigned short flags : 2;

    GameFlags() : flags(0) {} // Initialize flags to 0 (not game over, Alison not on screen)

    //BITWISE and with flags and 01
    bool isGameOver() const { return (flags & 1) != 0; }
    //BITWISE and with flags and NOT 1 (10) to clear
    //condition ? value_if_true : value_if_false
    //then BITWISE or to 'add' relevent bit to the flag if true.
    void setGameOver(bool gameOver) { flags = (flags & ~1) | (gameOver ? 1 : 0); }

    //bitwise and with 10, then with not2 ie 01
    bool isAlisonOnScreen() const { return (flags & 2) != 0; }
    void setAlisonOnScreen(bool onScreen) { flags = (flags & ~2) | (onScreen ? 2 : 0); }

    // A third flag would have the above operations done with 4 (100)
};


class mainGameWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit mainGameWindow(QWidget *parent = nullptr, GameSetup::GameSetUp *preGameSetup = nullptr);
    ~mainGameWindow();

private slots:
    void handleTimerEnded();
    void handleHurryUp();
    void on_NORTH_clicked();
    void on_WEST_clicked();
    void on_SOUTH_clicked();
    void on_EAST_clicked();
    void on_OpenGuide_clicked();
    void on_slot1_clicked();
    void on_slot2_clicked();
    void on_itemInRoom_clicked();
    void on_EnemyPlace_clicked();
    void on_AlisonGoesHere_clicked();

private:
    Ui::mainGameWindow *ui;
    GameSetup::GameSetUp *gameSetup;
    endGameScreen *end;
    AnxiousCharacter *alison;
    GameFlags flags;
    Timer *timerWidget;
    bool isSlot1Yellow;
    bool isSlot2Yellow;
    Guide *guide;
    void updateBackgroundImage();
    //dont need gamesetup::room here bc namespace
    void setButtonColor(QPushButton *button, Room *exitRoom);
    void updateInventory();
    void updateTimerDisplay();
};

#endif // MAINGAMEWINDOW_H

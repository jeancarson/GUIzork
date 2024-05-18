#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>
#include "gamesetup.h"
#include "endgamescreen.h"
#include "anxiouscharacter.h"
#include "timer.h"
#include <QPushButton>
#include "guide.h"

namespace Ui {

class mainGameWindow;}
struct GameFlags {
    unsigned short flags : 2; // Allocate 2 bits for flags

    GameFlags() : flags(0) {} // Initialize flags to 0 (not game over, Alison not on screen)

    // Access and modify flags using bitwise operators
    bool isGameOver() const { return (flags & 1) != 0; }
    void setGameOver(bool gameOver) { flags = (flags & ~1) | (gameOver ? 1 : 0); }

    bool isAlisonOnScreen() const { return (flags & 2) != 0; }
    void setAlisonOnScreen(bool onScreen) { flags = (flags & ~2) | (onScreen ? 2 : 0); }
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
    anxiousCharacter *alison;
    GameFlags flags;
    Timer *timerWidget;
    bool isSlot1Yellow;
    bool isSlot2Yellow;
    Guide *guide;
    void updateBackgroundImage();
    //dont need gamesetup::room here bc namespace
    void setButtonColor(QPushButton *button, Room *exitRoom);
    void updateInventory();
};

#endif // MAINGAMEWINDOW_H

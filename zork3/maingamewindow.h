#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>
#include "gamesetup.h"
#include <QLabel>
#include <QPushButton>
#include "guide.h"
#include "item.h"
#include "guide.h"
#include "endgamescreen.h"
#include "anxiouscharacter.h"


namespace Ui {
class mainGameWindow;
}

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
private:
    QMainWindow* parentWindow;
    Timer* timerWidget;
    GameSetUp* gameSetup;
    endGameScreen *end;
    anxiousCharacter *alison;
    // bool alisonTimeFlag;
    GameFlags flags;

public:
    explicit mainGameWindow(QWidget *parent, GameSetUp *preGameSetup);
    ~mainGameWindow();
    void updateInventory();


private slots:
    void on_NORTH_clicked();
    void on_WEST_clicked();
    void on_SOUTH_clicked();
    void on_EAST_clicked();
    void updateBackgroundImage();
    void setButtonColor(QPushButton *button, Room *exitRoom);
    void on_OpenGuide_clicked();
    void on_slot1_clicked();
    void on_slot2_clicked();
    void on_itemInRoom_clicked();
    void handleTimerEnded();
    void handleHurryUp();

    void on_EnemyPlace_clicked();

    void on_AlisonGoesHere_clicked();

private:
    Ui::mainGameWindow *ui;
    QWidget *InventoryWidget;
    Guide *guide;
    void addToSlot(Item item);
    void removeFromSlot(Item item);
    Item* selectedItem;

    // GameSetUp *preGameSetup;


};

#endif // MAINGAMEWINDOW_H






#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>
#include "gamesetup.h"
#include <QLabel>
#include <QPushButton>
#include "guide.h"
#include "item.h"
#include "inventorybackend.h"


namespace Ui {
class mainGameWindow;
}

class mainGameWindow : public QMainWindow {
    Q_OBJECT
private:
    Timer* timerWidget;
    GameSetUp* gameSetup;

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






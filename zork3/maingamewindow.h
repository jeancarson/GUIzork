#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>
#include "room.h"
#include "gamesetup.h"
namespace Ui {
class mainGameWindow;
}

class mainGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainGameWindow(QWidget *parent = nullptr);
    ~mainGameWindow();

private slots:
    void on_inventoryToggle_clicked();

    void on_NORTH_clicked();

    void on_WEST_clicked();

    void on_SOUTH_clicked();

    void on_EAST_clicked();

private:
    Ui::mainGameWindow *ui;
    QWidget *InventoryWidget;
    GameSetUp *gameSetup;

};

#endif // MAINGAMEWINDOW_H

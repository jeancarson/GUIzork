#ifndef INVENTORY_H
#define INVENTORY_H

#include <QWidget>
// #include "inventorybackend.h"
#include "item.h"
// class inventoryBackEnd;

namespace Ui {
class Inventory;
}

class Inventory : public QWidget
{
    Q_OBJECT

public:
    explicit Inventory(QWidget *parent = nullptr);
    ~Inventory();
    void updateInventoryWidget(vector<Item>& items);


private slots:
    // void on_SLOT1_linkHovered(const QString &link);

    // void on_SLOT2_linkHovered(const QString &link);

    // void on_SLOT1_linkActivated(const QString &link);
    // void on_SLOT1_hovered();

    void on_SLOT1_pressed();

    void on_SLOT1_clicked();

    void on_SLOT1_released();
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);




    void on_SLOT2_pressed();

    void on_SLOT2_released();

private:
    // inventoryBackEnd *inventoryBackEnd; // Use a pointer to avoid circular dependency
    Ui::Inventory *ui;
    Item itemInSlot1;
    Item iteminSlot2;
    void setItemInSlot1(Item item);
    void setItemInSlot2(Item item);




};

#endif // INVENTORY_H

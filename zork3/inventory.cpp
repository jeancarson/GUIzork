#include "inventory.h"
#include "ui_inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Inventory)
{
    ui->setupUi(this);
}

Inventory::~Inventory()
{
    delete ui;
}



//TODO I highly doubt that this will work :/
void Inventory::setItemInSlot1(Item item){
    ui->SLOT1->setStyleSheet("background-image: url(" + item.getPathToImage() + "); ");
}

void Inventory::setItemInSlot2(Item item){
    ui->SLOT2->setStyleSheet("background-image: url(" + item.getPathToImage() + "); ");
}

void Inventory::updateInventoryWidget(vector<Item>& items){
    setItemInSlot1(items[0]);
    setItemInSlot2(items[1]);
    }






















void Inventory::on_SLOT1_pressed()
{
    ui->SLOT1->setStyleSheet("background-color: yellow;");
}

void Inventory::on_SLOT1_clicked()
{
    ui->SLOT1->setText("AHHH");
    this->setStyleSheet("background-color: blue;");
}

void Inventory::on_SLOT1_released()
{
    ui->SLOT1->setStyleSheet("background-color: red;");
}

void Inventory::enterEvent(QEvent *event)
{
    ui->SLOT1->setStyleSheet("background-color: yellow;");
}

void Inventory::leaveEvent(QEvent *event)
{
    ui->SLOT1->setStyleSheet(""); // Reset to default stylesheet
}

void Inventory::on_SLOT2_pressed()
{
    // ui->SLOT2->setStyleSheet(""); // Reset to default stylesheet
    // ui->SLOT2->setStyleSheet("background-image: url(/:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/frontDoorGeneric.jpg); ");
    // cout << "SLOT 2 is PRESSED" << endl;
}

void Inventory::on_SLOT2_released()
{
    // this->setStyleSheet("background-image: url(/:/Users/jeanl/College/Blocks/Block 4/C++/GUIzork/zork3/frontDoorGeneric.jpg);");
    // cout << "SLOT 2 is released" << endl;
}

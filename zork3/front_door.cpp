// #include "front_door.h"
// #include "ui_front_door.h"
// #include "inside_front_door.h"
// #include "Inventory.h"
// #include <QTextEdit>


// front_door::front_door(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::front_door)
// {
//     ui->setupUi(this);
// }
// //SINGLETON YAY JOSH
// Inventory& inventory = Inventory::getInstance();
// front_door::~front_door()
// {
//     delete ui;
// }

// void front_door::on_pushButton_2_clicked()
// {
//     if(inventory.hasItem("keycard")){
//     inside_front_door *inside = new(inside_front_door);
//     inside->show();
//     this->hide();}
// }

// // QTextEdit textEdit;

// void front_door::on_pushButton_clicked()
// {
//     inventory.addItem("keycard");
//     // textEdit.setText("HAVE A KECARD");
// }


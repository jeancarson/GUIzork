#include "mapa.h"
#include "ui_mapa.h"
#include "gamesetup.h"

mapa::mapa(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mapa)
{
    ui->setupUi(this);
}

mapa::~mapa()
{
    delete ui;
}

Room currentRoom = //maybe make current room global????





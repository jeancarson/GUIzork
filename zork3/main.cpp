#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "inventory.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cout<<"MAIN IS RUNNING"<< endl;

    // MainWindow w;
    Inventory w;
    w.show();
    return a.exec();
}

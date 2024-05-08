
#include <QApplication>
#include <iostream>
#include "timer.h"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cout<<"MAIN IS RUNNING"<< endl;

    MainWindow w;
    // Timer w;
    w.show();
    return a.exec();
}


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
    cout<<"mainwindow is created"<<endl;
    w.show();
    cout<<"W should be showing rn"<<endl;
    return a.exec();
}

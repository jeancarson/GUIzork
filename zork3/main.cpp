#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "timer.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cout<<"MAIN IS RUNNING"<< endl;

    // MainWindow w;
    Timer w;
    w.show();
    cout<<"W should be showing rn"<<endl;
    return a.exec();
}

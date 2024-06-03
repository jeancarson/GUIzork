
#include <QApplication>
#include <iostream>
#include "timer.h"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{

    std::srand(std::time(nullptr));

    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();


}

#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
/*
 * will have each room be a room object, each room contains inventory list, floor,
 * coordinates of map
 *
 * will have an inventory at the bottom, probably don't need to be able to get rif of stuff
 *
 * maybe each room will have a text box idk yet
 *
 * have to get some object... idk what yet add to inventory and find your way back out
 *
 * will have text boxes show up if you try to access something without a keycard etc
 * A character can steal your keycard maybe
 * click on a character to talk to them
 *
 *
 */

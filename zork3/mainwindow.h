#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamesetup.h"
#include "guide.h"
#include "maingamewindow.h"
#include "Timer.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_start_clicked();

private:
    Ui::MainWindow *ui;
    GameSetUp *gameSetup;
    Timer *timer;
    mainGameWindow *game;


};
#endif // MAINWINDOW_H

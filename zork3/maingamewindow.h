#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class mainGameWindow;
}

class mainGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainGameWindow(QWidget *parent = nullptr);
    ~mainGameWindow();

private slots:
    void on_widget_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_3_clicked();

    void on_inventoryToggle_clicked();

private:
    Ui::mainGameWindow *ui;
    QWidget *InventoryWidget;


};

#endif // MAINGAMEWINDOW_H

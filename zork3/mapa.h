#ifndef MAPA_H
#define MAPA_H

#include <QMainWindow>
#include <QString>
#include "ui_mapa.h"


namespace Ui {
class mapa;
}

class mapa : public QMainWindow
{
    Q_OBJECT

public:
    explicit mapa(QWidget *parent = nullptr);
    ~mapa();

private:
    Ui::mapa *ui;
    void setFloorBackgroundImage();
    void setLocationYOUareHERE();
};

#endif // MAPA_H

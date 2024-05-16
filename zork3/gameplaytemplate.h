#ifndef GAMEPLAYTEMPLATE_H
#define GAMEPLAYTEMPLATE_H

#include <QMainWindow>

namespace Ui {
class GameplayTemplate;
}

class GameplayTemplate : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameplayTemplate(QWidget *parent = nullptr);
    ~GameplayTemplate();

private:
    Ui::GameplayTemplate *ui;
};

#endif // GAMEPLAYTEMPLATE_H

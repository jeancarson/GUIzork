#include "maingamewindow.h"
#include "ui_maingamewindow.h"
#include <iostream>
#include <QVBoxLayout>
#include <QPixmap>

using namespace std;
using namespace GameSetup;

mainGameWindow::mainGameWindow(QWidget *parent, GameSetUp *preGameSetup)
    : QMainWindow(parent)
    , ui(new Ui::mainGameWindow)
    , gameSetup(preGameSetup)
    , end(new endGameScreen(this))
    , alison(new anxiousCharacter(":/gameWon.jpg"))
    , flags()
    , isSlot1Yellow(false)
    , isSlot2Yellow(false)
    , guide(nullptr)
{
    ui->setupUi(this);
    timerWidget = new Timer(this);

    connect(timerWidget, &Timer::timeEnded, this, &mainGameWindow::handleTimerEnded);
    connect(timerWidget, &Timer::hurryUp, this, &mainGameWindow::handleHurryUp);

    if (!preGameSetup) {
        cout << "GAME SETUP IS NULL" << endl;
    }
    cout << "BEFORE INITIALIZING SETUP" << endl;
    gameSetup = preGameSetup;
    cout << gameSetup->getCurrentRoom()->getPathToImage() << endl;
    cout << "AFTER INITIALIZING SETUP" << endl;
    cout << gameSetup->getCurrentRoom()->getPathToImage() << endl;
    updateBackgroundImage();

    auto layout = new QVBoxLayout();
    layout->addWidget(timerWidget);
    ui->forTheTIMER->setLayout(layout);
}

void mainGameWindow::handleTimerEnded() {
    if (!flags.isGameOver()) {
        flags.setGameOver(true);
        this->hide();
        end->setScreen(false);
        end->show();
    }
}

void mainGameWindow::handleHurryUp() {
    flags.setAlisonOnScreen(true);
    QString imagePath = QString::fromStdString(alison->getPathToImage());
    QIcon icon(imagePath);
    ui->AlisonGoesHere->setIcon(icon);
    ui->AlisonGoesHere->setIconSize(ui->AlisonGoesHere->size());
}

mainGameWindow::~mainGameWindow() {
    delete ui;
}

void mainGameWindow::updateBackgroundImage() {
    if (gameSetup->isTheGameWon()) {
        flags.setGameOver(true);
        end->setScreen(true);
        end->show();
        this->hide();
    }

    string path = gameSetup->getCurrentRoom()->getPathToImage();
    QPixmap backgroundImage(QString::fromStdString(path));
    ui->label->setPixmap(backgroundImage);
    ui->label->setScaledContents(true);

    setButtonColor(ui->NORTH, gameSetup->getCurrentRoom()->getNextRoom("north"));
    setButtonColor(ui->WEST, gameSetup->getCurrentRoom()->getNextRoom("west"));
    setButtonColor(ui->EAST, gameSetup->getCurrentRoom()->getNextRoom("east"));
    setButtonColor(ui->SOUTH, gameSetup->getCurrentRoom()->getNextRoom("south"));

    if (!gameSetup->getCurrentRoom()->getItemsInRoom().empty()) {
        QPixmap item(gameSetup->getCurrentRoom()->getItemsInRoom()[0].getPathToImage());
        ui->itemInRoom->setIcon(item);
        ui->itemInRoom->setIconSize(ui->itemInRoom->size());
    } else {
        ui->itemInRoom->setIcon(QIcon());
    }

    if (Enemy* enemyPtr = gameSetup->getCurrentRoom()->getEnemyInRoom()) {
        QPixmap enemy(QString::fromStdString(enemyPtr->getPathToImage()));
        ui->EnemyPlace->setIcon(enemy);
        ui->EnemyPlace->setIconSize(ui->EnemyPlace->size());
    } else {
        ui->EnemyPlace->setIcon(QIcon());
    }
}

void mainGameWindow::setButtonColor(QPushButton *button, Room *exitRoom) {
    if (!exitRoom) {
        button->setStyleSheet("background-color: grey;");
    } else {
        button->setStyleSheet("background-color: red;");
    }
}

void mainGameWindow::updateInventory() {
    vector<Item> inventory = gameSetup->getItemsBackEnd();

    if (!inventory.empty()) {
        QPixmap slot1Image(inventory[0].getPathToImage());
        ui->slot1->setIcon(slot1Image);
        ui->slot1->setIconSize(ui->slot1->size());
        if (inventory.size() > 1) {
            QPixmap slot2Image(inventory[1].getPathToImage());
            ui->slot2->setIcon(slot2Image);
            ui->slot2->setIconSize(ui->slot2->size());
        }
        else{ui->slot2->setIcon(QIcon());}
    }
    else{
        ui->slot1->setIcon(QIcon());
        ui->slot2->setIcon(QIcon());
    }
}


void mainGameWindow::on_NORTH_clicked() {
    gameSetup->move("north");
    updateBackgroundImage();
}

void mainGameWindow::on_WEST_clicked() {
    gameSetup->move("west");
    updateBackgroundImage();
}

void mainGameWindow::on_SOUTH_clicked() {
    gameSetup->move("south");
    updateBackgroundImage();
}

void mainGameWindow::on_EAST_clicked() {
    gameSetup->move("east");
    updateBackgroundImage();
}

void mainGameWindow::on_OpenGuide_clicked() {
    guide = new Guide(gameSetup, this, timerWidget);
    guide->show();
    guide->updateBackgroundImage();
    this->hide();
}

void mainGameWindow::on_slot1_clicked() {
    if (!isSlot1Yellow && !ui->slot1->icon().isNull()) {
        ui->backgroundSlot1->setStyleSheet("background-color: yellow;");
        ui->backgroundSlot2->setStyleSheet("background-color: black;");
        isSlot1Yellow = true;
        isSlot2Yellow = false;
        gameSetup->setCurrentItem(gameSetup->getItemsBackEnd()[0]);
    } else {
        ui->backgroundSlot1->setStyleSheet("background-color: black;");
        isSlot1Yellow = false;
        gameSetup->setCurrentItem(Item());
    }
}
void mainGameWindow::on_slot2_clicked()
{
    if((!isSlot2Yellow) && !(ui->slot2->icon().isNull())){
        ui->backgroundSlot2->setStyleSheet("background-color:yellow;");
        ui->backgroundSlot1->setStyleSheet("background-color:black;");
        isSlot2Yellow =true;
        isSlot1Yellow = false;
        gameSetup->setCurrentItem(gameSetup->getItemsBackEnd()[1]);

    }
    else{
        gameSetup->setCurrentItem(Item ());

        ui->backgroundSlot2->setStyleSheet("background-color:black;");
        isSlot2Yellow = false;

    }
}

void mainGameWindow::on_itemInRoom_clicked()
{

    if(!ui->itemInRoom->icon().isNull() && gameSetup->getItemsBackEnd().size() <2){
        Item theItem = gameSetup->getCurrentRoom()->getItemsInRoom()[0];
        gameSetup->getInventory()->addToInventory(theItem);
        gameSetup->getCurrentRoom()->removeItemFromRoom(theItem);
        updateBackgroundImage();
        updateInventory();

        //change location of next object
        int lowerBound = 50;
        int upperBound = 500;

        int randomNumber1 = lowerBound + std::rand() % (upperBound - lowerBound + 1);
        int randomNumber2 = lowerBound + std::rand() % (upperBound - lowerBound + 1);
        ui->itemInRoom->setGeometry(randomNumber1, randomNumber2, 50, 50);
    }

}


void mainGameWindow::on_EnemyPlace_clicked()
{
    //TODO this should probabl be a method in the gamesetup class and just be called here??
    if(gameSetup->getCurrentRoom()->isEnemyInRoom){
        Enemy* enemy = gameSetup->getCurrentRoom()->getEnemyInRoom();
        Character* characterEnemy = dynamic_cast<Character*>(enemy);
        if (characterEnemy !=nullptr) {
            cout<<characterEnemy->talk()<<endl;
            ui->enemySpeech->setText(QString::fromStdString(characterEnemy->talk()));
        }



        if(enemy->getItemToOvercome().getName() == gameSetup->getCurrentItem()->getName()){
            gameSetup->getCurrentRoom()->removeEnemyFromRoom();
            gameSetup->getInventory()->removeFromInventory(*gameSetup->getCurrentItem());
            updateInventory();
            updateBackgroundImage();

            gameSetup->setCurrentItem(Item ());

            ui->backgroundSlot2->setStyleSheet("background-color:black;");
            isSlot2Yellow = false;

            ui->backgroundSlot1->setStyleSheet("background-color:black;");
            isSlot1Yellow = false;

            ui->enemySpeech->setText("");
        }
    }
}




void mainGameWindow::on_AlisonGoesHere_clicked()
{
    if (ui->alisonSays->text()=="" && flags.isAlisonOnScreen()){
        ui->alisonSays->setText(QString::fromStdString(alison->talk()));
    }
    else{
        ui->alisonSays->setText("");
    }
}

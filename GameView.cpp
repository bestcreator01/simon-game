#include "GameView.h"
#include "ui_GameView.h"

GameView::GameView(GameModel& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameView)
{
    // basic setup
    ui->setupUi(this);
    ui->startButton->setStyleSheet("background-color: silver");
    ui->blueButton->setStyleSheet("background-color: skyblue");
    ui->redButton->setStyleSheet("background-color: tomato");
    ui->loseLabel->setVisible(false);

    // start button
    connect(&model, &GameModel::hideStartButton, ui->startButton, &QPushButton::hide);
    connect(ui->startButton, &QPushButton::clicked, &model, &GameModel::gameStarted);

    // during game
    connect(&model, &GameModel::enableButtons, ui->blueButton, &QPushButton::setEnabled);
    connect(&model, &GameModel::enableButtons, ui->redButton, &QPushButton::setEnabled);
    connect(&model, &GameModel::displayBlue, ui->blueButton, &QPushButton::setStyleSheet);
    connect(&model, &GameModel::displayRed, ui->redButton, &QPushButton::setStyleSheet);

    connect(ui->blueButton, &QPushButton::clicked, &model, &GameModel::checkPattern);
    connect(ui->redButton, &QPushButton::clicked, &model, &GameModel::checkPattern);

//    connect(ui->blueButton, &QPushButton::clicked, &model, &GameModel::duringGame);
//    connect(ui->redButton, &QPushButton::clicked, &model, &GameModel::duringGame);

}

GameView::~GameView()
{
    delete ui;
}


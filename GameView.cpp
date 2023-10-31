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
    ui->progressBar->setValue(0);

    // start button
    connect(&model, &GameModel::enableStartButton, ui->startButton, &QPushButton::setVisible);
    connect(ui->startButton, &QPushButton::clicked, &model, &GameModel::gameStarted);

    // during game
    connect(&model, &GameModel::enableButtons, ui->blueButton, &QPushButton::setEnabled);
    connect(&model, &GameModel::enableButtons, ui->redButton, &QPushButton::setEnabled);
    connect(&model, &GameModel::displayBlue, ui->blueButton, &QPushButton::setStyleSheet);
    connect(&model, &GameModel::displayRed, ui->redButton, &QPushButton::setStyleSheet);

    connect(ui->blueButton, &QPushButton::clicked, &model, &GameModel::playerTurn);
    connect(ui->redButton, &QPushButton::clicked, &model, &GameModel::playerTurn);
    connect(&model, &GameModel::updateProgressBar, ui->progressBar, &QProgressBar::setValue);

    // lost game
    connect(&model, &GameModel::gameLost, ui->loseLabel, &QLabel::setVisible);

}

GameView::~GameView()
{
    delete ui;
}


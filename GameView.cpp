#include <QPixmap>
#include "GameView.h"
#include "ui_GameView.h"

GameView::GameView(GameModel& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameView)
    , bgm(new QMediaPlayer)
    , bgmOutput(new QAudioOutput)
{
    // basic setup
    ui->setupUi(this);
    ui->startButton->setStyleSheet("background-color: silver");
    ui->blueButton->setStyleSheet("background-color: skyblue");
    ui->redButton->setStyleSheet("background-color: tomato");
    ui->loseLabel->setVisible(false);
    ui->scoreLabel->setVisible(false);
    ui->resultLabel->setVisible(false);
    ui->resultLabel->setAlignment(Qt::AlignCenter);
    ui->progressBar->setValue(0);

    QPixmap pumpkin (":/png/carvedPumpkin.png");
    ui->pumpkinImage->setPixmap(pumpkin.scaled(80, 80));
    ui->pumpkinImage_2->setPixmap(pumpkin.scaled(50, 50));
    ui->pumpkinImage_3->setPixmap(pumpkin.scaled(30, 30));
    ui->pumpkinImage_4->setPixmap(pumpkin.scaled(30, 30));

    // start button
    connect(&model, &GameModel::enableStartButton, ui->startButton, &QPushButton::setVisible);
    connect(ui->startButton, &QPushButton::clicked, &model, &GameModel::gameStarted);
    connect(&model, &GameModel::showScoreLabel, ui->scoreLabel, &QPushButton::setVisible);

    // music setup
    connect(ui->startButton, &QPushButton::clicked, this, &GameView::playBGM);

    // during game
    connect(&model, &GameModel::enableButtons, ui->blueButton, &QPushButton::setEnabled);
    connect(&model, &GameModel::enableButtons, ui->redButton, &QPushButton::setEnabled);
    connect(&model, &GameModel::displayBlue, ui->blueButton, &QPushButton::setStyleSheet);
    connect(&model, &GameModel::displayRed, ui->redButton, &QPushButton::setStyleSheet);

    connect(ui->blueButton, &QPushButton::clicked, &model, &GameModel::playerTurn);
    connect(ui->redButton, &QPushButton::clicked, &model, &GameModel::playerTurn);
    connect(&model, &GameModel::updateProgressBar, ui->progressBar, &QProgressBar::setValue);
    connect(&model, &GameModel::updateScore, ui->scoreLabel, &QLabel::setText);

    // lost game & stop music
    connect(&model, &GameModel::gameLost, ui->loseLabel, &QLabel::setVisible);
    connect(&model, &GameModel::showResultLabel, ui->resultLabel, &QLabel::setVisible);
    connect(&model, &GameModel::updateResult, ui->resultLabel, &QLabel::setText);
    connect(&model, &GameModel::gameLost, this, &GameView::stopBGM);
}

GameView::~GameView()
{
    delete ui;

    delete bgm;
    delete bgmOutput;
}

void GameView::playBGM()
{
    bgm->setAudioOutput(bgmOutput);
    bgmOutput->setMuted(false);
    bgm->setSource(QUrl("qrc:/mp3/SpookyBGM.mp3"));
    bgmOutput->setVolume(0.8);
    bgm->play();
}

void GameView::stopBGM()
{
    bgm->stop();
}

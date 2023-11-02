#include <QPixmap>
#include "GameView.h"
#include "ui_GameView.h"

GameView::GameView(GameModel& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameView)
    , sound(new QMediaPlayer(this))
    , audioOutput(new QAudioOutput(this))
{
    // basic setup
    ui->setupUi(this);
    ui->startButton->setStyleSheet("background-color: silver");
    ui->blueButton->setStyleSheet("background-color: skyblue");
    ui->redButton->setStyleSheet("background-color: tomato");
    ui->loseLabel->setVisible(false);
    ui->progressBar->setValue(0);

    // music setup
    QMediaPlayer *p = new QMediaPlayer();
    p->setSource(QUrl(":/wav/SpookyBGM.wav"));
    p->play();

    QPixmap pix (":/png/carvedPumpkin.png");
    ui->pumpkinImage->setPixmap(pix.scaled(80, 80));
    ui->pumpkinImage_2->setPixmap(pix.scaled(50, 50));
    ui->pumpkinImage_3->setPixmap(pix.scaled(30, 30));
    ui->pumpkinImage_4->setPixmap(pix.scaled(30, 30));

    // music playing
    //connect(ui->startButton, &QPushButton::clicked, this, &GameView::playMusic);

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
    //connect(&model, &GameModel::playYouLostSound, sound, &QMediaPlayer::play);
}

GameView::~GameView()
{
    delete ui;
}

void GameView::playMusic()
{
    sound->setAudioOutput(audioOutput);
    sound->setSource(QUrl(":/wav/SpookyBGM.wav"));
    audioOutput->setVolume(80);
    sound->play();
}


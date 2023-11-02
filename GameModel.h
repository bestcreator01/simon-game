#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QPushButton>
#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QRandomGenerator>

class GameModel : public QObject
{
    Q_OBJECT

public:
    explicit GameModel(QObject *parent = nullptr);
    void duringGame();
    void displayPatterns(int pattern);
    void displayOriginal(int pattern);
    void computerTurn();

public slots:
    void gameStarted();
    void playerTurn();

signals:
    void enableStartButton(bool);
    void enableButtons(bool);
    void showScoreLabel(bool);
    void showResultLabel(bool);
    void displayBlue(QString);
    void displayRed(QString);
    void gameLost(bool);
    void updateProgressBar(int);
    void updateScore(QString);
    void updateResult(QString);

private:
    int currentMoves;
    int totalMoves;
    int currentIndex;
    int currentScore;
    QList<int> computerPatterns;
    void checkPattern(int pattern);
    void updateProgress();
};

#endif // GAMEMODEL_H

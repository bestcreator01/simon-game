#ifndef GAMEMODEL_H
#define GAMEMODEL_H

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
    void computerTurn();

public slots:
    void gameStarted();
//    void checkPattern();

signals:
    void hideStartButton();
    void enableButtons(bool);
    void displayBlue(QString);
    void displayRed(QString);
//    void gameLost();

private:
    int currentMoves;
    int totalMoves;
    int currentIndex;
    QList<int> computerPatterns;
    QTimer *timer;
};

#endif // GAMEMODEL_H

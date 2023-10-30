#include <QDebug>
#include <QEventLoop>
#include <QTimer>
#include "GameModel.h"

GameModel::GameModel(QObject *parent)
    : QObject(parent)
{
    totalMoves = 1;


//    connect(timer, &QTimer::timeout, this, [=]() { displayPatterns(2); });
}

void GameModel::gameStarted()
{
    // update start button to be invisible
    emit hideStartButton();
    computerTurn();
}

void GameModel::computerTurn()
{
    // disable red and blue buttons
    emit enableButtons(false);

    // generate random pattern and append to computerPatterns
    int randomNumber = QRandomGenerator::global()->bounded(2);
    computerPatterns.append(randomNumber);
//    computerPatterns.append(0);
//    computerPatterns.append(0);
//    computerPatterns.append(1);
//    computerPatterns.append(0);
//    computerPatterns.append(1);

    int patternTime = 750;
    int originalTime = 1500;
    for(int pattern : computerPatterns)
    {
        QTimer::singleShot(patternTime, this, [=]() { displayPatterns(pattern);});
        QTimer::singleShot(originalTime, this, [=]() { displayOriginal(pattern);});

        patternTime += 1000;
        originalTime += 1000;
    }

    // player turn

    // enable red and blue buttons
    emit enableButtons(true);

    // while !(computerPatterns is done or wrong),

        // for (int pattern: computerPatterns)
        //      if current pressed button == pattern
        //          continue
        //      else lose = true;
        //          break;
}

void GameModel::displayPatterns(int pattern)
{
    if (pattern == 0)
    {
        emit displayBlue("background-color: blue");
    }
    else
    {
        emit displayRed("background-color: red");
    }
    qDebug() << "pattern...";
}

void GameModel::displayOriginal(int pattern)
{
    if (pattern == 0)
    {
        emit displayBlue("background-color: skyblue");
    }
    else
    {
        emit displayRed("background-color: tomato");
    }
    qDebug() << "original...";
}

//void GameModel::gameLost()
//{
//    // disable all buttons
//    // disable everything on screen
//    // except "restart" button
//    // display YOU LOSE on screen with sound
//    // Try to make the game startable
//}


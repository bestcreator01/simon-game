#include <QDebug>
#include <QEventLoop>
#include <QTimer>
#include "GameModel.h"

GameModel::GameModel(QObject *parent)
    : QObject(parent)
    , timer(new QTimer(this))
{
    totalMoves = 1;


    timer->start();
    //connect(timer, &QTimer::timeout, this, [=]() { displayPatterns(2); });
    QTimer::singleShot(1000, this, [=]() { displayPatterns(2);});
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

    int randomNumber;

    // generate random pattern and append to computerPatterns
    //    randomNumber = QRandomGenerator::global()->bounded(2);
    //    computerPatterns.append(randomNumber);
    computerPatterns.append(0);
    computerPatterns.append(0);
    computerPatterns.append(1);
    computerPatterns.append(0);
    computerPatterns.append(1);

    for(int pattern : computerPatterns)
    {
        displayPatterns(pattern);
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
    else if (pattern == 1)
    {
        emit displayRed("background-color: red");
    }
    else
    {

    }
    qDebug() << "timer...";
}

//void GameModel::gameLost()
//{
//    // disable all buttons
//    // disable everything on screen
//    // except "restart" button
//    // display YOU LOSE on screen with sound
//    // Try to make the game startable
//}


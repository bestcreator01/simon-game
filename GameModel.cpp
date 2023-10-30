#include <QDebug>
#include <QTimer>
#include <QPushButton>
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
//    int randomNumber = QRandomGenerator::global()->bounded(2);
//    computerPatterns.append(randomNumber);
    computerPatterns.append(0);
    computerPatterns.append(0);
    computerPatterns.append(1);
    computerPatterns.append(0);
    computerPatterns.append(1);

    int patternTime = 750;
    int originalTime = 1500;
    for(int pattern : computerPatterns)
    {
        QTimer::singleShot(patternTime, this, [=]() { displayPatterns(pattern);});
        QTimer::singleShot(originalTime, this, [=]() { displayOriginal(pattern);});

        patternTime += 1000;
        originalTime += 1000;
    }

    // enable red and blue buttons
    QTimer::singleShot(originalTime + 1000, this, [=]() { emit enableButtons(true);});
    //emit enableButtons(true);
}

void GameModel::checkPattern()
{
    // retrieve which button is clicked
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString buttonText = buttonSender->text();

    int i = 0;
    if (buttonText == "Blue")
    {
        if (computerPatterns[i] == 0)
        {

        }
        qDebug() << "blue button clicked";
        qDebug() << buttonText;
    }
    else
    {
        if (computerPatterns[i] == 1)
        {

        }

        qDebug() << "red button clicked";
        qDebug() << buttonText;

        i++;
    }
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
}

//void GameModel::gameLost()
//{
//    // disable all buttons
//    // disable everything on screen
//    // except "restart" button
//    // display YOU LOSE on screen with sound
//    // Try to make the game startable
//}


#include "GameModel.h"

GameModel::GameModel(QObject *parent)
    : QObject(parent)
{
    totalMoves = 1;
}

void GameModel::gameStarted()
{
    // basic setup
    emit enableStartButton(false);
    emit gameLost(false);
    emit updateProgressBar(0);

    currentMoves = 0;
    totalMoves = 0;
    currentIndex = 0;
    computerPatterns.clear();
    computerTurn();
}

void GameModel::computerTurn()
{
    // reset things
    emit enableButtons(false);

    // generate random pattern and append to computerPatterns
    int randomNumber = QRandomGenerator::global()->bounded(2);
    computerPatterns.append(randomNumber);

    // set up totalMoves
    totalMoves = computerPatterns.length();

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
    QTimer::singleShot(originalTime + 500, this, [=]() { emit enableButtons(true);});
}

void GameModel::playerTurn()
{
    checkPattern();
}

void GameModel::checkPattern()
{
    // retrieve which button is clicked
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString buttonText = buttonSender->text();

    if (currentIndex < computerPatterns.length())
    {
        if (buttonText == "Blue")
        {
            checkPatternHelper(0);
        }
        else
        {
            checkPatternHelper(1);
        }
    }
}

void GameModel::checkPatternHelper(int pattern)
{
    if (computerPatterns[currentIndex] == pattern)
    {
        if (currentIndex == computerPatterns.length() - 1)
        {
            // reset variables
            currentMoves = 0;
            currentIndex = 0;
//            emit updateProgressBar(100);
            computerTurn();
        }
        else
        {
            currentMoves++;
            currentIndex++;
//            updateProgress();
        }
    }
    else
    {
        emit gameLost(true);
        emit enableStartButton(true);
        emit enableButtons(false);
    }
}

void GameModel::updateProgress()
{
    int progress = (currentMoves / totalMoves) * 100;
    emit updateProgressBar(progress);
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

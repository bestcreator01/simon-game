#include "GameModel.h"

GameModel::GameModel(QObject *parent) : QObject(parent) {}

void GameModel::gameStarted()
{
    // basic setup
    emit enableStartButton(false);
    emit gameLost(false);
    emit updateProgressBar(0);

    // reset things
    currentMoves = 1;
    totalMoves = 0;
    currentIndex = 0;
    computerPatterns.clear();

    computerTurn();
}

void GameModel::computerTurn()
{
    // reset things
    emit enableButtons(false);
    currentMoves = 0;
    currentIndex = 0;
    QTimer::singleShot(750, this, [=]() { updateProgressBar(0);}); // update progress bar to 0


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
    // retrieve which button is clicked
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString buttonText = buttonSender->text();

    if (currentIndex < computerPatterns.length())
    {
        if (buttonText == "Blue")
        {
            checkPattern(0);
        }
        else
        {
            checkPattern(1);
        }
    }
}

void GameModel::checkPattern(int pattern)
{
    if (computerPatterns[currentIndex] == pattern)
    {
        currentMoves++;

        if (currentIndex == computerPatterns.length() - 1)
        {
            emit updateProgressBar(100);
            computerTurn();
        }
        else
        {
            currentIndex++;
            updateProgress();
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
    int progress = static_cast<int>((static_cast<double>(currentMoves) / totalMoves) * 100);
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

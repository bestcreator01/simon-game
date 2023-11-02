/*
Author:     Seoin Kim and Gloria Shin
Date:       Nov-1-2023
Course:     CS 3505, University of Utah
Assignment: A6: Qt Simon Game

File Contents
    This program works as the "model" header class of this game.
*/

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
    /**
     * @brief Constructs a GameModel object.
     * @param parent The parent QObject (optional).
     */
    explicit GameModel(QObject *parent = nullptr);

    /**
     * @brief Handles actions during the game.
     */
    void duringGame();

    /**
     * @brief Displays the specified pattern.
     * @param pattern The pattern to display.
     */
    void displayPatterns(int pattern);

    /**
     * @brief Displays the original pattern.
     * @param pattern The pattern to display.
     */
    void displayOriginal(int pattern);

    /**
     * @brief Initiates the computer's turn in the game.
     */
    void computerTurn();

public slots:
    /**
     * @brief Slot to handle the start of the game.
     */
    void gameStarted();

    /**
     * @brief Slot to handle the player's turn.
     */
    void playerTurn();

signals:
    /**
     * @brief Signal to enable or disable the start button.
     * @param enable True to enable, false to disable.
     */
    void enableStartButton(bool);

    /**
     * @brief Signal to enable or disable game buttons.
     * @param enable True to enable, false to disable.
     */
    void enableButtons(bool);

    /**
     * @brief Signal to show or hide the score label.
     * @param show True to show, false to hide.
     */
    void showScoreLabel(bool);

    /**
     * @brief Signal to show or hide the result label.
     * @param show True to show, false to hide.
     */
    void showResultLabel(bool);

    /**
     * @brief Signal to display blue color on the UI.
     * @param color The blue color value.
     */
    void displayBlue(QString color);

    /**
     * @brief Signal to display red color on the UI.
     * @param color The red color value.
     */
    void displayRed(QString color);

    /**
     * @brief Signal emitted when the game is lost.
     * @param lost True if the game is lost, false otherwise.
     */
    void gameLost(bool lost);

    /**
     * @brief Signal to update the progress bar.
     * @param value The new value for the progress bar.
     */
    void updateProgressBar(int value);

    /**
     * @brief Signal to update the score on the UI.
     * @param score The new score value.
     */
    void updateScore(QString score);

    /**
     * @brief Signal to update the result on the UI.
     * @param result The new result value.
     */
    void updateResult(QString result);

private:
    int currentMoves;
    int totalMoves;
    int currentIndex;
    int currentScore;
    QList<int> computerPatterns;

    /**
     * @brief Checks if the player's pattern matches the computer's pattern.
     * @param pattern The pattern to check.
     */
    void checkPattern(int pattern);

    /**
     * @brief Updates the progress of the game.
     */
    void updateProgress();
};

#endif // GAMEMODEL_H

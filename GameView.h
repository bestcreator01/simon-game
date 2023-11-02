/*
Author:     Seoin Kim and Gloria Shin
Date:       Nov-1-2023
Course:     CS 3505, University of Utah
Assignment: A6: Qt Simon Game

File Contents
    This program works as the "view" header class of this game.
*/

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "GameModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameView; }
QT_END_NAMESPACE

class GameView : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a GameView object.
     * @param model The GameModel to associate with this view.
     * @param parent The parent QWidget (optional).
     */
    GameView(GameModel& model, QWidget *parent = nullptr);

    /**
     * @brief Destroys the GameView object.
     */
    ~GameView();

public slots:
    /**
     * @brief Slot to play the background music.
     */
    void playBGM();

    /**
     * @brief Slot to stop the background music.
     */
    void stopBGM();

private:
    Ui::GameView *ui; ///< The user interface associated with this view.

    QMediaPlayer *bgm; ///< The background music player.
    QAudioOutput *bgmOutput; ///< The audio output for the background music.
};

#endif // GAMEVIEW_H

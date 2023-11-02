/*
 * Team Members: Seoin Kim and Gloria Shin
 * Github Usernames: seointhenerd, bestcreator01
 *
 * Additional Features:
 *  1. Spooky background music while playing the game (vanishes when player dies)
 *  2. Spooky pumpkin images on the background
 *  3. Score is shown while playing the game
 *  4. Score result shown when the player dies
 */

#include "GameView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameModel m;
    GameView w(m);
    w.show();
    return a.exec();
}

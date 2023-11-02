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
    GameView(GameModel& model, QWidget *parent = nullptr);
    ~GameView();
    void playMusic();

private:
    Ui::GameView *ui;
    QMediaPlayer *sound;
    QAudioOutput *audioOutput;
};
#endif // GAMEVIEW_H

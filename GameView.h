#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMainWindow>
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

public slots:
    void playBGM();
    void stopBGM();

private:
    Ui::GameView *ui;

    QMediaPlayer *bgm;
    QAudioOutput *bgmOutput;
};
#endif // GAMEVIEW_H

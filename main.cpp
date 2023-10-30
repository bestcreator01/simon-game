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

#include"play_window.h"
#include"head_window.h"
#include "land.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Head_Window *my_play = new Head_Window;
    my_play->setCurrentWidget(my_play->GetWindowMain());
    my_play->showMaximized();
    QObject::connect((my_play->GetPlayButton()), SIGNAL(clicked()), my_play, SLOT(toPlay()));// вывод окна игры
    QObject::connect((my_play->GetHelpButton()), SIGNAL(clicked()), my_play, SLOT(toHelp()));// вывод окна справки

    return a.exec();
}

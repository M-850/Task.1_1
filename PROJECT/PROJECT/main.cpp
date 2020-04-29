#include"play_window.h"
#include"head_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Head_Window *my_play = new Head_Window;
    my_play->setCurrentWidget(my_play->GetWindowMain());
    my_play->showMaximized();

    QObject::connect((my_play->GetPlayButton()),SIGNAL(clicked()), my_play, SLOT(toPlay()));

    return a.exec();
}

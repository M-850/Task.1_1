#include "head_window.h"
#include "play_window.h"
#include "myclient.h"
Head_Window::Head_Window()
{
    window_main = new QWidget;
    window_play = new Play_Window;
    window_help = new QWidget;
    play_button = new QPushButton("Играть", window_main);
    play_button->setGeometry(960,500,100,40);
    help_button=new QPushButton("Справка", window_main);
    help_button->setGeometry(960,550,100,40);
    QLabel *lb = new QLabel("Разработчик Михаил Михерский \n\nИгра 'Мусороперерабатывающий завод'",window_help);
    client = new MyClient("localhost", 2323);
    this->addWidget(window_main);
    this->addWidget(window_play);
    this->addWidget(window_help);
    this->addWidget(client);
}

void Head_Window::toPlay()
{
    this->setCurrentWidget(this->window_play);
}
QWidget* Head_Window::GetWindowHelp()
{
    return window_help;
}
void Head_Window::toHelp()
{
    this->setCurrentWidget(this->client);
}
QWidget* Head_Window::GetWindowMain()
{
    return window_main;
}
Play_Window* Head_Window::GetWindowPlay()
{
    return window_play;
}

QPushButton* Head_Window::GetPlayButton()
{
    return play_button;
}
QPushButton* Head_Window::GetHelpButton()
{
    return help_button;
}


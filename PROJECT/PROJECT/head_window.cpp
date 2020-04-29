#include "head_window.h"
#include "play_window.h"
Head_Window::Head_Window()
{
    window_main = new QWidget;
    window_play = new Play_Window;
    window_setting = new QWidget;
    QLabel *lb = new QLabel("Это окно работает",window_setting);
    play_button = new QPushButton("Играть", window_main);
    play_button->setGeometry(960,500,100,40);
    setting_button = new QPushButton("Настройки", window_main);
    setting_button->setGeometry(960,580,100,40);
    this->addWidget(window_main);
    this->addWidget(window_play);
    this->addWidget(window_setting);
}
void Head_Window::toPlay()
{
    this->setCurrentWidget(this->window_play);

}
void Head_Window::toSetting()
{
    this->setCurrentWidget(this->window_setting);
}
void Head_Window::toHelp()
{
    this->setCurrentWidget(this->window_help);
}
QWidget* Head_Window::GetWindowMain()
{
    return window_main;
}
Play_Window* Head_Window::GetWindowPlay()
{
    return window_play;
}
QWidget* Head_Window::GetWindowSetting()
{
    return window_setting;
}
QPushButton* Head_Window::GetPlayButton()
{
    return play_button;
}
QPushButton* Head_Window::SettingButton()
{
    return setting_button;
}

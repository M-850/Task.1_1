#ifndef HEAD_WINDOW_H
#define HEAD_WINDOW_H
#include<QtWidgets>
#include<play_window.h>
class Head_Window: public QStackedWidget
{
    Q_OBJECT
public:
    Head_Window();

QWidget* GetWindowMain();
Play_Window* GetWindowPlay();
QWidget* GetWindowSetting();
QPushButton *GetPlayButton();
QPushButton *SettingButton();
public slots:
    void toPlay();
public slots:
   // void toSetting();
    public slots:
    //void toHelp();
private:
    QWidget *window_main;
    Play_Window *window_play;
   // QWidget* window_help;
   // QWidget *window_setting;
    QPushButton *play_button;
   // QPushButton *setting_button;

};
#endif // HEAD_WINDOW_H

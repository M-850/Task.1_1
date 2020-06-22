 #ifndef HEAD_WINDOW_H
#define HEAD_WINDOW_H
#include<QtWidgets>
#include<play_window.h>
#include<myclient.h>
class Head_Window: public QStackedWidget
{
    Q_OBJECT
public:
    Head_Window();

QWidget* GetWindowMain();
QWidget* GetWindowHelp();
Play_Window* GetWindowPlay();
QPushButton* GetHelpButton();
QPushButton* GetPlayButton();
public slots:
    void toPlay();
    void toHelp();

private:
    QWidget *window_main;// главное окно
    Play_Window *window_play;// окно игры
    QWidget* window_help;// окно справки
    QPushButton *play_button;//кнопка играть
    QPushButton *help_button;//кнопка справки
    MyClient *client;
};
#endif // HEAD_WINDOW_H

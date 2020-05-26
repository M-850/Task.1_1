#ifndef WINDOW_LAND_H
#define WINDOW_LAND_H

#include<QtWidgets>
#include<QString>
#include<QCloseEvent>
#include<land.h>
#include<player.h>

class Land;
class Player;
class Window_Land:public QWidget
{
    Q_OBJECT
public:
    Window_Land(Land*,Player*, QWidget*);
    int get_plans();
    int get_services();
public slots:
    void show_new_plants();
    void show_new_services();
    void slot_button_enabel(bool,bool);
signals:
 //   void signal_clicked_button();
private:
    void closeEvent(QCloseEvent *event) override;
    QLabel* plans_and_service;
    QPushButton* button_plan;
    QPushButton* button_service;
    int plans;// кол-во заводов для отображения
    int services;//кол-во уборочных служб для отображения
    std::vector<QPushButton*> vec_button;
};


#endif // WINDOW_LAND_H

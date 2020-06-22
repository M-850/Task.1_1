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
public slots:
    void show_new_plants();// вывод изменённых данных при постройке завода
    void show_new_services();// вывод изменённых данных при создании службы уборки
    void slot_button_enabel(bool,bool);//   блокирует кнопки постройки завода и служб уборки,
                                      //    если параметрами приходит false соотвественно
    void slot_build_emit();//слот для передачи в build_a_factory_player_ параметров
signals:

    void signal_land(Land*);
private:

    QLabel* plans_and_service;//лейбл в котором выводится количество построенных заводов и служб уборки
    QPushButton* button_plan;//кнопка отвечающая за постройку завода
    QPushButton* button_service;//кнопка отвечающая за создание службы уборки
    Player* player_this;// указатель которому присваиваем указатель на передаваемого игрока
    Land* land_this;//указатель которому присваивается указатель на передаваемую страну

};


#endif // WINDOW_LAND_H

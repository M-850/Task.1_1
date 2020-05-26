#ifndef PLAYER_H
#define PLAYER_H
#include<vector>
#include"garbage_collection_service.h"
#include"garbage_recycling_plant.h"
#include<QtWidgets>
class Player: public QWidget
{
   Q_OBJECT
public:
    Player();
    int Get_money();
    int Get_id_();
    int Get_move_points();// возвращает кол-во очков
    void checking_the_objects_status();
    void Set_name(QString);
    QString Get_name();
public slots:
     void build_a_factory_player_();//солт постройки завода
     void service_create_player();// слот постройки завода
signals:
     void button_enabel_(bool,bool);// можно ли нажимать кнопки
     void play_set_info();
     void build_a_factory();
     void create_services();
private:
     QString str_name;
     bool check_plans;
     bool check_services;
    static int counter;
    int id_player_;
    int money;
    int sum_move_points;//сумма всех очков
    int activity_point;// сколко убывает за дейтсвие
    int move_plus_point;//сколько добавляется на каждый ход
    void minus_activity_points();//релизует убывание за дейтсвие
    int price_plant;//цена завода
    int price_services;//цена уборочной службы
    std::vector<Garbage_recycling_plant*> plants;
    std::vector<Garbage_collection_service*> services;
};


#endif // PLAYER_H

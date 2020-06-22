#ifndef LAND_H
#define LAND_H

#include "garbage_recycling_plant.h"
#include "garbage_collection_service.h"
#include "window_land.h"
#include "player.h"
#include<iostream>
#include<QString>
#include<vector>
#include<QtWidgets>
class Land:public QWidget
{
 Q_OBJECT
public:
    Land(int Land_red, int Land_green, int Land_blue, QString Land_name, int this_land_gabarge);
    QString Get_Land_name();
    int Get_Land_red();
    int Get_Land_green();
    int Get_Land_blue();
    int Get_Quantity_garbage();
    int Get_Quantity_plans();
    int Get_Quantity_services();
    int Get_Percent();
//    int Counting_garbage();
    void window_land(Player*, QPushButton*);
public slots:
    void create_services();
    void build_a_factory();
private:
    const int all_garbage;//весь мусор в мире
    int percent_this_land_garbage;//мусор в данной стране в проценнтном соотношении
    int this_land_garbage;//мусор в данной стране
    QString Land_name;// имя страны
    int Land_red;// компонета красного цвета
    int Land_green;// компонета зелёного цвета
    int Land_blue;// компонента синего цвета
    int Quantity_garbage; // общие кол-во мусора
    int real; // дейтсвительная переработка
    std::vector<Garbage_recycling_plant*> plants;// кол-во заводов в стране
    std::vector<Garbage_collection_service*> services;//кол-во служб уборки мусора

};

#endif // LAND_H

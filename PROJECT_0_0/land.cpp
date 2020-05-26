#include "land.h"
Land::Land(int Land_red, int Land_green, int Land_blue, QString Land_name, int Quantity_garbage)
{

    this->Land_red = Land_red;
    this->Land_blue = Land_blue;
    this->Land_green = Land_green;
    this->Land_name = Land_name;
    this->Quantity_garbage = Quantity_garbage;

}
QString Land::Get_Land_name()
{
    return this->Land_name;
}
int Land::Get_Land_red()
{
    return this->Land_red;
}
int Land::Get_Land_green()
{
    return this->Land_green;
}
int Land::Get_Land_blue()
{
    return this->Land_blue;
}
int Land::Get_Quantity_garbage()
{
    return this->Quantity_garbage;
}
int Land::Get_Quantity_plans()//сделать функциию такую же только для разных пользователей
{
    return plants.size();
}
int Land::Get_Quantity_services()
{
    return services.size();
}
void Land::window_land(Player* player_1, QPushButton *button_land)
{
   // int sdaf = player_1->id_player_;

   Window_Land* window_land = new Window_Land(this, player_1,0);

   button_land->setText("Выберити \n страну");
  // window_land->deleteLater();
//  disconnect(button_land,SIGNAL(clicked()), sender(), SLOT(Slots_clicked()));
}
void Land::build_a_factory()
{
    Garbage_recycling_plant *factory = new Garbage_recycling_plant;

    plants.push_back(factory);
}
void Land::create_services()
{
    Garbage_collection_service *service = new Garbage_collection_service;
    services.push_back(service);
}

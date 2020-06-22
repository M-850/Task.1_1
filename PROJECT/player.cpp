#include "player.h"

Player::Player():money(2000000),sum_move_points(90),activity_point(30),price_plant(500000),price_services(300000),player_profit(0)
{
 counter++;
 id_player_ = counter;
}
int Player::counter = 0;
int Player::Get_id_()
{
    return id_player_;
}
void Player::build_a_factory_player_(int precent,QString name_land,int this_land_garbage)
{
       this->money = this->money - this->price_plant;
       this->sum_move_points = this->sum_move_points - this->activity_point;
       Garbage_recycling_plant *factory = new Garbage_recycling_plant;

       factory->real(precent + this->services.size());
       player_profit =  factory->Set_profit(plants.size());
       plants.push_back(factory);
       this->checking_the_objects_status();
       emit play_set_info();
}
QString Player::Get_name()
{
    return str_name;
}
void Player::Set_name(QString name)
{
    this->str_name = name;
}
void Player::service_create_player()
{
    this->money = this->money - this->price_services;
    this->sum_move_points = this->sum_move_points - this->activity_point;
    Garbage_collection_service *service = new Garbage_collection_service;

    services.push_back(service);
    this->checking_the_objects_status();
    emit play_set_info();
}
void Player::minus_activity_points()
{
    sum_move_points = sum_move_points - activity_point;
}

int Player::Get_money()
{
    return this->money;
}
int Player::Get_move_points()
{
    return this->sum_move_points;
}
void Player::checking_the_objects_status()
{
    bool check_plans = true;
    bool check_service = true;
    if(this->money - this->price_plant < 0)
    {
        check_plans = false;
    }
    if(this->money - this->price_services < 0)
    {
        check_service = false;
    }
    if(this->sum_move_points - this->activity_point < 0)
    {
        check_plans = false;
        check_service = false;
    }
    emit button_enabel_(check_plans,check_service);// ОТСЮДА ИСПУСКАЕТСЯ СИГНАЛ
}
int Player::Get_Quantity_plans_()
{
    return plants.size();
}
int Player::Get_Quantity_services_()
{
    return services.size();
}
int Player::Get_profit()
{
    return this->player_profit;
}
void Player::Set_mony(int new_profit)
{
    this->money = this->money + new_profit;
}
void Player::Set_point(int value)
{
    this->sum_move_points = this->sum_move_points + value;
}

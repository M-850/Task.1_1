#ifndef GARBAGE_RECYCLING_PLANT_H
#define GARBAGE_RECYCLING_PLANT_H
#include<QString>

class Garbage_recycling_plant
{
public:
    Garbage_recycling_plant();
    void Set_land_name_(QString);
    QString Get_land_name_();
    int Get_max();
    int real(int);
    int real_value;
    int profit;// прибыль от завода
    int Set_profit(int);// установка прибыли
private:
    int all_garbage;//весь мусор
    int percent_garbage_;//
    int max;// максимальная переработка
    QString land_name_;//название страны в которой построен завод
   // int price;//цена

};

#endif // GARBAGE_RECYCLING_PLANT_H

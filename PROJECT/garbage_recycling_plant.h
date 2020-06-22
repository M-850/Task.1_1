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
    int Set_profit(int);// установка прибыли
private:
    int profit;// прибыль от завода
    int real_value;//реальная переработка
    int all_garbage;//весь мусор 
    int max;// максимальная переработка
    QString land_name_;//название страны в которой построен завод

};

#endif // GARBAGE_RECYCLING_PLANT_H

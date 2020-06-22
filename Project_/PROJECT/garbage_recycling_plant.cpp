#include "garbage_recycling_plant.h"

Garbage_recycling_plant::Garbage_recycling_plant(): max(5000)
{

}
void Garbage_recycling_plant::Set_land_name_(QString name_)
{
     this->land_name_ = name_;
}
QString Garbage_recycling_plant::Get_land_name_()
{
     return this->land_name_;
}

int Garbage_recycling_plant::real(int percent)
{
     this->real_value = max * 4 * percent / 100;
     return real_value;
}
int Garbage_recycling_plant::Set_profit(int quanti)
{
     this->profit = (real_value / 5)*100;
     if(quanti < 10 || quanti > 50)
     {
       this->profit = this->profit - quanti;
     }
     else if(quanti <= 50)
     {
         this->profit = this->profit - (quanti / 2);
     }
     return this->profit;
}


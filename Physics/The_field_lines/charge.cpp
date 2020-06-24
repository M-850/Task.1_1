#include "charge.h"
#define Pi 3.1425926
#define k 9*1000000000
Charge::Charge(int center_x, int center_y, float q_): R(10), check(false)
{
    this->centerX = center_x;
    this->centerY = center_y;
    this->quantity = quantity;
    this->q = q_;

}
void Charge::paint_charge()
{

        glColor3f(1.0f,0.0f,0.0f);

        int no_newX = this->centerX;
        int no_newY = this->centerY + R;
                      for(int i = 0; i <= 50; i++)
                      {
                          float newX = this->centerX + R*sin(Pi*2*i/50);
                          float newY = this->centerY - R*cos(Pi*2*i/50);
                         glBegin( GL_TRIANGLES);

                         glVertex2f(this->centerX,this->centerY);
                         glVertex2f(no_newX,no_newY);
                         glVertex2f(newX,newY);

                         glEnd();
                           no_newX = newX;
                           no_newY = newY;
                      }
}

int Charge::Get_centerX()
{
    return this->centerX;
}
int Charge::Get_centerY()
{
    return this->centerY;
}
int Charge::Get_R()
{
    return this->R;
}
 bool Charge::Get_check()
{
    return  check;
}
void Charge::Set_centerX(int center_x)
{
    this->centerX= center_x;
}
void Charge::Set_centerY(int center_y)
{
    this->centerY = center_y;
}
void Charge::Set_check(bool check_)
{
    check = check_;
}
int Charge::Get_point_1_x()
{
    return point_1_x;
}
int Charge::Get_point_1_y()
{
    return point_1_y;
}
int Charge::Get_point_2_x()
{
    return point_2_x;
}
int Charge::Get_point_2_y()
{
    return point_2_y;
}
float Charge::E_x_(int x , int y)
{
    return this->E_x = (k*q*(x-this->centerX))/pow(pow((x-this->centerX),2)+pow((y-this->centerY),2),3/2);
}
float Charge::E_y_(int x, int y)
{
    return this->E_y = (k*q*(y-this->centerY))/pow(pow((x-this->centerX),2)+pow((y-this->centerY),2),3/2);
}

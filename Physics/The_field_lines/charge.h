#ifndef CHARGE_H
#define CHARGE_H
#include <QGLWidget>
#include <math.h>
#include<vector>
class Charge
{

public:
    Charge(int,int,float);
     void paint_charge();
     void update_charge();
     int Get_centerX();
     int Get_centerY();
     int Get_R();
     int Get_point_1_x();
     int Get_point_1_y();
     int Get_point_2_x();
     int Get_point_2_y();
     bool Get_check();
     void Set_centerX(int);
     void Set_centerY(int);
     void Set_check(bool);
     float E_x_(int,int);
     float E_y_(int,int);
private:
   float E_x;
   float E_y;
   int distance;
   float q;
   int quantity;
   std::vector<int> points_x;
   std::vector<int> points_y;
   int point_1_x;
   int point_1_y;
   int point_2_x;
   int point_2_y;
   int R;
   int centerX;
   int centerY;
   bool check;
};

#endif // CHARGE_H

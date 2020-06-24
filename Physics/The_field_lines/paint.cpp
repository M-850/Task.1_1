#include "paint.h"
#define Pi 3.1415926
#define  steps 50
#define  angel Pi*2/steps
#define k 9*1000000000
Paint::Paint(QWidget* pwgt/*= 0*/) : QGLWidget(pwgt), delta_L(5)
{
    charge_1 = new Charge(100,250,10);
    charge_2 = new Charge(400,250,-10);

}
void Paint::initializeGL()
{
    glClearColor(0,1,0,0);
}
void Paint::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,(GLint) w,(GLint) h);
    glOrtho(0,500,500,0,-1,1);
}
void Paint::paintGL()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
charge_1->paint_charge();
charge_2->paint_charge();
glColor3f(0.0f,0.0f,1.0f);



for(size_t i = 0; i < 99; ++i)
    {
    this->x = charge_1->Get_centerX() + charge_1->Get_R()*sin(2*Pi*i/99);
    this->y = charge_1->Get_centerY() + charge_1->Get_R()*cos(2*Pi*i/99);


for(int i = 1; i < 1000 ; i++)
{
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y);
    E = pow(pow(charge_1->E_x_(x,y)+charge_2->E_x_(x,y),2) + pow(charge_1->E_y_(x,y)+charge_2->E_y_(x,y),2),0.5);
    x = x + (delta_L*(charge_1->E_x_(x,y)+charge_2->E_x_(x,y)))/E;
    y = y + (delta_L*(charge_1->E_y_(x,y)+charge_2->E_y_(x,y)))/E;

    float rb = pow(pow(x-charge_2->Get_centerX(),2) + pow(y-charge_2->Get_centerY(),2),0.5);
    if(rb < charge_2->Get_R())
    {
        break;
    }
}
glEnd();
}
}



void Paint::mousePressEvent(QMouseEvent* pe)
{
    if(pe->x() < charge_1->Get_centerX() + charge_1->Get_R() && pe->x() > charge_1->Get_centerX() - charge_1->Get_R() && pe->y() < charge_1->Get_centerY() + charge_1->Get_R() && pe->y() > charge_1->Get_centerY() - charge_1->Get_R())
    {
    charge_1->Set_centerX(pe->x());
    charge_1->Set_centerY(pe->y());
    charge_1->Set_check(true);
    updateGL();
    }
    if(pe->x() < charge_2->Get_centerX() + charge_2->Get_R() && pe->x() > charge_2->Get_centerX() - charge_2->Get_R() && pe->y() < charge_2->Get_centerY() + charge_2->Get_R() && pe->y() > charge_2->Get_centerY() - charge_2->Get_R())
    {
    charge_2->Set_centerX(pe->x());
    charge_2->Set_centerY(pe->y());
    charge_2->Set_check(true);
    updateGL();
    }

}
void Paint::mouseReleaseEvent(QMouseEvent *pe)
{
            charge_1->Set_check(false);
            charge_2->Set_check(false);
}
void Paint::mouseMoveEvent(QMouseEvent* pe)
{
    if(charge_1->Get_check() == true)
    {
    charge_1->Set_centerX(pe->x());
    charge_1->Set_centerY(pe->y());
    updateGL();
    }
    if(charge_2->Get_check() == true)
    {
    charge_2->Set_centerX(pe->x());
    charge_2->Set_centerY(pe->y());
    updateGL();
    }
}

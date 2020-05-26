#include "window_land.h"
Window_Land::Window_Land(Land *land, Player *player, QWidget *parent=0):QWidget(parent)
{
    button_plan = new QPushButton("Построить завод");
    button_service = new QPushButton("Создать свою \n службу уборки");
    connect(player, SIGNAL(button_enabel_(bool, bool)), this, SLOT(slot_button_enabel(bool, bool)));
    player->checking_the_objects_status();
    plans_and_service = new QLabel;
    plans = land->Get_Quantity_plans();
    services = land->Get_Quantity_services();
    this->setWindowTitle("Игрок "+ QString::number(player->Get_id_()));
   // int id = player->id_player_;
    plans_and_service->setText("Посторенные заводы:"+QString::number(plans)
                               +"\n"+
                               "Количетсво служб уборки:"+QString::number(services)
                               +"\n"+
                               "Игрок " + player->Get_name());

    plans_and_service->setStyleSheet("background-color: red");
   // plans_and_service->setMinimumSize(1800,500);
    plans_and_service->setMaximumSize(1920,800);


    button_plan->setMinimumSize(120,30);
    button_plan->setMaximumSize(210,70);
    vec_button.push_back(button_plan);
    connect(vec_button[0],SIGNAL(clicked()),player, SLOT(build_a_factory_player_()));
    connect(vec_button[0],SIGNAL(clicked()), land,SLOT(build_a_factory()));
    connect(vec_button[0],SIGNAL(clicked()), this,SLOT(show_new_plants()));
    //connect(button_plan,SIGNAL(ckicked()),player_1,SLOT(build_a_factory()));
  //  connect(button_plan,SIGNAL(clicked()),)

    button_service->setMinimumSize(120,30);
    button_service->setMaximumSize(210,70);
    connect(button_service,SIGNAL(clicked()), player,SLOT(service_create_player()));
    connect(button_service,SIGNAL(clicked()), land,SLOT(create_services()));
    connect(button_service,SIGNAL(clicked()), this,SLOT(show_new_services()));
    vec_button.push_back(button_service);
    connect(player,SIGNAL(button_enabel_(bool,bool)),this,SLOT(slot_button_enabel(bool,bool)));
    QGridLayout* Location = new QGridLayout;
    Location->setRowStretch(1,10);
    Location->setRowMinimumHeight(1,300);
    Location->setColumnMinimumWidth(0,150);
    Location->setRowMinimumHeight(0,150);
    Location->setColumnMinimumWidth(3,150);
    Location->setRowMinimumHeight(1,150);
    Location->addWidget(button_plan,0,0,Qt::AlignTop);
    Location->addWidget(button_service,0,3,Qt::AlignTop);
    Location->addWidget(plans_and_service,1,0,1,4,Qt::AlignTop);
    this->setLayout(Location);
    this->show();

}
//void Window_Land::win_delete()
//{
//    this->deleteLater();
//}

void Window_Land::closeEvent(QCloseEvent *event)
{
    this->deleteLater();
}
 void Window_Land::show_new_plants()
 {
     this->plans++;
      //this->services++;
      plans_and_service->setText("Посторенные заводы:"+QString::number(get_plans())
                                 +"\n"+
                                 "Количетсво служб уборки:"+QString::number(get_services()));

      this->show();
 }
 void Window_Land::show_new_services()
 {
     this->services++;
     plans_and_service->setText("Посторенные заводы:"+QString::number(get_plans())
                                +"\n"+
                                "Количетсво служб уборки:"+QString::number(get_services()));
     this->show();
 }
 int  Window_Land::get_plans()
 {
     return this->plans;
 }
 int Window_Land::get_services()
 {
     return this->services;
 }
void Window_Land::slot_button_enabel(bool check_plans_,bool check_service_)
{
   this->button_plan->setEnabled(check_plans_);

   this->button_service->setEnabled(check_service_);
}

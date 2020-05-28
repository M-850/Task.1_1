#include "window_land.h"
Window_Land::Window_Land(Land *land, Player *player, QWidget *parent=0):QWidget(parent)
{
    player_this = player;
    land_this = land;
    button_plan = new QPushButton("Построить завод");
    button_service = new QPushButton("Создать свою \n службу уборки");
    connect(player_this, SIGNAL(button_enabel_(bool, bool)), this, SLOT(slot_button_enabel(bool, bool)));
    player_this->checking_the_objects_status();
    plans_and_service = new QLabel;
    this->setWindowTitle(land_this->Get_Land_name());
    plans_and_service->setText("Общее количество посторенных заводов в стране: " + QString::number(land_this->Get_Quantity_plans())
                               +"\n"+
                               "Общее количество служб уборки в стране: " + QString::number(land_this->Get_Quantity_services())
                               +"\n"+
                               +"\n"+
                               "Количество построенных заводов у " + player_this->Get_name() + " в мире: " + QString::number(player_this->Get_Quantity_plans_())
                               +"\n"+
                               "Количество служб уборки у " + player_this->Get_name() + " в мире: " + QString::number(player_this->Get_Quantity_services_()));

    plans_and_service->setStyleSheet("background-color: green");
    plans_and_service->setMaximumSize(1920,800);
    button_plan->setMinimumSize(120,30);
    button_plan->setMaximumSize(210,70);
    connect(button_plan,SIGNAL(clicked()), this,SLOT(slot_build_emit()));
    connect(button_plan,SIGNAL(clicked()), land_this,SLOT(build_a_factory()));
    connect(button_plan,SIGNAL(clicked()), this,SLOT(show_new_plants()));

    button_service->setMinimumSize(120,30);
    button_service->setMaximumSize(210,70);
    connect(button_service,SIGNAL(clicked()), player_this,SLOT(service_create_player()));
    connect(button_service,SIGNAL(clicked()), land_this,SLOT(create_services()));
    connect(button_service,SIGNAL(clicked()), this,SLOT(show_new_services()));
    connect(player_this,SIGNAL(button_enabel_(bool,bool)),this,SLOT(slot_button_enabel(bool,bool)));
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

void Window_Land::closeEvent(QCloseEvent *event)
{
    this->deleteLater();
}
 void Window_Land::show_new_plants()
 {
      plans_and_service->setText("Общее количество посторенных заводов в стране: " + QString::number(land_this->Get_Quantity_plans())
                                 +"\n"+
                                 "Общее количество служб уборки в стране: " + QString::number(land_this->Get_Quantity_services())
                                 +"\n"+
                                 +"\n"+
                                 "Количество построенных заводов у " + player_this->Get_name() + " в мире: " + QString::number(player_this->Get_Quantity_plans_())
                                 +"\n"+
                                 "Количество служб уборки у " + player_this->Get_name() + " в мире: " + QString::number(player_this->Get_Quantity_services_()));

      this->show();
 }
 void Window_Land::show_new_services()
 {
     plans_and_service->setText("Общее количество посторенных заводов в стране: " + QString::number(land_this->Get_Quantity_plans())
                                +"\n"+
                                "Общее количество служб уборки в стране: " + QString::number(land_this->Get_Quantity_services())
                                +"\n"+
                                +"\n"+
                                "Количество построенных заводов у " + player_this->Get_name() + " в мире: " + QString::number(player_this->Get_Quantity_plans_())
                                +"\n"+
                                "Количество служб уборки у " + player_this->Get_name() + " в мире: " + QString::number(player_this->Get_Quantity_services_()));
     this->show();
 }

void Window_Land::slot_button_enabel(bool check_plans_,bool check_service_)
{
   this->button_plan->setEnabled(check_plans_);

   this->button_service->setEnabled(check_service_);
}
void Window_Land::slot_build_emit()//слот для передачи в build_a_factory_player_ параметров
{
    player_this->build_a_factory_player_(land_this->Get_Percent(),land_this->Get_Land_name(),land_this->Get_Quantity_garbage());
}

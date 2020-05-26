#include "play_window.h"
Play_Window::Play_Window():counter_move(0)
{
    button_land = new QPushButton("Выберите \n страну",this);
    button_land->setGeometry(0,0,100,50);
    button_move = new QPushButton("Ход",this);
    button_move->setGeometry(100,0,100,50);
   // player_1= new Player;
    for(size_t i = 0; i < 4; i++)
    {
        Player* player_1 = new Player;
        player_1->Set_name("Мистер бизнесмен"+QString::number(i));
        players.push_back(player_1);
    }
    player_=players[0];// захаркодил надо исправить
    connect(button_move,SIGNAL(clicked()),this,SLOT(Slot_move()));
    connect(player_,SIGNAL(play_set_info()),this,SLOT(Slot_set_info()));
    this->lb_map = new QLabel(this);
    lb_map->setMargin(0);
    lb_informational = new QLabel(this);
    lb_informational->setGeometry(200,0,1770,50);
    lb_informational->setStyleSheet("background-color:silver");
    lb_informational->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    lb_informational->setLineWidth(5);
    lb_informational->setText("\t\t\t\tКапитал:  "+QString::number(player_->Get_money())+"$\t\t\t\t"
                             +"Очки хода:  " + QString::number(player_->Get_move_points())+"\t\t\t\t"
                             +"Игрок:  " + player_->Get_name());

 //   lb_map->setScaledContents(true);//растягивает на карту на весь лейбл
    Russia = new Land(6,19,255,"Россия",1000);
    lands.push_back(Russia);
    China = new Land(255,127,39,"Китай",2000);
    lands.push_back(China);
    Mongolia = new Land(153,217,234,"Монголия",900);
    lands.push_back(Mongolia);
  //  lb_map->setStyleSheet("background-color: gray");


 //  players.push_back(player_1);
   // button_land->setText("world!");
}
void Play_Window::paintEvent(QPaintEvent *event )
{
    QRect rect(100,30,this->width(),this->height());
    this->lb_map->setGeometry(rect);


    this->map.load("\\PROJECT\\Map_4.png");
    QPixmap p;
    lb_map->setPixmap(p.fromImage(map));

}
//void Play_Window::window_land(Land* land)
//{
//    Land* temp_land = land;
//   Window_Land* window_land = new Window_Land(temp_land);
//}
void Play_Window::mousePressEvent(QMouseEvent *event)
{
   // смотреть по id игрока и вызывать window_land() для этого игрока
    bool check = false;
   QRgb rgb = map.pixel(event->x()-100,event->y()-43);
   QColor color(rgb);
for (size_t i = 0; i < lands.size();i++)
   if(color.red() == lands[i]->Get_Land_red() && color.green() == lands[i]->Get_Land_green() && color.blue() == lands[i]->Get_Land_blue())
   {
       check = true;
       button_land->setText(lands[i]->Get_Land_name());
       str_land = lands[i]->Get_Land_name();

       connect(button_land,SIGNAL(clicked()),this,SLOT(Slots_clicked()));
      // disconnect(button_land,SIGNAL(clicked()),this,SLOT(Slots_clicked()));
       break;
   }
//   else if(color.red() == China->Get_Land_red() && color.green() == China->Get_Land_green() && color.blue() == China->Get_Land_blue())
//   {
//       button_land->setText(China->Get_Land_name());
//       str_land = China->Get_Land_name();
//       connect(button_land,SIGNAL(clicked()),China,SLOT(window_land()));
//   }
//   else if(color.red() == Mongolia->Get_Land_red() && color.green() == Mongolia->Get_Land_green() && color.blue() == Mongolia->Get_Land_blue())
//   {
//       button_land->setText(Mongolia->Get_Land_name());
//       str_land = Mongolia->Get_Land_name();
//       connect(button_land,SIGNAL(clicked()),Mongolia,SLOT());
//   }
   if(!check)
   {
    button_land->setText("x " + QString::number(event->x()) + "y " + QString::number(event->y()) +
               "\n red " + QString::number( color.red()) +
               "\n green " + QString::number( color.green()) +
               "\n blue " + QString::number(color.blue()));
   }

}
//void Play_Window::Signal_clicked(Player* players);

QPushButton* Play_Window::Get_button_land()
{
    return button_land;
}
 void Play_Window::Slots_clicked()
 {
     //цикл проверяющий названия всех стран
     for(size_t i = 0; i < lands.size(); i++)
     {
        if(this->str_land == lands[i]->Get_Land_name())
        {

            lands[i]->window_land(player_,button_land);
            disconnect(button_land,SIGNAL(clicked()),this,SLOT(Slots_clicked()));
           //connect(this,SIGNAL(Signal_clicked(this->player_1)),lands[i],SLOT(window_land(this->player_1)));
        }
     }
 }
void Play_Window::Slot_set_info()
{
    lb_informational->setText("\t\t\t\tКапитал:  "+QString::number(player_->Get_money())+"$\t\t\t\t"
                             +"Очки хода:  " + QString::number(player_->Get_move_points())+"\t\t\t\t"
                              +"Игрок:  " + player_->Get_name());
}
void Play_Window::Slot_move()
{

    disconnect(player_,SIGNAL(play_set_info()),this,SLOT(Slot_set_info()));
    if(counter_move < 3)
    {
        counter_move++;
    }
    else
    {
        counter_move = 0;
    }
    player_= players[counter_move];
    connect(player_,SIGNAL(play_set_info()),this,SLOT(Slot_set_info()));
    emit player_->play_set_info();
}

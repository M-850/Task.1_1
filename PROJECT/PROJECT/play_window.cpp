#include "play_window.h"

Play_Window::Play_Window()
{
    this->lb = new QLabel(this);
    b = new QPushButton("hello",this);
    b->setGeometry(0,0,100,100);
    b->setText("world!");
}
void Play_Window::paintEvent(QPaintEvent *event )
{
    QRect rect(0,0,this->width(),this->height());
    this->lb->setGeometry(rect);
    this->map.load("\\PROJECT\\Map.png");
    QPixmap p;
    lb->setPixmap(p.fromImage(map));

}
void Play_Window::mousePressEvent(QMouseEvent *event)
{
   QRgb rgb = map.pixel(event->x(),event->y());
   QColor color(rgb);

    b->setText("x " + QString::number(event->x()) + "y " + QString::number(event->y()) +
               "\n red " + QString::number( color.red()) +
               "\n green " + QString::number( color.green()) +
               "\n blue " + QString::number(color.blue()));


}

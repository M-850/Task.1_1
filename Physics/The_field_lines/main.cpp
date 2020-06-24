#include <QWidget>
#include "paint.h"
#include <QApplication>
#include<QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel* lb = new QLabel;
    lb->resize(500,500);
    Paint paint(lb);
   // paint.resize(500,500);
    paint.setGeometry(0,0,500,500);
    lb->show();

    return a.exec();
}

#ifndef PLAY_WINDOW_H
#define PLAY_WINDOW_H


#include<QtWidgets>
#include<QPainter>
#include<QString>
#include "land.h"
#include "window_land.h"
#include "player.h"
#include <vector>
class Play_Window: public QWidget
{
    Q_OBJECT
public:

    Play_Window();
    QPushButton* Get_button_land();
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
//public slots:
   // void window_land(Land*);
signals:
    void Signal_clicked(Player*);

public slots:
    void Slots_clicked();
    void Slot_set_info();
    void Slot_move();
private:
    int counter_move;
    QLabel* lb_map;
    QLabel* lb_informational;
    QPushButton* button_land;
    QPushButton* button_move;
    QImage map;
    Land* Russia;
    Land* China;
    Land* Mongolia;
    QString str_land;
//    std::vector<Player*>players;
    std::vector<Land*> lands;
    std::vector<Player*> players;
    Player* player_;
  //  Player* player_1;
};
#endif // PLAY_WINDOW_H

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
signals:
    void Signal_clicked(Player*);

public slots:
    void Slots_clicked();
    void Slot_set_info();
    void Slot_move();
private:
    int counter_move;// посчёт количеств нажатия на кнопку хода
    QLabel* lb_map;// лейбл на который ставится карта
    QLabel* lb_informational;//лейбл вывода информации о игроке
    QPushButton* button_land;//кнопка выводящяя окно страны
    QPushButton* button_move;// кнопка хода
    QImage map;// карта
    Land* Russia;// объекты страны мира
    Land* China;
    Land* Mongolia;
    Land* USA;
    Land* Japan;
    Land* Brazil;
    Land* Canada;
    Land* India;
    QString str_land;// хранит название текущей выбранной пользователем страны
    std::vector<Land*> lands;// вектор хранящий все доступные страны в игре
    std::vector<Player*> players;//вектор хранящий всех игроков в игре
    Player* player_;// указатель хранящий адрес на текущего игрока
};
#endif // PLAY_WINDOW_H

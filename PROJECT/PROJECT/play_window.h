#ifndef PLAY_WINDOW_H
#define PLAY_WINDOW_H
#include<QtWidgets>
#include<QPainter>

class Play_Window: public QWidget
{
    Q_OBJECT
public:

    Play_Window();
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    QLabel* lb;
    QPushButton* b;
    QImage map;
};

#endif // PLAY_WINDOW_H

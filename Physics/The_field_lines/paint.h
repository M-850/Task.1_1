#ifndef PAINT_H
#define PAINT_H
#include <QGLWidget>
#include <QMouseEvent>
#include<math.h>
#include<charge.h>
class Paint: public QGLWidget
{
    Q_OBJECT
protected:
    virtual void mousePressEvent(QMouseEvent*)override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void mouseReleaseEvent(QMouseEvent*)override;
    virtual void initializeGL() override;
    virtual void resizeGL(int, int) override;
    virtual void paintGL() override;
public:
   Paint(QWidget* pwgt = 0);
private:
   int E;
   float x;
   float y;
   int result_L_x;
   int result_L_y;
   int delta_L;
   Charge *charge_1;
   Charge *charge_2;
};


#endif // PAINT_H

#ifndef TIMER_H
#define TIMER_H
#include <QFont>
#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QPixmap>

class Timer : public QMainWindow
{
    Q_OBJECT
public:
    explicit Timer(QWidget *parent = nullptr);
    double timetoover=-1;//倒计时的时间
    double timerace;//竞速时间设置
    int timer_x;//初始坐标
    int timer_y;
    QFont font;
//    void updateCountdown();
//    QTimer *timer;
//    void paintEvent(QPaintEvent *event);
    QPixmap clock;
    int counter;//用于计数，使用一个计时器来实现时钟倒计时

signals:

public slots:
};

#endif // TIMER_H

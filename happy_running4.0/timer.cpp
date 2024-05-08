#include "timer.h"
#include <QPainter>
#include <QPixmap>
#include <mainwindow.h>

Timer::Timer(QWidget *parent) : QMainWindow(parent)
{
    timer_x =1250;
    timer_y =50;
    QPixmap clock;
    clock.load(TIMER_PICTURE);
    font = QFont("Comic Sans MS", 24, QFont::Bold);
    counter = 0;
}


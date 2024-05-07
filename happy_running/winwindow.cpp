#include "winwindow.h"
#include "config.h"
#include <QDebug>
#include <QCoreApplication>
Winwindow::Winwindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("ABOUT US");//修改标题
    setFixedSize(947, 720);
    win_pix.load(WIN_PIC);//游戏结束图片

    timer.start(15);

    connect(&timer,QTimer::timeout,this,[=](){
        update();
    });
}

void Winwindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.drawPixmap(0, y--, win_pix);
    if(y == -1330)
      QCoreApplication::quit();
}

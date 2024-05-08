#include "Winner.h"
#include "config.h"
#include <QPixmap>
#include <QDebug>
#include <QCoreApplication>
#include <QPainter>
#include <QMainWindow>
#include "mainwindow.h"
Winner::Winner(QWidget *parent) : QMainWindow(parent)
{
    setAttribute(Qt::WA_DeleteOnClose, false); // 禁用自动删除
    setWindowTitle("Game Results");//设置标题
    setFixedSize(1366, 728);//设置窗口大小
    winner_pix.load(WINNER_PICTURE);//双人游戏结束初界面
timer.start(15);

connect(&timer,QTimer::timeout,this,[=](){
    update();
});
exitbutton = new QPushButton(this);
exitbutton->move(1040,528);
exitbutton->setFlat(false);
exitbutton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
exitbutton->setIcon(QIcon("://picture/pushButton.png"));
exitbutton->setIconSize(QSize(300, 200)); // 设置图片的大小
exitbutton->setFixedSize(300,200);

// 禁用关闭按钮
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
}
void Winner::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0, 0, winner_pix);
            QFont font;
            font = QFont("Comic Sans MS", 48, QFont::Bold);
            painter.setFont(font);//设置字体和颜色
            painter.setPen(Qt::white);


            painter.setFont(font);//设置字体和颜色
            painter.setPen(Qt::blue);
            if(winnerplayer==true)
            {
                painter.drawText(winnername_x,winnername_y,"Player1 !");
            }
            if(winnerplayer==false)
            {
                painter.drawText(winnername_x,winnername_y,"Player2 !");
            }


            painter.setFont(font);//设置字体和颜色
            painter.setPen(Qt::blue);
            painter.drawText(winnertime_x,winnertime_y,QString::number(score));
}

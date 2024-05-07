#include "intro.h"
#include <QScreen>
#include <QApplication>
intro::intro(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Introduction");//设置标题

    setFixedSize(1280, 720);//设置窗口大小
    intro_pix.load("://picture/introduction.png");//双人游戏结束初界面
timer.start(15);
    QScreen *screen=QGuiApplication::primaryScreen ();//获取主屏幕
    QRect mm=screen->availableGeometry() ;//返回屏幕可用几何图形大小
    int screen_width = mm.width();//屏幕宽度
    int screen_height = mm.height();//屏幕高度
move (( screen_width- width())/2,
            ( screen_height- height())/2);//让窗口始终居中显示
connect(&timer,&QTimer::timeout,this,[=](){
    update();
});
}
void intro::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0, 0, intro_pix);
}

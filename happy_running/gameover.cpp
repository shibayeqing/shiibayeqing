#include "gameover.h"
#include "config.h"
#include <QLabel>

Gameover::Gameover(QWidget *parent) : QMainWindow(parent)
{

    setFixedSize(1280, 720);
    setWindowTitle("GAME OVER!");          //修改标题
    StartAgain = new Changecolourbutton(this);
    StartAgain->yellow.load(YELLOWBUTTON);
    StartAgain->red.load(REDBUTTON);
    StartAgain->move(400,490);




//  StartAgain->setText("2"); // 设置按钮文本
//  StartAgain->setFont(StartAgain->font);


    gameover_pix.load(Gameover_PICTURE);//游戏结束图片
    gameover_x=((WIDTH-Gameover_WIDTH)/2);
    gameover_y=((WIDTH-Gameover_WIDTH)/2);

    timer.start(10);

    connect(&timer,QTimer::timeout,this,[=](){
        update();
    });

}
void Gameover::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    QPixmap backgroundImage(Gameover_PICTURE);//设置背景图
    QPixmap timeup(TIMEUP_TEXT);
    QPixmap youdied(YOUDIED_TEXT);//设置背景图
    painter.drawPixmap(0, 0, backgroundImage);

    if(type == 0)
        painter.drawPixmap(100, 0,timeup);
    else
        painter.drawPixmap(100, 0, youdied);


}

#include "turtle.h"
#include"config.h"
Turtle::Turtle(QWidget *parent) : QWidget(parent)
{
    turtle_x=turtle_left;//设置乌龟初始位置                  //此处改动
    turtle_y=HEIGHT-GROUND_WIDTH-TURTLE_HEIGHT-30;
    timer.start(TURTLE_CHANGE_PIX);//启动乌龟切图的定时器
    connect(&timer,QTimer::timeout,[=](){
        if(turtle_rfree==false){//控制乌龟向右边走时的切图
    QString str=QString(TURTLE_RPICTURE).arg(turtle_rbiao++);
    turtle_pix.load(str);
    if(turtle_rbiao==12){
        turtle_rbiao=0;
       }
        }

        if(turtle_lfree==false){//控制乌龟向左边走时的切图
    QString str=QString(TURTLE_PICTURE).arg(turtle_lbiao++);
    turtle_pix.load(str);
    if(turtle_lbiao==12){
        turtle_lbiao=0;
       }
        }
        //设置矩形的长宽，用于碰撞检测
        turtle_rec.setWidth(turtle_pix.width());
        turtle_rec.setHeight(turtle_pix.height());
    });
}

void Turtle::moving()
{

    timer2.start(TURTLE_MOVE);
    connect(&timer2,QTimer::timeout,[=](){
        if(turtle_rfree==false){
            turtle_x+=20;//每次移动20像素
            if(turtle_x>=turtle_left+300)
            {turtle_rfree=true;
            turtle_lfree=false;}
        }
        if(turtle_lfree==false)
            turtle_x-=20;//每次移动20像素
        if(turtle_x<=turtle_left)                       //此处改动
        {turtle_lfree=true;
         turtle_rfree=false;}
        //改变矩形的位置用于碰撞检测
        turtle_rec.moveTo(turtle_x,turtle_y);
    });
}
void Turtle::tread()//乌龟被踩函数
{
  //  timer3.start(TURTLE_MOVE);//借用一下这个时间间隔
    connect(&timer3,QTimer::timeout,[=](){
    if(turtle_isroll==true&&rolltime<20){
        rolltime++;
        timer.stop();
        timer2.stop();
        turtle_pix.load(TURTLE_ROLL);
        if(rolltime==20){
            turtle_isroll=false;
            rolltime=0;
            timer.start(TURTLE_CHANGE_PIX);
            timer2.start(TURTLE_MOVE);
            timer3.stop();
            turtle_y-=30;
        }
    }

   });
}

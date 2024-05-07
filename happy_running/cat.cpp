#include "cat.h"
#include "config.h"
#include <QTimer>
#include <QPixmap>
#include <QMainWindow>
#include <QPainter>
#include<QDebug>
cat::cat(QWidget *parent) : QMainWindow(parent)
{
    cat_x=100;//设置猫初始位置
    fakecat_x=100;

    cat_y=HEIGHT-GROUND_WIDTH-cat_HEIGHT-26;
    cat_rec.setWidth(50);
    cat_rec.setHeight(60);
    cat_jump_height = cat_y-270;//8.15修改 实时更新高度，控制一次只能跳270高
    timer.start(cat_CHANGE_PIX);
    connect(&timer,QTimer::timeout,[=]()
    {
        if(!iscat2)
            cat_dead_pic.load(cat_DEAD);
            else cat_dead_pic.load(DOG_DEAD);
        //用于键盘跳跃事件来更新坐标，注意猫跳跃后y变小
        if(cat_jumpfree==false)
        {//这个条件让猫启动跳跃代码
            if(cat_ban_picture==false)
            {
                if(cat_stand==false)
                    if(!iscat2)
                    cat_pix.load(cat_JUMP);
                else cat_pix.load(DOG_JUMP);
                if(cat_stand==true)
                    if(!iscat2)
                    cat_pix.load(cat_LJUMP);
                else cat_pix.load(DOG_LJUMP);
            }
 //这部分做的不好还是得用自由落体来做
if(iscat2==false){
            if(cat_y>=cat_jump_height&&cat_up==true)
            {
                qDebug()<<cat_jump_height;
                cat_down=0;//每次跳起来更新默认玛丽奥下方无东西
                cat_y-=20;
                if(cat_y<=cat_jump_height)//向上至最大限度停止上行
                    cat_up=false;//加上这个变量就相当于是让上去下来代码不能同时执行
                //不然的话刚刚下去的代码执行了一点又满足了上面代码执行的条件
            }
            if(cat_y<cat_height_min&&cat_up==false&&cat_down==0)
            {
                cat_y+=20;
                if(cat_y>=cat_height_min)
                {
                    //向下至最小限度停止下行
                    cat_jumpfree=true;//结束调用跳跃部分代码
                    cat_up=true;
                    cat_jump_height=cat_y-270;//恢复猫默认最大跳跃高度，因为在顶砖块时猫最大跳跃高度发生变化，跳跃完成要及时恢复
                }
            }
}
            //**********************************
            if(iscat2==true){

//                qDebug()<<(cat_y>=cat_jump_height+BIAS+10);
            if(cat_y>=cat_jump_height&&cat_up==true)
            {
                cat_down=0;//每次跳起来更新默认玛丽奥下方无东西
                cat_y-=20;
                if(cat_y<=cat_jump_height)//向上至最大限度停止上行
                    cat_up=false;//加上这个变量就相当于是让上去下来代码不能同时执行
                //不然的话刚刚下去的代码执行了一点又满足了上面代码执行的条件
            }
            if(cat_y<cat_height_min+BIAS&&cat_up==false&&cat_down==0)
            {
                cat_y+=20;
                if(cat_y>=cat_height_min+BIAS)
                {
                    //向下至最小限度停止下行
                    cat_jumpfree=true;//结束调用跳跃部分代码
                    cat_up=true;
                    cat_jump_height=cat_y-270;//恢复猫默认最大跳跃高度，因为在顶砖块时猫最大跳跃高度发生变化，跳跃完成要及时恢复
                }
            }
            }
            //************************************
            if(cat_down!=0)
            {
                //实现猫在砖块上也能跳跃，因为如果脚下有物体，下落阶段代码执行不完全，就不能跳跃了
                cat_jumpfree=true;
                cat_up=true;
                cat_jump_height=cat_y-270;
            }
        }

//猫处于站立状态时加载站立的图片，这里后来添加了第三个条件，原因是在跳跃状态前两个条件也会满足
//图片还会切换成站立不动的图，将刚刚换好的站立不动的图覆盖
    if(cat_rfree==true&&cat_lfree==true&&cat_jumpfree==true)
    {
        if(cat_stand==false)
            if(!iscat2)
            cat_pix.load(cat_STAND);
        else cat_pix.load(DOG_STAND);
        if(cat_stand==true)
            if(!iscat2)
            cat_pix.load(cat_LSTAND);
        else cat_pix.load(DOG_LSTAND);
        cat_rbiao=0;//每次在猫结束移动之后将切图重新开始
        cat_lbiao=0;
    }

        if(cat_rfree==false)
        {
            //控制猫向右边走时的切图
            QString str;
            if(!iscat2)
             str=QString(cat_RPICTURE).arg(cat_rbiao++);
            else  str=QString(DOG_RPICTURE).arg(cat_rbiao++);
            cat_pix.load(str);
            if(cat_rbiao==22)
            {
                cat_rbiao=0;
            }
        }

        if(cat_lfree==false)
        {QString str;
               //控制猫向左边走时的切图
            if(!iscat2)
              str=QString(cat_PICTURE).arg(cat_lbiao++);
            else str=QString(DOG_PICTURE).arg(cat_lbiao++);
               cat_pix.load(str);
               if(cat_lbiao==22)
               {
                    cat_lbiao=0;
               }
        }
        //用于碰撞检测，因为只有这里猫的坐标会发生变化，至于设置矩形长宽为什么也在这里是因为
        //猫图片的行走图片尺寸好像有些不太一样，这样可以实时更新当前图片作为长宽
//        cat_rec.setWidth(cat_pix.width());
//        cat_rec.setHeight(cat_pix.height());
          cat_rec.moveTo(cat_x,cat_y);
    });
}

void cat::cat_move()
{
    if(cat_can_move==true)
    {
        if(cat_stand==true)
        {
            cat_x-=22;
            fakecat_x-=22;
       }

        if(cat_stand==false)
        {
            cat_x+=22;
            fakecat_x+=22;
        }
    }
    cat_rec.moveTo(cat_x,cat_y);
}
void cat::cat_auto_down()
{
    if(cat_down!=0&&iscat2==false)
    {
            if(!((cat_x>315&&cat_x<415)||(cat_x>465&&cat_x<765)||(cat_x>840&&cat_x<940)||(cat_x>990&&cat_x<1140)||(cat_y<300&&cat_x>1450&&cat_x<1600)||
                (cat_x>1585&&cat_x<1785&&cat_y>300)||(cat_x>2020&&cat_x<2170)||(cat_x>2220&&cat_x<2420)||(cat_x>2220&&cat_x<2420)
                 ||(cat_x>3510&&cat_x<3660)||(cat_x>4195&&cat_x<4325)||(cat_x>4405&&cat_x<4505)||(cat_x>4800&&cat_x<4900)
                 ||(cat_x>4950&&cat_x<5050)||(cat_x>6520&&cat_x<6660)||(cat_x>10600&&cat_x<10800)||(cat_x>10150&&cat_x<10500)||(cat_x>8600&&cat_x<9150)||
                 (cat_x>9250&&cat_x<9800)||(cat_x>8350&&cat_x<8550)||(cat_x>8100&&cat_x<8300)||(cat_x>7400&&cat_x<7600)||(cat_x>7650&&cat_x<7950&&cat_y>200)||
                 (cat_x>7950&&cat_x<8050)||(cat_x>6750&&cat_x<6950)||(cat_x>7050&&cat_x<7140)||(cat_x>7160&&cat_x<7240)||(cat_x>7260&&cat_x<7340)
                 ||(cat_x>10960&&cat_x<11340)||(cat_x>5100&&cat_x<5365)||(cat_x>3810&&cat_x<3940)||(cat_x>5460&&cat_x<5580)
                 ||(cat_x>6320&&cat_x<6460)))
            {
                 cat_jumpfree=false;
                 cat_up=false;
                 cat_down=0;
            }
     }

    if(cat_down!=0&&iscat2==true)
    {
            if(!((cat_x>315&&cat_x<415)||(cat_x>465&&cat_x<765)||(cat_x>840&&cat_x<940)||(cat_x>990&&cat_x<1140)||(cat_y<300+BIAS&&cat_x>1450&&cat_x<1600)||
                (cat_x>1585&&cat_x<1785&&cat_y>300+BIAS)||(cat_x>2020&&cat_x<2170)||(cat_x>2220&&cat_x<2420)||(cat_x>2220&&cat_x<2420)
                 ||(cat_x>3510&&cat_x<3660)||(cat_x>4195&&cat_x<4325)||(cat_x>4405&&cat_x<4505)||(cat_x>4800&&cat_x<4900)
                 ||(cat_x>4950&&cat_x<5050)||(cat_x>6520&&cat_x<6660)||(cat_x>10600&&cat_x<10800)||(cat_x>10150&&cat_x<10500)||(cat_x>8600&&cat_x<9150)||
                 (cat_x>9250&&cat_x<9800)||(cat_x>8350&&cat_x<8550)||(cat_x>8100&&cat_x<8300)||(cat_x>7400&&cat_x<7600)||(cat_x>7650&&cat_x<7950&&cat_y>200+BIAS)||
                 (cat_x>7950&&cat_x<8050)||(cat_x>6750&&cat_x<6950)||(cat_x>7050&&cat_x<7140)||(cat_x>7160&&cat_x<7240)||(cat_x>7260&&cat_x<7340)
                 ||(cat_x>10960&&cat_x<11290)||(cat_x>5100&&cat_x<5365)||(cat_x>3810&&cat_x<3940)||(cat_x>5460&&cat_x<5580)
                 ||(cat_x>6320&&cat_x<6460)))
            {
                 cat_jumpfree=false;
                 cat_up=false;
                 cat_down=0;
            }
     }
}
void cat::cat_Dead()
{
    cat_x-=200;
    fakecat_x-=200;
    cat_crash_monster=0;
}





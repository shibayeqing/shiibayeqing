#include "monster.h"
#include"config.h"
#include<QPixmap>
#include<QTimer>
Monster::Monster(QWidget *parent) : QWidget(parent)
  {
      monster_x=monster_left;//设置怪初始位置

          //设置矩形的长宽，用于碰撞检测
          monster_rec.setWidth(50);
          monster_rec.setHeight(50);
}

void Monster::moving()
  {
      timer.start(MONSTER_MOVE);
      connect(&timer,QTimer::timeout,[=]()
      {
          if(monster_rfree==false){//控制小怪向右边走时的切图
      monster_pix.load(MONSTER_RPICTURE);
          }

          if(monster_lfree==false){//控制小怪向左边走时的切图
      monster_pix.load(MONSTER_LPICTURE);
          }
          if(monster_rfree==false){
              monster_x+=20;//每次移动20像素
              if(monster_x>=monster_left+MONSTER_RIGHT_MAX)
              {monster_rfree=true;
              monster_lfree=false;}
          }

          if(monster_lfree==false)
              monster_x-=20;//每次移动20像素
          if(monster_x<=monster_left)
          {monster_lfree=true;
           monster_rfree=false;}
          //改变矩形的位置用于碰撞检测
          monster_rec.moveTo(monster_x,monster_y);
      });
  }

  void Monster::bian()
  {
          timer.stop();
          monster_pix =monster_pix.scaled(50,20);
          monster_y+=25;
  }

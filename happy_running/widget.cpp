//#include "widget.h"
//#include "ui_widget.h"
//#include"config.h"
//#include"wall.h"
//#include "turtle.h"
//#include"mario.h"
//#include"monster.h"
//#include "grassground.h"
//#include"questionwall.h"
//#include"bullet.h"
//#include<QPainter>
//#include<QKeyEvent>
//#include<QDebug>
//#include<QTimer>
//#include<QDebug>
//Widget::Widget(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::Widget)
//{
//    ui->setupUi(this);


//    initScence();
//    build_wall();
//  //  mushroom_initScence();//这里函数放的位置也要注意mushroom_initScence()要放到build_wall();后面
//    mushroom_moving();
//    turtle.moving();//建立乌龟移动的信号与槽
//    monster.moving();//建立小怪移动的信号与槽
//    for(int i=0;i<50;i++){
//        bullet[i].shoot();//建立每发子弹的信号与槽
//    }
//    connect(&turtle.timer,&QTimer::timeout,[=](){
//        update();
//        crash();//利用这个定时器来反复执行碰撞函数来检测碰撞是否发生
//        mario_any_down();
//    });
//}
//void Widget::initScence()
//{   //this->setWindowIcon(QIcon(":/picture/icon.png"));//暂时还没有加载进来图片故无显示
//    this->setWindowTitle("Super Mario");
//    this->setFixedSize(1460,740);
//}

//void Widget::build_wall()
//{//修建三个砖头
//    wall[0].wall_x=100;wall[1].wall_x=150;wall[2].wall_x=200;
//    wall[0].wall_y=wall[1].wall_y=wall[2].wall_y=170;
//    wall[0].wall_rec.moveTo(wall[0].wall_x,wall[0].wall_y);
//    wall[1].wall_rec.moveTo(wall[1].wall_x,wall[1].wall_y);
//    wall[2].wall_rec.moveTo(wall[2].wall_x,wall[2].wall_y);
//    //修建两个问题砖头
//    question_wall[0].question_x=250;question_wall[1].question_x=300;
//    question_wall[0].question_y=question_wall[1].question_y=170;
//    question_wall[0].question_rec.moveTo(question_wall[0].question_x,question_wall[0].question_y);
//    question_wall[1].question_rec.moveTo(question_wall[1].question_x,question_wall[1].question_y);

//}

//void Widget::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    painter.drawPixmap(ground.ground_x,ground.ground_y,ground.ground_pix);//绘制草地
//    painter.drawPixmap(mario.mario_x,mario.mario_y,mario.mario_pix);//绘制马里奥
// //    painter.drawPixmap(600,ground.ground_y,ground.ground_pix);
//    painter.drawPixmap(turtle.turtle_x,turtle.turtle_y,turtle.turtle_pix);//绘制乌龟
//    if(monster.monster_life==true){
//    painter.drawPixmap(monster.monster_x,monster.monster_y,monster.monster_pix);}//绘制小怪
//    if(monster.monster_life==false&&bian_time<10&&monster.monster_kill_cai==true){//在小怪死亡后绘制小怪被踩扁的图片
//     painter.drawPixmap(monster.monster_x,monster.monster_y,monster.monster_pix);//绘制小怪
//    bian_time++;
//    }
//    if(mushroom.istaste==false){
//    painter.drawPixmap(mushroom.mushroom_x,mushroom.mushroom_y,mushroom.mushroom_pix);}
//    //绘制问题砖块，这里切图不是写在封装的类里面用定时器切换，因为16张图片是一张长图
//    for(int i=0;i<2;i++){
//        if(question_wall[i].question_state==true){//问题砖块的背后切图，并且这里是长图
//            painter.drawPixmap(question_wall[i].question_x,question_wall[i].question_y,question_wall[i].question_pix,50*question_wall[i].pix_biao++,0,50,50);
//            if(question_wall[i].pix_biao==16)
//                question_wall[i].pix_biao=0;}
//        if(question_wall[i].question_state==false){//问题砖块被顶后切图
//            question_wall[i].question_pix.load(QUESTION_HPICTURE);
//            painter.drawPixmap(question_wall[i].question_x,question_wall[i].question_y,question_wall[i].question_pix);
//        }
//    }

//    for(int i=0;i<3;i++){//绘制砖头
//        if(wall[i].wall_state==true)
//            painter.drawPixmap(wall[i].wall_x,wall[i].wall_y,wall[i].wall_pix);
//        if(wall[i].wall_state==false&&wall[i].wall_life==true){//绘制砖头的破裂
//        painter.drawPixmap(wall[i].wall_x-75,wall[i].wall_y-75,wall[i].zs_pix);
//        painter.drawPixmap(wall[i].wall_x-75,wall[i].wall_y+75,wall[i].zx_pix);
//        painter.drawPixmap(wall[i].wall_x+75,wall[i].wall_y-75,wall[i].ys_pix);
//        painter.drawPixmap(wall[i].wall_x+75,wall[i].wall_y+75,wall[i].yx_pix);
//        wall[i].wall_life=false;//砖头死了，破裂效果只显示一次
//        }
//    }
//    for(int i=0;i<50;i++){
//        if(bullet[i].bullet_free==false)//只有发射了才更新位置
//            painter.drawPixmap(bullet[i].bullet_x,bullet[i].bullet_y,bullet[i].bullet_pix);
//    }
//   //  painter.drawPixmap(mushroom.mushroom_x,mushroom.mushroom_y,mushroom.mushroom_pix);
//}

//void Widget::keyPressEvent(QKeyEvent * event)
//{

////控制马里奥左右移动
//        if (event->key() == Qt::Key_Left) {
//            mario.mario_stand=true;//马里奥朝向左边
//            mario.mario_rfree=true;
//            mario.mario_lfree=false;
//            mario.mario_x-=8;
//                    // 移动窗口向左

//                } else if (event->key() == Qt::Key_Right) {
//            mario.mario_stand=false;
//            mario.mario_rfree=false;
//            mario.mario_lfree=true;
//            mario.mario_x+=8;
//                    // 移动窗口向右

//                }
//        else if (event->key() == Qt::Key_Space){
//          mario.mario_jumpfree=false;//开始调用跳跃部分代码
//      }
//        else if (event->key() == Qt::Key_X&&bullet_fire==true){
//            bullet[bullet_num].bullet_free=false;
//            bullet[bullet_num].timer.start(50);//开启定时器，子弹开始偏移
//            bullet[bullet_num].bullet_x=mario.mario_x;
//            bullet[bullet_num].bullet_y=mario.mario_y+30;//处于马里奥中央
//            if(mario.mario_stand==false)//控制子弹发射方向
//                bullet[bullet_num].bullet_pos=false;
//            if(mario.mario_stand==true)
//                bullet[bullet_num].bullet_pos=true;
//            bullet[bullet_num].bullet_rec.moveTo(bullet[bullet_num].bullet_x,bullet[bullet_num].bullet_y);
//           bullet_num++;//子弹只设置了50发
//        }
//         mario.mario_rec.moveTo(mario.mario_x,mario.mario_y);
//}

//void Widget::keyReleaseEvent(QKeyEvent *event)
//{
//    if (event->key() == Qt::Key_Left) {

//        mario.mario_rfree=true;//左右均为true，左右切图停止
//        mario.mario_lfree=true;
//                // 移动窗口向左
//            } else if (event->key() == Qt::Key_Right) {

//        mario.mario_rfree=true;
//        mario.mario_lfree=true;
//                // 移动窗口向右
//    }
//     mario.mario_rec.moveTo(mario.mario_x,mario.mario_y);
//}


//void Widget::mushroom_moving()
//{//mushroom_moving()从crash中分离出来了，不然会建立多个信号与槽的连接，造成严重后果
//    mushroom.mushroom_x=question_wall[0].question_x;//这里没有选择在封装的类中初始化因为不确定可能有多个蘑菇
//    mushroom.mushroom_y=question_wall[0].question_y;
//    connect(&mushroom.timer,QTimer::timeout,[=](){
//        if(mushroom.i<5){
//            mushroom.i++;
//            mushroom.mushroom_y-=10;
//        }
//        else{
//            if(mushroom.j<10){
//                mushroom.j++;
//                mushroom.mushroom_x+=10;
//            }
//            else{
//                if(mushroom.mushroom_y<400-GROUND_WIDTH-MUSHROOM_HEIGHT)
//                    mushroom.mushroom_y+=10;
//                else{
//                    mushroom.mushroom_x-=10;
//                }
//            }
//        }
//        mushroom.mushroom_rec.moveTo(mushroom.mushroom_x,mushroom.mushroom_y);
//    });
//}

//void Widget::crash()
//{   for(int i=0;i<3;i++){
//        if(wall[i].wall_state==true&&mario.mario_rec.intersects(wall[i].wall_rec)==true){
//            int dx = mario.mario_rec.x() - wall[i].wall_rec.x();
//                   int dy = mario.mario_rec.y() - wall[i].wall_rec.y();

//                   if (qAbs(dx) < qAbs(dy)) {
//                       // 竖直方向上的碰撞
//                       if (dy > 0) {
//                           wall[i].wall_state=false;//检测到碰撞后开始绘制砖头破碎图
//                              mario.mario_jump_height=wall[i].wall_y+WALL_HEIGHT;
//                               mario.mario_up=false;//这里有小误差故需要加上手动变为下落
//                           //qDebug() << "Rect1 collides with the bottom edge of Rect2";
//                       } else {
//                           mario.mario_down=1;//告诉跳跃函数马里奥脚下有砖块
//                        mario.mario_y=wall[i].wall_y-MARIO_HEIGHT;
//                           //qDebug() << "Rect1 collides with the top edge of Rect2";
//                       }
//                   }
//            }
//       }
//    for(int i=0;i<2;i++){//这里不用检查state因为不管问号是否存在,对于每一个问号砖块都要碰撞检测
//           if(mario.mario_rec.intersects(question_wall[i].question_rec)==true){
//               int dx = mario.mario_rec.x() - question_wall[i].question_rec.x();
//                      int dy = mario.mario_rec.y() - question_wall[i].question_rec.y();

//                      if (qAbs(dx) < qAbs(dy)) {
//                          // 竖直方向上的碰撞
//                          if (dy > 0) {
//                              question_wall[i].question_state=false;//检测到碰撞后开始绘制砖头破碎图
//                                 mario.mario_jump_height=question_wall[i].question_y+QUESTION_WALL_HEIGHT;
//                                 mario.mario_up=false;//这里有小误差故需要加上手动变马里奥为下落状态
//                                 if(i==0)
//                                  mushroom.timer.start(100);//蘑菇开始移动
//                              //qDebug() << "Rect1 collides with the bottom edge of Rect2";
//                          } else {
//                              mario.mario_down=2;//告诉跳跃函数马里奥脚下有问题砖块
//                           mario.mario_y=question_wall[i].question_y-MARIO_HEIGHT;
//                              qDebug() << "Rect1 collides with the top edge of Rect2";
//                          }
//                      }
//               }
//          }
//    if(mario.mario_rec.intersects(mushroom.mushroom_rec)==true){
//        bullet_fire=true;//可以发射子弹了
//        mushroom.istaste=true;//蘑菇被吃掉了，此后将不再显示
//    }
//    for(int i=0;i<50;i++){//小怪与子弹的碰撞
//        if(bullet[i].bullet_free==false&&monster.monster_life==true){//只有发射了才检测是否碰撞了
//            if(bullet[i].bullet_rec.intersects(monster.monster_rec)==true){
//               // qDebug()<<1;
//                bullet[i].bullet_free=true;
//                monster.monster_life=false;//小怪死亡，不再绘制
//            }
//        }
//    }

//    if(monster.monster_life==true&&mario.mario_rec.intersects(monster.monster_rec)==true){//小怪与马里奥踩踏的碰撞
//        int dx = mario.mario_rec.x() - monster.monster_rec.x();
//               int dy = mario.mario_rec.y() - monster.monster_rec.y();

//               if (qAbs(dx) < qAbs(dy)) {
//                   // 竖直方向上的碰撞
//                   if (dy < 0) {
//                       monster.bian();
//                       monster.monster_life=false;//小怪死亡，不再绘制
//                       monster.monster_kill_cai=true;
//                       }
//                }
//  }

//}
////这里想到两个碰撞检测方法，一种使用intersected与contains来检测，但是前提是要设置多个碰撞检测点，需要的东西比较多
////第二种是利用砖块的x,y坐标以及厚度与高度来检测碰撞范围(利用到马里奥此时的坐标)，以此来确定马里奥在下方还是上方
////最后发现是第三种的判断比较好用
//void Widget::mario_any_down()
//{
////    if(mario.mario_jumpfree==true&&mario.mario_y<400-GROUND_WIDTH-MARIO_HEIGHT){
////         //mario.mario_rec.moveTo(mario.mario_x,mario.mario_y+10);
////        for(int i=0;i<2;i++){//这里不用检查state因为不管问号是否存在,对于每一个问号砖块都要碰撞检测
////            //mario.mario_rec.moveTo(mario.mario_x,mario.mario_y+10);
////               if(mario.mario_rec.intersects(question_wall[i].question_rec)==false){
////                   mario.mario_jumpfree=false;
////                   mario.mario_up=false;
////                   mario.mario_down=0;
////                   mario.mario_ban_picture=true;//禁止播放跳跃图
////               }
////        }
////         for(int i=0;i<3;i++){
////                if(wall[i].wall_state==true&&mario.mario_rec.intersects(wall[i].wall_rec)==false){
////                    mario.mario_jumpfree=false;
////                    mario.mario_up=false;
////                    mario.mario_down=0;
////                    mario.mario_ban_picture=true;
////                }
////               }
////    }

//}//这段代码实现了马里奥的掉落效果，如果不想要直接注释掉






//Widget::~Widget()
//{
//    delete ui;
//}

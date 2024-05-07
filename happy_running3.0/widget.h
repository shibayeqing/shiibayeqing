#ifndef WIDGET_H
#define WIDGET_H
#include "turtle.h"
#include"cat.h"
#include"wall.h"
#include"monster.h"
#include"mushroom.h"
#include <QWidget>
#include "grassground.h"
#include"questionwall.h"
#include"bullet.h"
#include<QKeyEvent>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    Turtle turtle;
    Monster monster;
    cat cat;
    GrassGround ground;
    Wall wall[3];
    QuestionWall question_wall[2];
    Bullet bullet[50];
    MushRoom mushroom;
    bool bullet_fire=false;//开始时马里奥不能发射子弹
    int bullet_num=0;
    int bian_time=0;//用于绘制小怪被踩扁后绘制踩扁图片，因为这里要让扁的图片存在一段时间
    void initScence();//用于初始化场景
    void build_wall();//用于构建砖块
    void crash();//碰撞检测函数,包含了蘑菇与问题方块的碰撞检测函数
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);//键盘事件
    void keyReleaseEvent(QKeyEvent *event);
  //  void mushroom_initScence();
    void mushroom_moving();
     void cat_any_down();
  //  void cat_down();//马里奥下落函数，主要用于当马里奥
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

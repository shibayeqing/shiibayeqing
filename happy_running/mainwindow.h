#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <widget.h>
#include "turtle.h"
#include "cat.h"
#include "wall.h"
#include "monster.h"
#include "mushroom.h"
#include <QWidget>
#include "grassground.h"
#include "questionwall.h"
#include "bullet.h"
#include <QKeyEvent>
#include <Pipe.h>
#include <timer.h>
#include <coincounter.h>
#include <cat_heath.h>
#include <gameover.h>
#include <dj.h>
#include <Gold.h>
#include <Hole.h>
#include <FloatGround.h>
#include <flagandcastle.h>
#include <winwindow.h>
#include "WhiteMonster.h"
#include "Winner.h"
#include "Rocket.h"
#include "MoveGround.h"
#include "key.h"
#include "intro.h"
namespace Ui//声明namespace Ui是因为要调用Ui中的MainWindow，此MainWindow非彼MainWindow，后面涉及的*ui指针会调用它！
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);//explicit去掉隐式转换机制
    ~MainWindow();
signals: void soundeffect(QString);
private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsScene* scene_2;
    QPushButton *startbutton;
    QTimer *timer;
    QTimer *timerforcountdown;
    QPushButton *settingbutton;
    QPushButton *exitbutton;
    QPushButton *fullscreenbutton;
    void gamebegin();
    void loginwindow();
    void nextframe();
    void changecolor();
    void changewindow();
    void twoplayer();
    Widget* scene_3;
    Timer time;//设置定时器
    QTimer update_timer;//用于paintevent手动调用定时器
    Turtle turtle[6];//设置乌龟数组
    intro introduction;
    Monster monster[14];//设置小怪数组
    cat cat[2];//设置猫数组
    GrassGround ground[200];//设置草地数组
    Wall wall[206];//设置砖块
    QuestionWall question_wall[14];//设置问题砖块数组
    Bullet bullet0[5];//设置子弹数组
    Bullet bullet1[5];//设置子弹数组
    Gold gold[330];//设置金币
    CoinCounter coincounter[2];//设置金币计数器
    cat_heath heath[2];//设置猫的生命计数器
    //FloatGround floatground[10];//设置悬浮地面
    Gameover gameover;//游戏结束标志
    Pipe tube[4];//设置水管，一共4个，双人模式上方下方各2个
    DJ *dj;//设置音乐
    Hole hole[16];//设置洞穴，一共4个，双人模式上下方各2个
    Hole fire_hole[4];//设置洞穴内的火球
    MushRoom mushroom[2];//设置蘑菇数组
    Winwindow winwindow;
    Winner winner;
    Rocket rocket[2];//设置小火箭
    MoveGround moveground[8];//设置动态地面
    Key key[2];
    int update_only_once=1;
    int bias=0;//cat[0]移动的时候用于移动场景的变量
    int bias1=0;//cat[1]移动的时候用于移动场景的变量
    int music = 0;//初始化背景音乐变量
    int totalscore1=0;//设置得分计数器1
    int totalscore2=0;//设置得分计数器2
    bool cat1_win =0;
    bool cat2_win = 0;
    bool cat_dead = 0;//设置上方猫的死亡
    bool cat_dead_2 = 0;//设置下方猫的死亡
    bool bullet0_fire=false;//开始时猫不能发射子弹
    bool bullet1_fire=false;//开始时猫不能发射子弹
    Flagandcastle flagandcastle[2];//设置旗帜和城堡数组
    WhiteMonster whitemonster[2];//设置白色鬼魂数组
    int bullet0_num =0, bullet1_num = 0;//初始化子弹数量
    bool gamemode;//设置游戏模式，单人为1，双人为0；
    bool musicEnabled = true;
    void initScence();//用于初始化场景
    void build_wall();//用于构建砖块
    void crash();//碰撞检测函数,包含了蘑菇与问题方块的碰撞检测函数
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);//键盘按下事件
    void keyReleaseEvent(QKeyEvent *event);//键盘抬起事件
    void mushroom_moving();//设置蘑菇移动
    void cat_any_down();//设置猫自由落体
    void set_turtle();//设置乌龟
    void set_grassground();//设置草地
    void set_monster();//设置橙色小怪
    void set_hole();//设置小洞
    void setCoin();//设置硬币的初始位置
    void gameover_time();//时间耗尽的死法
    void set_tube();//设置水管
    void set_flagandcastle();//设置旗帜和城堡
    //void cat_fallhole();//设置猫掉落进洞
    void set_whitemonster();//设置白色鬼魂
    //void set_rocket();//设置火箭
    void set_moveground();//设置动态地面
    void set_fire();
    void playagian();
    void set_key();
    void key_moving();
    void cat_moveground_down();
    void cat_float();
    //void cat_lower_ground();
    void rocket_moving1();
    void rocket_moving2();
    //void set_floatground();
};

#endif // MAINWINDOW_H

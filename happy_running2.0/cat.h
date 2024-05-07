#ifndef cat_H
#define cat_H
#include"config.h"
#include <QWidget>
#include<QPixmap>
#include<QTimer>
#include <QMainWindow>
class cat : public QMainWindow
{
    Q_OBJECT
public:
    explicit cat(QWidget *parent = nullptr);
     int cat_x;
     int cat_y;
     int iscat2=false;
     int fakecat_x;//猫的假坐标
     int cat_life = 5;
     bool dead = 0;
     int cat_lbiao=0;//向左走切图下标
     int cat_rbiao=0;//向右走切图下标
     int cat_jump_height;//设置猫最大跳跃高度，即可跳跃到的最小y坐标
     int cat_down=0;//默认猫脚下无东西，1代表砖块，主要为了保证在脚下有东西时
     QPixmap cat_pix;
     QPixmap cat_dead_pic;
     QRect cat_rec;
     bool cat_can_move=false;//默认猫没在移动
     bool cat_up=true;//判断猫此时是否处于跳跃向上状态
     bool cat_rfree=true;//都默认为true表示一开始都不切图，为false时表示正在移动，为true时表示不动
     bool cat_lfree=true;
     bool cat_move_state=false;
     bool cat_ban_picture=false;
     bool cat_label=true;
     int cat_height_min;
     bool cat_stand=false;//用于判断猫停下时朝向，false朝右，true朝左
     bool cat_jumpfree=true;//默认猫不处于跳动状态
     int cat_Dead_index = 0;
     int cat_crash_monster=0;
     QTimer timer;//控制猫切图
     void cat_move();
     void cat_auto_down();//用于实现猫初始掉落位置
     void cat_Dead();
     bool cat_downhole=false;//默认猫没有掉落进洞的趋势
     int cat_minheight;
     void cat_hole_down();


signals:

public slots:
};

#endif // cat_H

 #include "wall.h"
#include"config.h"
#include<QTimer>
#include <QMainWindow>
Wall::Wall(QMainWindow *parent) : QMainWindow(parent)
{

    wall_pix.load(WALL_MEW_PICTURE);
    wall_pix = wall_pix.scaled(50,50);
    zs_pix.load(WALL_BREAK_ZS);
    zx_pix.load(WALL_BREAK_ZX);
    ys_pix.load(WALL_BREAK_YS);
    yx_pix.load(WALL_BREAK_YX);
    wall_rec.setWidth(wall_pix.width());
    wall_rec.setHeight(wall_pix.height());

    //wall_rec.moveTo(wall_x,wall_y);
    //wall_rec.moveTo(wall_x,wall_y);
    //wall_rec.moveTo(wall_x,wall_y);
    //
    //一会弄一下看move也设置到这里会发生什么，主要是考虑到代码执行顺序
    //可能这里还没有设置好，如果这里也可以，就最好设置到这里，更紧密
    //事实证明不行果然是代码执行顺序问题，



}

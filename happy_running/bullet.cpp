#include "bullet.h"

Bullet::Bullet(QWidget *parent) : QWidget(parent)
{

    bullet_rec.setWidth(20);
    bullet_rec.setHeight(20);


}

void Bullet::shoot()
{connect(&timer,QTimer::timeout,[=](){
        if(iscat==0)
            bullet_pix.load(BULLET_FISH_PICTURE);
        if(iscat==1)
            bullet_pix.load(BULLET_BONE_PICTURE);
        bullet_pix =bullet_pix.scaled(20,20);
        if(bullet_pos==false)
        bullet_x+=40;
        if(bullet_pos==true)
           bullet_x-=40;

       bullet_rec.moveTo(bullet_x,bullet_y);
    });
//待完善的功能：子弹发射的界限/范围没有实现
    //子弹矩形框的跟踪，矩形框的更新
    //猫与蘑菇碰撞之后蘑菇消失，并且拥有发射子弹能力
    //
}

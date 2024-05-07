#include "Rocket.h"
#include "config.h"

Rocket::Rocket(QWidget *parent) : QMainWindow(parent)
{
    //rocket_pix=rocket_pix.scaled(160,80);
    //碰撞检测
    rocket_pix.load(Rocket_PICTURE);
    rocket_pix=rocket_pix.scaled(160,80);
    rocket_rec.setWidth(160);
    rocket_rec.setHeight(80);
}
void Rocket::rocket_crash()
{
     timer.stop();
     rocket_crash_zs_pix.load(Rocket_crash_PICTURE);
     rocket_crash_zs_pix=rocket_crash_zs_pix.scaled(50,50);
     rocket_crash_zx_pix.load(Rocket_crash_PICTURE);
     rocket_crash_zx_pix=rocket_crash_zx_pix.scaled(50,50);
     rocket_crash_ys_pix.load(Rocket_crash_PICTURE);
     rocket_crash_ys_pix=rocket_crash_ys_pix.scaled(50,50);
     rocket_crash_yx_pix.load(Rocket_crash_PICTURE);
     rocket_crash_yx_pix=rocket_crash_yx_pix.scaled(50,50);
}

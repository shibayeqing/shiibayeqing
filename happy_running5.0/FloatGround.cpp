#include "FloatGround.h"
#include "config.h"

FloatGround::FloatGround(QWidget *parent) : QWidget(parent)
{
//    floatground_pix1.load(SFloatGround_PICTURE);//草地图片
//    floatground_sx=5904;
//    floatground_sy=HEIGHT-GROUND_WIDTH-SFloatGround_HEIGHT-31;
    floatground_pix2.load(GROUND_PICTURE);//草地图片
    floatground_lx=5574;
    floatground_ly=HEIGHT-GROUND_WIDTH-LFloatGround_HEIGHT-47;
}

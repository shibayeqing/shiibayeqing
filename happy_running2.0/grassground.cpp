#include "grassground.h"
#include"config.h"
GrassGround::GrassGround(QWidget *parent) : QWidget(parent)
{
     ground_pix.load(GROUND_PICTURE);
     ground_x=0;
     ground_y=HEIGHT-GROUND_WIDTH-40;


}

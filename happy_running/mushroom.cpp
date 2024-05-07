#include "mushroom.h"
#include<QPixmap>
#include"config.h"
#include<QTimer>
MushRoom::MushRoom(QWidget *parent) : QWidget(parent)
{
    mushroom_pix.load(GREEN_MUSHROOM);
    mushroom_pix = mushroom_pix .scaled(50,50);
    mushroom_rec.setWidth(50);
    mushroom_rec.setHeight(50);
}

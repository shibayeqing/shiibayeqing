#include "Hole.h"
#include "config.h"
#include <QTimer>
#include <QPixmap>

Hole::Hole(QWidget *parent) : QWidget(parent)
{
    hole_pix.load(GreenGround_PICTURE);
    hole_rec.setWidth(24);
    hole_rec.setHeight(96);
    fire_hole_rec.setWidth(80);
    fire_hole_rec.setHeight(80);
}

void Hole::fire_moving()
{
      timer6.start(fire_TIME);
      connect(&timer6,QTimer::timeout,[=]()
      {
          fire_hole_pix.load(Rocket_crash_PICTURE);
          fire_hole_pix = fire_hole_pix.scaled(100,100);
          if(fire_up==true)
          {
              fire_hole_y-=10;//单次上升10
              if(fire_hole_y<=fire_up_max)
              {
                  fire_up=false;
                  fire_down=true;
              }
          }
          if(fire_down==true)
          {
              fire_hole_y+=10;//单次下降10
              if(fire_hole_y>=fire_down_max)
              {
                  fire_up=true;
                  fire_down=false;
              }
          }
          fire_hole_rec.moveTo(fire_hole_x,fire_hole_y);
      });
}


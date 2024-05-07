#include "MoveGround.h"
#include <QPixmap>
#include <QTimer>
#include <config.h>

MoveGround::MoveGround(QWidget *parent) : QMainWindow(parent)
{
     moveground_rec.setWidth(32);
     moveground_rec.setHeight(112);
}

void MoveGround::ground_moving()
{
      timer4.start(GreenGround_l_Time);
      connect(&timer4,QTimer::timeout,[=]()
      {
          moveground_pix.load(GreenGround_l_PICTURE);
          if(moveground_up==true)
          {
              moveground_y-=15;//单次上升15
              if(moveground_y<=moveground_up_max)
              {
                  moveground_up=false;
                  moveground_down=true;
              }
          }
          if(moveground_down==true)
          {
              moveground_y+=15;//单次下降15
              if(moveground_y>=moveground_down_max)
              {
                  moveground_up=true;
                  moveground_down=false;
              }
          }
          moveground_rec.moveTo(moveground_x,moveground_y);
      });
}

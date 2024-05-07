#include "WhiteMonster.h"
#include "config.h"
#include <QPixmap>
#include <QTimer>

WhiteMonster::WhiteMonster(QWidget *parent) : QMainWindow(parent)
{
    //碰撞数据设置
    whitemonster1_rec.setWidth(40);
    whitemonster1_rec.setHeight(40);
    whitemonster2_rec.setWidth(40);
    whitemonster2_rec.setHeight(40);
}

void WhiteMonster::whitemonster_moving()
{
      timer5.start(WhiteMonster_Time);
      connect(&timer5,QTimer::timeout,[=]()
      {
          whitemonster1_pix.load(WhiteMonster_PICTURE);
          whitemonster2_pix.load(WhiteMonster_PICTURE);
          if(whitemonster1_up==true)
          {
              whitemonster_y1-=10;//单次上升10
              if(whitemonster_y1<=300)
              {
                 whitemonster1_up=false;
                 whitemonster1_down=true;
              }
          }
          if(whitemonster1_down==true)
          {
              whitemonster_y1+=10;//单次下降10
              if(whitemonster_y1>=600)
              {
                  whitemonster1_up=true;
                  whitemonster1_down=false;
              }
          }


          if(whitemonster2_up==true)
          {
              whitemonster_y2-=10;//单次上升10
              if(whitemonster_y2<=300)
              {
                 whitemonster2_up=false;
                 whitemonster2_down=true;
              }
          }

          if(whitemonster2_down==true)
          {
              whitemonster_y2+=10;//单次下降10
              if(whitemonster_y2>=600)
              {
                  whitemonster2_up=true;
                  whitemonster2_down=false;
              }
          }
          whitemonster1_rec.moveTo(whitemonster_x1,whitemonster_y1);
          whitemonster2_rec.moveTo(whitemonster_x2,whitemonster_y2);
      });
}

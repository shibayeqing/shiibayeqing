#ifndef MUSHROOM_H
#define MUSHROOM_H

#include <QWidget>
#include<QTimer>
class MushRoom : public QWidget
{
    Q_OBJECT
public:
    explicit MushRoom(QWidget *parent = nullptr);
   int mushroom_x;
   int mushroom_y;
   int i=0,j=0;
   int m=0,n=0;
   QPixmap mushroom_pix;
   bool mushroom_up = 0;
   //bool mushroom_hit=false;//没必要这个变量，因为碰撞后只会激发定时器
   bool istaste=false;//默认蘑菇没有被吃掉
   QRect mushroom_rec;
   QTimer timer;
signals:

public slots:
};

#endif // MUSHROOM_H

#ifndef BULLET_H
#define BULLET_H
#include"config.h"
#include <QWidget>
#include<QPixmap>
#include<QTimer>
#include<QRect>
class Bullet : public QWidget
{
    Q_OBJECT
public:
    explicit Bullet(QWidget *parent = nullptr);
QPixmap bullet_pix;
int bullet_x;
int bullet_y;
int bullet_start_x;
bool iscat;
bool bullet_free=true;
bool bullet_pos=false;//决定子弹飞出方向，如果时false则子弹像右发射，这个是根据在widget.cpp中猫站位来更改的
//用途是在moving函数中决定x是加还是减
int bullet_max;
QRect bullet_rec;
QTimer timer;
void shoot();
signals:

public slots:
};

#endif // BULLET_H

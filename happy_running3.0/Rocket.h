#ifndef ROCKET_H
#define ROCKET_H

#include <QMainWindow>
#include <QPixmap>
#include "config.h"
#include <QTimer>

class Rocket : public QMainWindow
{
    Q_OBJECT
public:
    explicit Rocket(QWidget *parent = nullptr);
    QPixmap rocket_pix;//小火箭图片
    QPixmap rocket_crash_zs_pix;
    QPixmap rocket_crash_zx_pix;
    QPixmap rocket_crash_ys_pix;
    QPixmap rocket_crash_yx_pix;//火球图片
    int rocket_x;
    int rocket_y;
    int rocket_crash_zs_x;
    int rocket_crash_zs_y;//火球左上图片
    int rocket_crash_zx_x;
    int rocket_crash_zx_y;//火球左下图片
    int rocket_crash_ys_x;
    int rocket_crash_ys_y;//火球右上图片
    int rocket_crash_yx_x;
    int rocket_crash_yx_y;//火球右下图片

    int rocket_rightmax;//用于控制火箭右移的移动边界
    int rocket_crash_time=0;

    bool rocket_life=false;//默认一开始火箭未发射
    bool rocket_crash_life=false;//默认一开始火箭未爆炸

    QRect rocket_rec;

    int i=0;
    int j=0;


    QTimer timer;//设置火箭移动定时器
    void rocket_moving();
    void rocket_crash();

signals:

public slots:
};

#endif // ROCKET_H

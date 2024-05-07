#ifndef WALL_H
#define WALL_H
#include"config.h"
#include <QMainWindow>
#include<QPixmap>
#include<QTimer>
class Wall : public QMainWindow
{
    Q_OBJECT
public:
    explicit Wall(QMainWindow *parent = nullptr);
    int wall_x;
    int wall_y;
    bool wall_state=true;//开始时墙是完好的,这个变量主要是控制切图时应该绘制哪幅图
    bool wall_life=true;//开始时砖时活着的，这个主要控制不要之后一直绘图，砖头破裂特效只出现一下，
    //并且让其变为false之后就不可做碰撞检测了
    QPixmap wall_pix;
    QPixmap zs_pix;//破碎后左上的碎片图片
    QPixmap zx_pix;
    QPixmap ys_pix;
    QPixmap yx_pix;
    QRect wall_rec;


signals:

public slots:
};

#endif // WALL_H

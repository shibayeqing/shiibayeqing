#ifndef TURTLE_H
#define TURTLE_H
#include<QTimer>
#include <QWidget>

class Turtle : public QWidget
{
    Q_OBJECT
public:
    explicit Turtle(QWidget *parent = nullptr);
    QPixmap turtle_pix;
    int turtle_x;
    int turtle_y;
    int turtle_left;
    int turtle_lbiao=0;//向左走图片下标
    int turtle_rbiao=0;//向右走图片下标
    int rolltime=0;//记录乌龟蜷缩时间
    bool turtle_lfree=true;//默认一开始乌龟朝右进行移动
    bool turtle_rfree=false;
    bool turtle_isroll=false;//默认乌龟没有缩回去
    QRect turtle_rec;
    QTimer timer;   //乌龟背后切图定时器
    QTimer timer2;  //乌龟移动定时器
    QTimer timer3;//用于检测乌龟是否被踩
    void moving();
    void tread();//用于检测乌龟是否被踩，被踩后移动函数停止调用所以需要另设函数
signals:

public slots:
};

#endif // TURTLE_H

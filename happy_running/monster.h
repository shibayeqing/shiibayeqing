#ifndef MONSTER_H
#define MONSTER_H
#include <QTimer>
#include <QWidget>

class Monster : public QWidget
{
    Q_OBJECT
public:
    explicit Monster(QWidget *parent = nullptr);
    QPixmap monster_pix;
    QPixmap monster_bian_pix;
    int monster_x;
    int monster_y;
    int monster_left;//用于控制小怪左边的移动边界
    int bian_time=0;//用于绘制小怪被踩扁后绘制踩扁图片，因为这里要让扁的图片存在一段时间
    bool monster_lfree=true;//默认一开始怪物朝右进行移动
    bool monster_rfree=false;
    bool monster_life=true;
    bool monster_kill_cai=false;//这个变量用于区分在绘图小怪踩扁图片如果用子弹打死小怪不会绘制扁小怪图片
    QRect monster_rec;
    QTimer timer;//怪物移动定时器，这里怪物只有一张照片，不用切图，只需切一下左右图
    void moving();
    void bian();

signals:

public slots:
};

#endif // MONSTER_H

#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>
#include "changecolourbutton.h"
#include <QTimer>
#include <QPainter>


class Gameover : public QMainWindow
{
    Q_OBJECT
public:
    explicit Gameover(QWidget *parent = nullptr);

    Changecolourbutton* StartAgain;

    QPixmap gameover_pix;
    QRect gameover_rec;
    int gameover_x;
    int gameover_y;
    bool gameover_life=false;//设置游戏结束图标触发标志，false表示未触发，一旦猫阵亡或时间消耗完则变为true
    QTimer timer;
    bool type = 1;//0为时间耗尽，1为死了
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // GAMEOVER_H

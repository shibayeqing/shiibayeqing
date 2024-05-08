#ifndef MOVEGROUND_H
#define MOVEGROUND_H

#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <config.h>

class MoveGround : public QMainWindow
{
    Q_OBJECT
public:
    explicit MoveGround(QWidget *parent = nullptr);
    QPixmap moveground_pix;
    QRect moveground_rec;

    int moveground_x;
    int moveground_y;

    int moveground_up_max;
    int moveground_down_max;

    bool moveground_up=true;//初始化地面向上进行移动
    bool moveground_down=false;

    QTimer timer4;
    void ground_moving();

signals:

public slots:
};

#endif // MOVEGROUND_H

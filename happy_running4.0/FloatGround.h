#ifndef FLOATGROUND_H
#define FLOATGROUND_H

#include <QWidget>
#include <QPixmap>
#include "config.h"

class FloatGround : public QWidget
{
    Q_OBJECT
public:
    explicit FloatGround(QWidget *parent = nullptr);
    QPixmap floatground_pix1;
    QPixmap floatground_pix2;
    QRect floatground_rec1;
    QRect floatground_rec2;
    int floatground_sx;//设置小悬浮地面X坐标
    int floatground_sy;//设置小悬浮地面Y坐标
    int floatground_lx;//设置长悬浮地面X坐标
    int floatground_ly;//设置长悬浮地面Y坐标


signals:

public slots:
};

#endif // FLOATGROUND_H

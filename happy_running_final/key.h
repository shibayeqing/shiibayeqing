#ifndef KEY_H
#define KEY_H

#include <QWidget>
#include<QPixmap>
#include"config.h"
#include<QTimer>
#include <random>
class Key : public QWidget
{
    Q_OBJECT
public:
    explicit Key(QWidget *parent = nullptr);
    int key_x;
    int key_y;
    int key_add1=0;
    int key_add2=0;
    QPixmap key_pix;
    bool key_istaste=false;//默认钥匙没有被吃掉
    bool keypix_show = 0;
    QRect key_rec;
    QTimer timer;
    int random_num1=0;
    int random_num2=0;
    int key_i=0;
signals:

public slots:
};

#endif // KEY_H

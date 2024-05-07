#ifndef HOLE_H
#define HOLE_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include "config.h"

class Hole : public QWidget
{
    Q_OBJECT
public:
    explicit Hole(QWidget *parent = nullptr);
    QPixmap hole_pix;
    QPixmap fire_hole_pix;
    int hole_x;
    int hole_y;
    int fire_hole_x;
    int fire_hole_y;
    int fire_up_max;
    int fire_down_max;
    bool fire_up=true;
    bool fire_down=false;

    QRect hole_rec;
    QRect fire_hole_rec;

    QTimer timer6;
    void fire_moving();

signals:

public slots:
};

#endif // HOLE_H

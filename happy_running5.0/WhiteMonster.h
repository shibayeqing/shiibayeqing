#ifndef WHITEMONSTER_H
#define WHITEMONSTER_H

#include <QMainWindow>
#include "config.h"
#include <QPixmap>
#include <QTimer>

class WhiteMonster : public QMainWindow
{
    Q_OBJECT
public:
    explicit WhiteMonster(QWidget *parent = nullptr);
    QPixmap whitemonster1_pix;
    QPixmap whitemonster2_pix;
    QRect whitemonster1_rec;
    QRect whitemonster2_rec;

    int whitemonster_x1;
    int whitemonster_y1;
    int whitemonster_x2;
    int whitemonster_y2;

    int whitemonster1_up_max;
    int whitemonster2_up_max;
    int whitemonster_down_max;

    bool whitemonster1_up=true;
    bool whitemonster1_down=false;
    bool whitemonster2_up=true;
    bool whitemonster2_down=false;

    QTimer timer5;
    void whitemonster_moving();

signals:

public slots:
};

#endif // WHITEMONSTER_H

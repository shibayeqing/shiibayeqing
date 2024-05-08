#ifndef WINNER_H
#define WINNER_H

#include <QMainWindow>
#include "config.h"
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include<QPushButton>

class Winner : public QMainWindow
{
    Q_OBJECT
public:
    explicit Winner(QWidget *parent = nullptr);
    QPixmap winner_pix;

    int winnertime_x=700;
    int winnertime_y=590;
    int winnername_x=700;
    int winnername_y=450;
    int time = 0;
    int score = 0;
    void paintEvent(QPaintEvent *event);
    QTimer timer;
    //QFont font;
    QPushButton *exitbutton;
    bool winnerplayer;//true为上方猫胜利，false为下方猫胜利

signals:

public slots:
};

#endif // WINNER_H

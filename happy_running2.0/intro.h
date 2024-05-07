#ifndef INTRO_H
#define INTRO_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
class intro : public QMainWindow
{
public:intro(QWidget *parent = nullptr);

    QPixmap intro_pix;

    int time = 0;
    void paintEvent(QPaintEvent *event);
    QTimer timer;
};

#endif // INTRO_H

#include "changecolourbutton.h"
#include "config.h"
#include <QTimer>
#include <QPainter>
#include <QString>
Changecolourbutton::Changecolourbutton(QWidget *parent) : QPushButton(parent)
{

   setStyleSheet("QPushButton { background-color: transparent; border: none; }");

    yellow.load(YELLOWBUTTON);

    yellow = yellow.scaled(QSize(500, 125), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    setIcon(QIcon(yellow));
    setIconSize(QSize(500, 125));

    setFixedSize(500, 125); // 设置按钮的固定大小

    connect(this,&QPushButton::pressed,this,&Changecolourbutton::changecolor);

}

void Changecolourbutton::changecolor(){


   red = red.scaled(QSize(500, 125), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

   setIcon(QIcon(red));

   setIconSize(QSize(500, 125));

}

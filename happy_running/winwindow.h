#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
class Winwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Winwindow(QWidget *parent = nullptr);
    QPixmap win_pix;
    QTimer timer;
    void paintEvent(QPaintEvent *event);
    int y = 0;//y坐标
signals:

public slots:
};

#endif // WINWINDOW_H

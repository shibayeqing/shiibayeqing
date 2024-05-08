#ifndef GRASSGROUND_H
#define GRASSGROUND_H
#include <QPixmap>
#include <QWidget>

class GrassGround : public QWidget
{
    Q_OBJECT
public:
    explicit GrassGround(QWidget *parent = nullptr);
    QPixmap ground_pix;
    int ground_x;
    int ground_y;
    QRect ground_rec;
signals:

public slots:
};

#endif // GRASSGROUND_H

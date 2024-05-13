#ifndef PIPE_H
#define PIPE_H

#include <QWidget>
#include <QPixmap>

class Pipe : public QWidget
{
    Q_OBJECT
public:
    explicit Pipe(QWidget *parent = nullptr);
    QPixmap tube_pix;
    int tube_x;
    int tube_y;
    QRect tube_rec;

signals:

public slots:
};

#endif // PIPE_H

#ifndef FLAGANDCASTLE_H
#define FLAGANDCASTLE_H

#include <QMainWindow>

class Flagandcastle : public QMainWindow
{
    Q_OBJECT
public:
    explicit Flagandcastle(QWidget *parent = nullptr);
    QPixmap flag_pic;
    QPixmap flagpole_pic;
    QPixmap castle_pic;
    int flag_x;
    int flag_y;
    int flagpole_x;
    int flagpole_y;
    int castle_x;
    int castle_y;
    QRect flag_rec;
    QRect castle_rec;
    bool flagdown = 0;
signals:

public slots:
};

#endif // FLAGANDCASTLE_H

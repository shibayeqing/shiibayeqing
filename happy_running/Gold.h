#ifndef GOLD_H
#define GOLD_H

#include <QWidget>
#include <QPixmap>

class Gold : public QWidget
{
    Q_OBJECT
public:
    explicit Gold(QWidget *parent = nullptr);
    int pix_index=0;//控制分割图的下标
    QPixmap gold_pix;
    QRect gold_rec;
    int gold_x;//设置金币组的X坐标
    int gold_y;//设置金币组的Y坐标
    bool gold_life=0;
    //设置金币的生命，false表示金币未被吃掉，true表示金币已经被吃掉
    //bool值的默认值是false,一旦猫触碰到相应金币的生命值变为true



signals:

public slots:
};

#endif // GOLD_H

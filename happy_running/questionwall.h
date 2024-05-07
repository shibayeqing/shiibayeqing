#ifndef QUESTIONWALL_H
#define QUESTIONWALL_H

#include <QMainWindow>
#include <QPixmap>
class QuestionWall : public QMainWindow
{
    Q_OBJECT
public:
    explicit QuestionWall(QMainWindow *parent = nullptr);
    int question_x;
    int question_y;
    int pix_biao=0;//控制分割图的下标

    bool question_state=true;//开始时问号墙是完好的,这个变量主要是控制切图时应该绘制哪幅图
    QPixmap question_pix;
    QRect question_rec;
signals:

public slots:
};

#endif // QUESTIONWALL_H

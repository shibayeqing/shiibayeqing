#include "questionwall.h"
#include<QRect>
#include"config.h"
#include<QPixmap>

QuestionWall::QuestionWall(QMainWindow *parent) : QMainWindow(parent)
{
    question_pix.load(QUESTION_PICTURE);
    question_pix = question_pix .scaled(800,50);
    question_rec.setWidth(100);
    question_rec.setHeight(60);
    //question_rec.
}

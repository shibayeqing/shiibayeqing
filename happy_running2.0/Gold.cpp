#include "Gold.h"
#include "config.h"
Gold::Gold(QWidget *parent) : QWidget(parent)
{
    gold_pix.load(Gold_PICTURE);
    gold_rec.setWidth(30);
    gold_rec.setHeight(33);



}


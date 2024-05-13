#include "flagandcastle.h"
#include <config.h>

Flagandcastle::Flagandcastle(QWidget *parent) : QMainWindow(parent)
{
    flag_pic.load(FLAG_PIC);
    flagpole_pic.load(FLAGPOLE_PIC);
    castle_pic.load(CASTLE_PIC);
   castle_pic =  castle_pic.scaled(350,350);
    flag_rec.setSize(QSize(75,FLAGPOLE_HEIGHT));
    castle_rec.setSize(QSize(100,CASTLE_HEIGHT));

}

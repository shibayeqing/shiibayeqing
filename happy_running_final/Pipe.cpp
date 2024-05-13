#include "Pipe.h"
#include "config.h"

Pipe::Pipe(QWidget *parent) : QWidget(parent)
{
    tube_pix.load(Pipe_PICTURE);
//    tube_x=350;
//    tube_y=WINDOW_WIDTH-Pipe_WIDTH-Background_WIDTH;
}

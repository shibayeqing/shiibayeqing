#include "coincounter.h"
#include <QPixmap>
#include <config.h>
CoinCounter::CoinCounter(QWidget *parent) : QMainWindow(parent)
{
    coincounterpic.load(COINCOUNTER_PICTURE);
}

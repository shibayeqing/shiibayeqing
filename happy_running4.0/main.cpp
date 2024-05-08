#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include<QResource>
    int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//实例化了QApplication
    QResource::registerResource("./picture.rcc");//通过registerResource文件动态加载
    a.setWindowIcon(QIcon("://picture/bl2.png"));//
    MainWindow w;//实例化了一个窗口
    w.show();//让窗口显示
    QScreen *screen=QGuiApplication::primaryScreen ();//获取主屏幕
    QRect mm=screen->availableGeometry() ;//返回屏幕可用几何图形大小
    int screen_width = mm.width();//屏幕宽度
    int screen_height = mm.height();//屏幕高度
    w.move ((screen_width - w.width())/2,//通过QApplication的函数
            (screen_height - w.height())/2);//让窗口始终居中显示

    return a.exec();
}

#include "key.h"
#include<QPixmap>
#include"config.h"
#include<QTimer>
#include <random>
#include<QDebug>
#include<ctime>
Key::Key(QWidget *parent) : QWidget(parent)
{
    // 在需要生成随机数的地方
    srand((unsigned int)time(NULL));//随机数种子，用于敌机出场的随机位置
     random_num1 =rand()%(3);
    random_num1+=3;
     random_num2 =rand()%(3);
    random_num2+=10;
//    std::random_device rd;  // 获取真随机数种子
//    std::mt19937 gen(rd());  // 使用种子初始化伪随机数生成器
//    std::uniform_int_distribution<int> dis(2,6); // 定义一个范围的均匀分布

//    int random_num1 = dis(gen);  // 生成随机数
//    int random_num2 = dis(gen);
    qDebug()<<"aaaaa"<<random_num1<<"bbbbb"<<random_num2;
    key_pix.load(KEY_PICTURE);
    key_pix =key_pix .scaled(50,50);
    key_rec.setWidth(50);
    key_rec.setHeight(50);
}


/* By the passion of B&C&Y, 09.23*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "turtle.h"
#include "cat.h"
#include "wall.h"
#include "monster.h"
#include "mushroom.h"
#include <QWidget>
#include "grassground.h"
#include "questionwall.h"
#include "bullet.h"
#include "WhiteMonster.h"
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <cat_heath.h>
#include <QMediaPlayer>
#include <dj.h>
#include "Winner.h"
#include "Rocket.h"
#include "MoveGround.h"
#include "config.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//new了一个ui域上的MainWindow
    scene = new QGraphicsScene(this);//创建一个新的QGraphicsScene 变量，父类为mianwindow
    setWindowTitle("happy run");//修改标题
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//禁用滚动条
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1460, 740);//固定窗口的尺寸
    loginwindow();
    dj = new DJ(this);//创建播放管理器
    connect(ui->actionABOUT_US, &QAction::triggered, this, [=](){
        winwindow.show();
    });
    connect(ui->playagian, &QAction::triggered, this, [=](){
        playagian();
    });
    connect(ui->introduction, &QAction::triggered, this, [=](){
        introduction.show();
    });
    connect(ui->music, &QAction::triggered, this, [=](){
        if (musicEnabled) {
             emit soundeffect("stop");
         } else {
             emit soundeffect("theme");
         }
         musicEnabled = !musicEnabled; // 切换状态
    });
}

// 编写loginwindow
void MainWindow::loginwindow()
{

    ui->graphicsView->setScene(scene);     // 将scene设置给QGraphicsView
    ui->graphicsView->move(0,0);

    QPixmap loginbackgroundimage("://picture/background.png");
    QGraphicsPixmapItem* background = //设置背景图适应graphicsView的大小
    new QGraphicsPixmapItem(loginbackgroundimage.scaled(ui->graphicsView->size(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    background->setPos(0, 0);
    scene->addItem(background);        //设置背景图

    QPixmap icon1("://picture/icon001.png");
    QGraphicsPixmapItem* iconpic1 =
    new QGraphicsPixmapItem(icon1.scaled(QSize(256,300),Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    iconpic1->setPos(100,200);
    iconpic1->setZValue(100);
    scene->addItem(iconpic1);        //设置cat1

    QPixmap icon2("://picture/loginlogo.png");
    QGraphicsPixmapItem* iconpic2 =
    new QGraphicsPixmapItem(icon2.scaled(QSize(256,300),Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    iconpic2->setPos(1150,200);
    iconpic2->setZValue(100);
    scene->addItem(iconpic2);        //设置cat2

    QPixmap mainlogo("://picture/logo.png");
    QGraphicsPixmapItem* logo = new QGraphicsPixmapItem(mainlogo.scaled(QSize(800,400),Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    logo->setPos(350,0);
    logo->setZValue(100);
    scene->addItem(logo);            //设置中心标志

    setCentralWidget(ui->graphicsView);      //背景图窗口设置在主窗口的中心位置

    startbutton = new QPushButton(ui->graphicsView); //创建开始按钮
    startbutton->setGeometry(660, 460, 150, 150); //设置位置和大小
    startbutton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    startbutton->setIcon(QIcon("://picture/startButton.png"));
    startbutton->setIconSize(QSize(170, 170));// 设置图片的大小
    settingbutton = new QPushButton(ui->graphicsView); //创建选项按钮
    settingbutton->setGeometry(900, 490, 100, 100); //设置位置和大小
    settingbutton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    settingbutton->setIcon(QIcon("://picture/settingButton.png"));
    settingbutton->setIconSize(QSize(100, 100)); // 设置图片的大小
    exitbutton = new QPushButton(ui->graphicsView); //创建退出按钮
    exitbutton->setGeometry(470, 490, 100, 100); //设置位置和大小
    exitbutton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    exitbutton->setIcon(QIcon("://picture/exitButton.png"));
    exitbutton->setIconSize(QSize(100, 100)); // 设置图片的大小
    timer = new QTimer(this);
       connect(timer, &QTimer::timeout, this, &MainWindow::nextframe);
       timer->start(100); // 设置定时器的时间间隔（毫秒）
    connect(startbutton,&QPushButton::pressed,this,&MainWindow::changecolor);//连接槽函数和信号，当按钮被摁下把
    connect(settingbutton,&QPushButton::pressed,this,&MainWindow::changecolor);//颜色变为红色
    connect(exitbutton,&QPushButton::pressed,this,&MainWindow::changecolor);
    connect(startbutton,&QPushButton::clicked,this,[=]()
    {
        gamemode = 0;//双人模式
        changewindow();
    });
    connect(exitbutton,&QPushButton::clicked,[](){ QCoreApplication::quit();});//lambda表达式，关闭程序
    connect(settingbutton,&QPushButton::clicked,this,[=]()
    {
        gamemode = 1;//单人模式
        changewindow();
    });
}

unsigned int i=0;
void MainWindow::nextframe()
{
    if(i==0){startbutton->setIconSize(QSize(165, 165));//resize切换大小
        settingbutton->setIconSize(QSize(97, 97));
        exitbutton->setIconSize(QSize(97, 97));}
    else if(i==1){startbutton->setIconSize(QSize(160, 160));
        settingbutton->setIconSize(QSize(94, 94));
        exitbutton->setIconSize(QSize(94, 94));}
    else if (i==2){startbutton->setIconSize(QSize(155, 155));
        settingbutton->setIconSize(QSize(91, 91));
        exitbutton->setIconSize(QSize(91, 91));}
    else if (i==3){startbutton->setIconSize(QSize(150, 150));
        settingbutton->setIconSize(QSize(88, 88));
        exitbutton->setIconSize(QSize(88, 88));}
    else if (i==4){startbutton->setIconSize(QSize(145, 145));
        settingbutton->setIconSize(QSize(85, 85));
        exitbutton->setIconSize(QSize(85, 85));}
    else if (i==5){startbutton->setIconSize(QSize(140, 140));
        settingbutton->setIconSize(QSize(82, 82));
        exitbutton->setIconSize(QSize(82, 82));}
    else if (i==6){startbutton->setIconSize(QSize(135, 135));
        settingbutton->setIconSize(QSize(79, 79));
        exitbutton->setIconSize(QSize(79, 79));}
    else if (i==7){startbutton->setIconSize(QSize(130, 130));
        settingbutton->setIconSize(QSize(76, 76));
        exitbutton->setIconSize(QSize(76, 76));}
    else if (i==8){startbutton->setIconSize(QSize(125, 125));
        settingbutton->setIconSize(QSize(73, 73));
        exitbutton->setIconSize(QSize(73, 73));}
    else if (i==9){startbutton->setIconSize(QSize(120, 120));
        settingbutton->setIconSize(QSize(70, 70));
        exitbutton->setIconSize(QSize(70, 70));}
    else if(i==10){startbutton->setIconSize(QSize(125, 125));
        settingbutton->setIconSize(QSize(73, 73));
        exitbutton->setIconSize(QSize(73, 73));}
    else if (i==11){startbutton->setIconSize(QSize(130, 130));
        settingbutton->setIconSize(QSize(76, 76));
        exitbutton->setIconSize(QSize(76, 76));}
    else if (i==12){startbutton->setIconSize(QSize(135, 135));
        settingbutton->setIconSize(QSize(79, 79));
        exitbutton->setIconSize(QSize(79, 79));}
    else if (i==13){startbutton->setIconSize(QSize(140, 140));
        settingbutton->setIconSize(QSize(82, 82));
        exitbutton->setIconSize(QSize(82, 82));}
    else if (i==14){startbutton->setIconSize(QSize(145, 145));
        settingbutton->setIconSize(QSize(85, 85));
        exitbutton->setIconSize(QSize(85, 85));}
    else if (i==15){startbutton->setIconSize(QSize(150, 150));
        settingbutton->setIconSize(QSize(88, 88));
        exitbutton->setIconSize(QSize(88, 88));}
    else if (i==16){startbutton->setIconSize(QSize(155, 155));
        settingbutton->setIconSize(QSize(91, 91));
        exitbutton->setIconSize(QSize(91, 91));}
    else if (i==17){startbutton->setIconSize(QSize(160, 160));
        settingbutton->setIconSize(QSize(94, 94));
        exitbutton->setIconSize(QSize(94, 94));}
    else if (i==18){{startbutton->setIconSize(QSize(165, 165));
            settingbutton->setIconSize(QSize(97, 97));
            exitbutton->setIconSize(QSize(97, 97));}
        i=0;}
    i++;
}

void MainWindow::changecolor()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());//获取信号的来源，不同的按钮不同处理
      if (button == startbutton){
         emit soundeffect("button");
         startbutton->setIcon(QIcon("://picture/startButton2.png"));//变色
      }
      else if (button == settingbutton){
         emit soundeffect("button");
         settingbutton->setIcon(QIcon("://picture/settingButton2.png"));
      }
      else if (button == exitbutton){
          emit soundeffect("button");
          exitbutton->setIcon(QIcon("://picture/exitButton2.png"));
      }
}

void MainWindow::changewindow()
{
    //将loginwindow变化为gamewindow
    ui->graphicsView->hide();
    scene->clear();//清楚原先场景
    startbutton->hide();//隐藏三个按钮
    settingbutton->hide();
    exitbutton->hide();
    if (gamemode == 0){//双人模式
        setFixedSize(1640,1340);
        move(this->x()-100,0);
    }
    gamebegin();
}

// 游戏开始函数
void MainWindow::gamebegin()
{
    if( update_only_once == 1){
        initScence();
        qDebug()<<"update";
        update_only_once++;
        for(int i=0;i<6;i++){
            turtle[i].moving();
        }//建立乌龟移动的信号与槽
        for(int i=0;i<14;i++){
            monster[i].moving();
        }//建立小怪移动的信号与槽
        for(int i=0;i<5;i++){
            bullet0[i].shoot();//建立每发子弹的信号与槽
        }
        for(int i=0;i<5;i++){
            bullet1[i].shoot();//建立每发子弹的信号与槽
        }
        for(int i=0;i<8;i++){
            moveground[i].ground_moving();
        }
        for(int i=0;i<2;i++){
            whitemonster[i].whitemonster_moving();
        }
        for(int i=0;i<4;i++){
            fire_hole[i].fire_moving();
        }
    }
    build_wall();
    set_whitemonster();
    set_turtle();
    set_monster();
    set_moveground();
    set_grassground(); 
    setCoin();
    set_hole();
    set_key();
    set_flagandcastle();
    setFocusPolicy(Qt::StrongFocus);
    if(gamemode==1)
        time.timetoover= GAMETIME1;//计时开始，时间结束后游戏结束
    if(gamemode==0)
        time.timetoover= GAMETIME2;//计时开始，时间结束后游戏结束
    // 播放背景音乐
    connect(this, &MainWindow::soundeffect, dj, &DJ::playsoundeffect);
    emit soundeffect("theme");
    mushroom_moving();
    rocket_moving1();
    rocket_moving2();
    key_moving();
    connect(&update_timer,&QTimer::timeout,[=](){
        update();
        crash();//利用这个定时器来反复执行碰撞函数来检测碰撞是否发生
        cat[0].cat_auto_down();//猫的自动下落初始
        cat[1].cat_auto_down();//猫的自动下落初始
        cat_any_down();//猫自动下落的补充
        cat_float();
        cat_moveground_down();
        cat[0].cat_move();//反复调用猫是否移动的检测函数
        cat[1].cat_move();//反复调用猫是否移动的检测函数
    });
        cat[1].cat_y+=BIAS+10;
        cat[1].iscat2=true;
        cat[1].cat_jump_height=cat[1].cat_y-270;
}

void MainWindow::setCoin()
{
    gold[0].gold_x = 1155;gold[0].gold_y=202;gold[1].gold_x = 1205;gold[1].gold_y=152;
    gold[2].gold_x = 1265;gold[2].gold_y=122;gold[3].gold_x = 1325;gold[3].gold_y=122;
    gold[4].gold_x = 1385;gold[4].gold_y=152;gold[5].gold_x = 1435;gold[5].gold_y=202;
    gold[6].gold_x = 2770;gold[6].gold_y=540;gold[7].gold_x = 2820;gold[7].gold_y=540;
    gold[8].gold_x = 2870;gold[8].gold_y=370;gold[18].gold_x = 2995;gold[18].gold_y=370;
    gold[19].gold_x = 3045;gold[19].gold_y=540;gold[20].gold_x = 3095;gold[20].gold_y=540;
    gold[9].gold_x = 3570;gold[9].gold_y=370;gold[10].gold_x = 3620;gold[10].gold_y=370;

    gold[11].gold_x = 3840;gold[11].gold_y=300;gold[12].gold_x = 3840;gold[12].gold_y=260;
    gold[13].gold_x = 3840;gold[13].gold_y=220;gold[14].gold_x = 3880;gold[14].gold_y=300;
    gold[15].gold_x = 3880;gold[15].gold_y=260;gold[16].gold_x = 3880;gold[16].gold_y=220;
    gold[17].gold_x = 3920;gold[17].gold_y=300;gold[21].gold_x = 3920;gold[21].gold_y=260;
    gold[22].gold_x = 3920;gold[22].gold_y=220;gold[23].gold_x = 3960;gold[23].gold_y=300;qDebug()<<"000";
    gold[24].gold_x = 3960;gold[24].gold_y=260;qDebug()<<"111";gold[25].gold_x = 3960;gold[25].gold_y=220;
    gold[26].gold_x = 4000;gold[26].gold_y=300;gold[27].gold_x = 4000;gold[27].gold_y=260;
    gold[28].gold_x = 4000;gold[28].gold_y=220;gold[29].gold_x = 3960;gold[29].gold_y=180;
    gold[30].gold_x = 3960;gold[30].gold_y=340;gold[31].gold_x = 4040;gold[31].gold_y=260;

    const int x=1300;

    gold[37].gold_x = 3840+x;gold[37].gold_y=300;gold[38].gold_x = 3840+x;gold[38].gold_y=260;
    gold[39].gold_x = 3840+x;gold[39].gold_y=220;gold[40].gold_x = 3880+x;gold[40].gold_y=300;
    gold[41].gold_x = 3880+x;gold[41].gold_y=260;gold[42].gold_x = 3880+x;gold[42].gold_y=220;
    gold[43].gold_x = 3920+x;gold[43].gold_y=300;gold[44].gold_x = 3920+x;gold[44].gold_y=260;
    gold[45].gold_x = 3920+x;gold[45].gold_y=220;gold[46].gold_x = 3960+x;gold[46].gold_y=300;
    gold[47].gold_x = 3960+x;gold[47].gold_y=260;gold[48].gold_x = 3960+x;gold[48].gold_y=220;
    gold[49].gold_x = 4000+x;gold[49].gold_y=300;gold[50].gold_x = 4000+x;gold[50].gold_y=260;
    gold[51].gold_x = 4000+x;gold[51].gold_y=220;gold[52].gold_x = 3960+x;gold[52].gold_y=180;
    gold[53].gold_x = 3960+x;gold[53].gold_y=340;gold[54].gold_x = 4040+x;gold[54].gold_y=260;

    gold[32].gold_x = 6370;gold[32].gold_y=314;gold[33].gold_x = 6420;gold[33].gold_y=264;gold[34].gold_x = 6470;gold[34].gold_y=244;
    gold[35].gold_x = 6520;gold[35].gold_y=264;gold[36].gold_x = 6570;gold[36].gold_y=314;
    gold[55].gold_x = 4850;gold[55].gold_y=440;gold[56].gold_x = 4890;gold[56].gold_y=390;gold[57].gold_x = 4930;gold[57].gold_y=370;
    gold[58].gold_x = 4970;gold[58].gold_y=390;gold[59].gold_x = 5010;gold[59].gold_y=440;

    gold[60].gold_x=gold[61].gold_x=7700;gold[62].gold_x=gold[63].gold_x=7750;
    gold[60].gold_y=gold[62].gold_y=150;gold[61].gold_y=gold[63].gold_y=100;

    gold[64].gold_x=7100;gold[65].gold_x=7200;gold[66].gold_x=7300;
    gold[64].gold_y=517;gold[65].gold_y=417;gold[66].gold_y=317;

    gold[67].gold_x=8150;gold[68].gold_x=8200;gold[69].gold_x=8250;
    gold[70].gold_x=8400;gold[71].gold_x=8450;gold[72].gold_x=8500;
    gold[67].gold_y=gold[68].gold_y=gold[69].gold_y=520;gold[70].gold_y=gold[71].gold_y=gold[72].gold_y=340;

    gold[73].gold_x=gold[74].gold_x=8700;gold[75].gold_x=gold[76].gold_x=8750;
    gold[77].gold_x=gold[78].gold_x=8800;gold[73].gold_y=gold[75].gold_y=gold[77].gold_y=190;
    gold[74].gold_y=gold[76].gold_y=gold[78].gold_y=150;

    gold[79].gold_x=gold[80].gold_x=9350;gold[81].gold_x=gold[82].gold_x=9400;gold[83].gold_x=gold[84].gold_x=9450;
    gold[79].gold_y=gold[81].gold_y=gold[83].gold_y=190;gold[80].gold_y=gold[82].gold_y=gold[84].gold_y=150;

    gold[85].gold_x=8700;gold[86].gold_x=8750;gold[87].gold_x=8800;gold[88].gold_x=8850;
    gold[89].gold_x=8900;gold[90].gold_x=8950;gold[91].gold_x=9000;gold[92].gold_x=9050;
    gold[85].gold_y=280;gold[86].gold_y=280;gold[87].gold_y=280;gold[88].gold_y=280;gold[89].gold_y=280;gold[90].gold_y=280;

    gold[93].gold_x=8700;gold[94].gold_x=8700;gold[95].gold_x=8700;gold[96].gold_x=8700;
    gold[97].gold_x=8700;gold[98].gold_x=8700;gold[99].gold_x=9050;gold[100].gold_x=9050;
    gold[101].gold_x=9050;gold[102].gold_x=9050;gold[103].gold_x=9050;gold[104].gold_x=9050;

    gold[93].gold_y=330;gold[94].gold_y=380;gold[95].gold_y=430;gold[96].gold_y=480;
    gold[97].gold_y=530;gold[98].gold_y=580;gold[99].gold_y=330;gold[100].gold_y=380;
    gold[101].gold_y=430;gold[102].gold_y=480;gold[103].gold_y=530;gold[104].gold_y=580;

    gold[105].gold_x=8750;gold[106].gold_x=8800;gold[107].gold_x=8850;gold[108].gold_x=8900;gold[109].gold_x=8950;gold[110].gold_x=9000;
    gold[105].gold_y=580;gold[106].gold_y=580;gold[107].gold_y=580;gold[108].gold_y=580;gold[109].gold_y=580;gold[110].gold_y=580;

    gold[111].gold_x=9350;gold[112].gold_x=9400;gold[113].gold_x=9450;gold[114].gold_x=9500;gold[115].gold_x=9550;gold[116].gold_x=9600;
    gold[117].gold_x=9650;gold[118].gold_x=9700;gold[111].gold_y=280;gold[112].gold_y=280;gold[113].gold_y=280;gold[114].gold_y=280;
    gold[115].gold_y=280;gold[116].gold_y=280;gold[117].gold_y=280;gold[118].gold_y=280;

    gold[119].gold_x=9500;gold[120].gold_x=9550;gold[121].gold_x=9500;gold[122].gold_x=9550;gold[123].gold_x=9500;gold[124].gold_x=9550;
    gold[125].gold_x=9500;gold[126].gold_x=9550;gold[127].gold_x=9500;gold[128].gold_x=9550;gold[129].gold_x=9500;gold[130].gold_x=9550;
    gold[131].gold_x=9500;gold[132].gold_x=9550;gold[119].gold_y=gold[120].gold_y=280;gold[121].gold_y=gold[122].gold_y=330;
    gold[123].gold_y=gold[124].gold_y=380;gold[125].gold_y=gold[126].gold_y=430;gold[127].gold_y=gold[128].gold_y=480;
    gold[129].gold_y=gold[130].gold_y=530;gold[131].gold_y=gold[132].gold_y=580;

    gold[133].gold_x=gold[134].gold_x=8950;gold[135].gold_x=gold[136].gold_x=9000;
    gold[137].gold_x=gold[138].gold_x=9050;gold[133].gold_y=gold[135].gold_y=gold[137].gold_y=190;
    gold[134].gold_y=gold[136].gold_y=gold[138].gold_y=150;

    gold[139].gold_x=gold[140].gold_x=9600;gold[141].gold_x=gold[142].gold_x=9650;gold[143].gold_x=gold[144].gold_x=9700;
    gold[139].gold_y=gold[141].gold_y=gold[143].gold_y=190;gold[140].gold_y=gold[142].gold_y=gold[144].gold_y=150;

    gold[145].gold_x=9000;gold[145].gold_y=530;gold[146].gold_x=8950;gold[146].gold_y=480;
    gold[147].gold_x=8900;gold[147].gold_y=430;gold[148].gold_x=9050;gold[148].gold_y=610;

    gold[149].gold_x=9350;gold[150].gold_x=9400;gold[151].gold_x=9450;gold[152].gold_x=9600;
    gold[153].gold_x=9650;gold[154].gold_x=9700;gold[149].gold_y=330;gold[150].gold_y=330;
    gold[151].gold_y=330;gold[152].gold_y=330;gold[153].gold_y=330;gold[154].gold_y=330;

    gold[155].gold_x=9500;gold[156].gold_x=9550; gold[155].gold_y=gold[156].gold_y=630;
    gold[157].gold_x=gold[158].gold_x=6855;gold[157].gold_y=607;gold[158].gold_y=647;

    gold[159].gold_x=10661;gold[159].gold_y=450;gold[160].gold_x=10711;gold[160].gold_y=450;gold[161].gold_x=10761;gold[161].gold_y=450;

    gold[162].gold_x=10350;gold[162].gold_y=170;
    gold[163].gold_x=10400;gold[163].gold_y=200;
    gold[164].gold_x=10450;gold[164].gold_y=230;

    for(int i=0;i<165;i++)
    {
        gold[i].gold_rec.moveTo(gold[i].gold_x,gold[i].gold_y);
    }

    if(gamemode == 0)//双人模式
    {
        gold[0].gold_x = 1155;gold[0].gold_y=202;
        gold[1].gold_x = 1205;gold[1].gold_y=152;
        gold[2].gold_x = 1265;gold[2].gold_y=122;
        gold[3].gold_x = 1325;gold[3].gold_y=122;
        gold[4].gold_x = 1385;gold[4].gold_y=152;
        gold[5].gold_x = 1435;gold[5].gold_y=202;

        gold[6].gold_x = 2770;gold[6].gold_y=540;
        gold[7].gold_x = 2820;gold[7].gold_y=540;
        gold[8].gold_x = 2870;gold[8].gold_y=370;
        gold[18].gold_x = 2995;gold[18].gold_y=370;
        gold[19].gold_x = 3045;gold[19].gold_y=540;
        gold[20].gold_x = 3095;gold[20].gold_y=540;

        gold[9].gold_x = 3570;gold[9].gold_y=370;
        gold[10].gold_x = 3620;gold[10].gold_y=370;

        gold[11].gold_x = 3840;gold[11].gold_y=300;
        gold[12].gold_x = 3840;gold[12].gold_y=260;
        gold[13].gold_x = 3840;gold[13].gold_y=220;
        gold[14].gold_x = 3880;gold[14].gold_y=300;
        gold[15].gold_x = 3880;gold[15].gold_y=260;
        gold[16].gold_x = 3880;gold[16].gold_y=220;
        gold[17].gold_x = 3920;gold[17].gold_y=300;
        gold[21].gold_x = 3920;gold[21].gold_y=260;
        gold[22].gold_x = 3920;gold[22].gold_y=220;
        gold[23].gold_x = 3960;gold[23].gold_y=300;qDebug()<<"000";
        gold[24].gold_x = 3960;gold[24].gold_y=260;qDebug()<<"111";
        gold[25].gold_x = 3960;gold[25].gold_y=220;
        gold[26].gold_x = 4000;gold[26].gold_y=300;
        gold[27].gold_x = 4000;gold[27].gold_y=260;
        gold[28].gold_x = 4000;gold[28].gold_y=220;
        gold[29].gold_x = 3960;gold[29].gold_y=180;
        gold[30].gold_x = 3960;gold[30].gold_y=340;
        gold[31].gold_x = 4040;gold[31].gold_y=260;

        const int x=1300,y=100;

        gold[37].gold_x = 3840+x;gold[37].gold_y=300;
        gold[38].gold_x = 3840+x;gold[38].gold_y=260;
        gold[39].gold_x = 3840+x;gold[39].gold_y=220;
        gold[40].gold_x = 3880+x;gold[40].gold_y=300;
        gold[41].gold_x = 3880+x;gold[41].gold_y=260;
        gold[42].gold_x = 3880+x;gold[42].gold_y=220;
        gold[43].gold_x = 3920+x;gold[43].gold_y=300;
        gold[44].gold_x = 3920+x;gold[44].gold_y=260;
        gold[45].gold_x = 3920+x;gold[45].gold_y=220;
        gold[46].gold_x = 3960+x;gold[46].gold_y=300;
        gold[47].gold_x = 3960+x;gold[47].gold_y=260;
        gold[48].gold_x = 3960+x;gold[48].gold_y=220;
        gold[49].gold_x = 4000+x;gold[49].gold_y=300;
        gold[50].gold_x = 4000+x;gold[50].gold_y=260;
        gold[51].gold_x = 4000+x;gold[51].gold_y=220;
        gold[52].gold_x = 3960+x;gold[52].gold_y=180;
        gold[53].gold_x = 3960+x;gold[53].gold_y=340;
        gold[54].gold_x = 4040+x;gold[54].gold_y=260;


        gold[32].gold_x = 6370;gold[32].gold_y=314;
        gold[33].gold_x = 6420;gold[33].gold_y=264;
        gold[34].gold_x = 6470;gold[34].gold_y=244;
        gold[35].gold_x = 6520;gold[35].gold_y=264;
        gold[36].gold_x = 6570;gold[36].gold_y=314;


        gold[55].gold_x = 4850;gold[55].gold_y=440;
        gold[56].gold_x = 4890;gold[56].gold_y=390;
        gold[57].gold_x = 4930;gold[57].gold_y=370;
        gold[58].gold_x = 4970;gold[58].gold_y=390;
        gold[59].gold_x = 5010;gold[59].gold_y=440;

        gold[60].gold_x=gold[61].gold_x=7700;
        gold[62].gold_x=gold[63].gold_x=7750;
        gold[60].gold_y=gold[62].gold_y=150;
        gold[61].gold_y=gold[63].gold_y=100;

        gold[64].gold_x=7100;
        gold[65].gold_x=7200;
        gold[66].gold_x=7300;
        gold[64].gold_y=517;
        gold[65].gold_y=417;
        gold[66].gold_y=317;

        gold[67].gold_x=8150;
        gold[68].gold_x=8200;
        gold[69].gold_x=8250;
        gold[70].gold_x=8400;
        gold[71].gold_x=8450;
        gold[72].gold_x=8500;
        gold[67].gold_y=gold[68].gold_y=gold[69].gold_y=520;
        gold[70].gold_y=gold[71].gold_y=gold[72].gold_y=340;

        gold[73].gold_x=gold[74].gold_x=8700;
        gold[75].gold_x=gold[76].gold_x=8750;
        gold[77].gold_x=gold[78].gold_x=8800;
        gold[73].gold_y=gold[75].gold_y=gold[77].gold_y=190;
        gold[74].gold_y=gold[76].gold_y=gold[78].gold_y=150;

        gold[79].gold_x=gold[80].gold_x=9350;
        gold[81].gold_x=gold[82].gold_x=9400;
        gold[83].gold_x=gold[84].gold_x=9450;
        gold[79].gold_y=gold[81].gold_y=gold[83].gold_y=190;
        gold[80].gold_y=gold[82].gold_y=gold[84].gold_y=150;

        gold[85].gold_x=8700;gold[86].gold_x=8750;
        gold[87].gold_x=8800;gold[88].gold_x=8850;
        gold[89].gold_x=8900;gold[90].gold_x=8950;
        gold[91].gold_x=9000;gold[92].gold_x=9050;
        gold[85].gold_y=280;gold[86].gold_y=280;
        gold[87].gold_y=280;gold[88].gold_y=280;
        gold[89].gold_y=280;gold[90].gold_y=280;
        gold[91].gold_y=280;gold[92].gold_y=280;

        gold[93].gold_x=8700;gold[94].gold_x=8700;
        gold[95].gold_x=8700;gold[96].gold_x=8700;
        gold[97].gold_x=8700;gold[98].gold_x=8700;
        gold[99].gold_x=9050;gold[100].gold_x=9050;
        gold[101].gold_x=9050;gold[102].gold_x=9050;
        gold[103].gold_x=9050;gold[104].gold_x=9050;

        gold[93].gold_y=330;gold[94].gold_y=380;
        gold[95].gold_y=430;gold[96].gold_y=480;
        gold[97].gold_y=530;gold[98].gold_y=580;
        gold[99].gold_y=330;gold[100].gold_y=380;
        gold[101].gold_y=430;gold[102].gold_y=480;
        gold[103].gold_y=530;gold[104].gold_y=580;

        gold[105].gold_x=8750;gold[106].gold_x=8800;
        gold[107].gold_x=8850;gold[108].gold_x=8900;
        gold[109].gold_x=8950;gold[110].gold_x=9000;

        gold[105].gold_y=580;gold[106].gold_y=580;
        gold[107].gold_y=580;gold[108].gold_y=580;
        gold[109].gold_y=580;gold[110].gold_y=580;

        gold[111].gold_x=9350;gold[112].gold_x=9400;
        gold[113].gold_x=9450;gold[114].gold_x=9500;
        gold[115].gold_x=9550;gold[116].gold_x=9600;
        gold[117].gold_x=9650;gold[118].gold_x=9700;
        gold[111].gold_y=280;gold[112].gold_y=280;
        gold[113].gold_y=280;gold[114].gold_y=280;
        gold[115].gold_y=280;gold[116].gold_y=280;
        gold[117].gold_y=280;gold[118].gold_y=280;

        gold[119].gold_x=9500;gold[120].gold_x=9550;
        gold[121].gold_x=9500;gold[122].gold_x=9550;
        gold[123].gold_x=9500;gold[124].gold_x=9550;
        gold[125].gold_x=9500;gold[126].gold_x=9550;
        gold[127].gold_x=9500;gold[128].gold_x=9550;
        gold[129].gold_x=9500;gold[130].gold_x=9550;
        gold[131].gold_x=9500;gold[132].gold_x=9550;
        gold[119].gold_y=gold[120].gold_y=280;
        gold[121].gold_y=gold[122].gold_y=330;
        gold[123].gold_y=gold[124].gold_y=380;
        gold[125].gold_y=gold[126].gold_y=430;
        gold[127].gold_y=gold[128].gold_y=480;
        gold[129].gold_y=gold[130].gold_y=530;
        gold[131].gold_y=gold[132].gold_y=580;

        gold[133].gold_x=gold[134].gold_x=8950;
        gold[135].gold_x=gold[136].gold_x=9000;
        gold[137].gold_x=gold[138].gold_x=9050;
        gold[133].gold_y=gold[135].gold_y=gold[137].gold_y=190;
        gold[134].gold_y=gold[136].gold_y=gold[138].gold_y=150;

        gold[139].gold_x=gold[140].gold_x=9600;
        gold[141].gold_x=gold[142].gold_x=9650;
        gold[143].gold_x=gold[144].gold_x=9700;
        gold[139].gold_y=gold[141].gold_y=gold[143].gold_y=190;
        gold[140].gold_y=gold[142].gold_y=gold[144].gold_y=150;

        gold[145].gold_x=9000;gold[145].gold_y=530;
        gold[146].gold_x=8950;gold[146].gold_y=480;
        gold[147].gold_x=8900;gold[147].gold_y=430;
        gold[148].gold_x=9100;gold[148].gold_y=610;

        gold[149].gold_x=9350;gold[150].gold_x=9400;
        gold[151].gold_x=9450;gold[152].gold_x=9600;
        gold[153].gold_x=9650;gold[154].gold_x=9700;
        gold[149].gold_y=330;gold[150].gold_y=330;
        gold[151].gold_y=330;gold[152].gold_y=330;
        gold[153].gold_y=330;gold[154].gold_y=330;

        gold[155].gold_x=9500;gold[156].gold_x=9550;
        gold[155].gold_y=gold[156].gold_y=630;

        gold[157].gold_x=gold[158].gold_x=6855;
        gold[157].gold_y=607;gold[158].gold_y=647;

        gold[159].gold_x=10661;gold[159].gold_y=450;
        gold[160].gold_x=10711;gold[160].gold_y=450;
        gold[161].gold_x=10761;gold[161].gold_y=450;

        gold[162].gold_x=10350;gold[162].gold_y=170;
        gold[163].gold_x=10400;gold[163].gold_y=200;
        gold[164].gold_x=10450;gold[164].gold_y=230;

        for (int i = 165; i < 330; i++)
        {
            gold[i].gold_x = gold[i - 165].gold_x;
            gold[i].gold_y = gold[i - 165].gold_y+BIAS;
        }
        for(int i=0;i<330;i++)
        {
            gold[i].gold_rec.moveTo(gold[i].gold_x,gold[i].gold_y);
        }
    }
}

void MainWindow::set_hole()//设置洞穴
    {
        hole[0].hole_x=2520;
        hole[0].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH-15;
        hole[1].hole_x=2520+Hole_LENGTH-GreenGround_Width;
        hole[1].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH-15;
        hole[2].hole_x=4550;
        hole[2].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH-15;
        hole[3].hole_x=4550+Hole_LENGTH-GreenGround_Width;
        hole[3].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH-15;

        hole[4].hole_x=2520;
        hole[4].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+26-GreenGround_Height;
        hole[5].hole_x=2520+Hole_LENGTH-GreenGround_Width;
        hole[5].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+26-GreenGround_Height;
        hole[6].hole_x=4550;
        hole[6].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+26-GreenGround_Height;
        hole[7].hole_x=4550+Hole_LENGTH-GreenGround_Width;
        hole[7].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+26-GreenGround_Height;

        hole[8].hole_x=2520;
        hole[8].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS-1;
        hole[9].hole_x=2520+Hole_LENGTH-GreenGround_Width;
        hole[9].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS-1;
        hole[10].hole_x=4550;
        hole[10].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS-1;
        hole[11].hole_x=4550+Hole_LENGTH-GreenGround_Width;
        hole[11].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS-1;

        hole[12].hole_x=2520;
        hole[12].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS+30-GreenGround_Height;
        hole[13].hole_x=2520+Hole_LENGTH-GreenGround_Width;
        hole[13].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS+30-GreenGround_Height;
        hole[14].hole_x=4550;
        hole[14].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS+30-GreenGround_Height;
        hole[15].hole_x=4550+Hole_LENGTH-GreenGround_Width;
        hole[15].hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS+30-GreenGround_Height;

        for(int i=0;i<16;i++)
        {
            hole[i].hole_rec.moveTo(hole[i].hole_x,hole[i].hole_y);
        }

        fire_hole[0].fire_hole_x=2548;
        fire_hole[0].fire_hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+26-50;
        fire_hole[1].fire_hole_x=4578;
        fire_hole[1].fire_hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+26-50;
        fire_hole[2].fire_hole_x=2548;
        fire_hole[2].fire_hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS-15;
        fire_hole[3].fire_hole_x=4578;
        fire_hole[3].fire_hole_y=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS-15;

        fire_hole[0].fire_up_max=HEIGHT-GreenGround_Height-GROUND_WIDTH+26-50-30;
        fire_hole[1].fire_up_max=HEIGHT-GreenGround_Height-GROUND_WIDTH+26-50-30;
        fire_hole[2].fire_up_max=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS-15-30;
        fire_hole[3].fire_up_max=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS-15-30;
        fire_hole[0].fire_down_max=HEIGHT-GreenGround_Height-GROUND_WIDTH+26-50;
        fire_hole[1].fire_down_max=HEIGHT-GreenGround_Height-GROUND_WIDTH+26-50;
        fire_hole[2].fire_down_max=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS-15;
        fire_hole[3].fire_down_max=HEIGHT-GreenGround_Height-GROUND_WIDTH+BIAS-15;


    }

    void MainWindow::set_flagandcastle()//设置终点旗帜和城堡
    {

            flagandcastle[0].castle_rec.moveTo(7870+1588*3-800,HEIGHT-CASTLE_HEIGHT-GROUND_WIDTH);
            flagandcastle[0].castle_x=7740+1588*3-800;
            flagandcastle[0].castle_y=HEIGHT-CASTLE_HEIGHT-GROUND_WIDTH+60;

            flagandcastle[1].castle_rec.moveTo(7870+1588*3-800,HEIGHT-CASTLE_HEIGHT-GROUND_WIDTH+BIAS);
            flagandcastle[1].castle_x=7740+1588*3-800;
            flagandcastle[1].castle_y=HEIGHT-CASTLE_HEIGHT-GROUND_WIDTH+BIAS+60;

    }


void MainWindow::set_moveground()
{
    moveground[0].moveground_x=9850;
    moveground[1].moveground_x=9850+GreenGround_l_Length-30;
    moveground[2].moveground_x=9850+GreenGround_l_Length*2-30*2;
    moveground[3].moveground_x=9850+GreenGround_l_Length*3-30*3;
    moveground[0].moveground_y=moveground[1].moveground_y=moveground[2].moveground_y=moveground[3].moveground_y=600;
    moveground[0].moveground_up_max=moveground[1].moveground_up_max=moveground[2].moveground_up_max=moveground[3].moveground_up_max=180;
    moveground[0].moveground_down_max=moveground[1].moveground_down_max=moveground[2].moveground_down_max=moveground[3].moveground_down_max=600;

    moveground[4].moveground_x=9850;
    moveground[5].moveground_x=9850+GreenGround_l_Length-30;
    moveground[6].moveground_x=9850+GreenGround_l_Length*2-30*2;
    moveground[7].moveground_x=9850+GreenGround_l_Length*3-30*3;
    moveground[4].moveground_y=moveground[5].moveground_y=moveground[6].moveground_y=moveground[7].moveground_y=600+BIAS-30;
    moveground[4].moveground_up_max=moveground[5].moveground_up_max=moveground[6].moveground_up_max=moveground[7].moveground_up_max=180+BIAS;
    moveground[4].moveground_down_max=moveground[5].moveground_down_max=moveground[6].moveground_down_max=moveground[7].moveground_down_max=600+BIAS;
}

void MainWindow::set_key()
{
    key[0].key_x=question_wall[key[0].random_num1].question_x;
    key[0].key_y=question_wall[key[0].random_num1].question_y;
    key[0].key_rec.moveTo(question_wall[key[0].random_num1].question_x,question_wall[key[0].random_num1].question_y-50);
    key[1].key_x=question_wall[key[1].random_num2].question_x;
    key[1].key_y=question_wall[key[1].random_num2].question_y;
    qDebug()<<question_wall[key[1].random_num2].question_y-50;
    key[1].key_rec.moveTo(question_wall[key[1].random_num2].question_x,question_wall[key[1].random_num2].question_y-50);
}
void MainWindow::initScence()
{
     update_timer.start(50);
     for(int i=0;i<6;i++)
     {
        turtle[i].tread();//开始时建立乌龟蜷缩信号与槽的联系，但不启动定时器，之后碰撞启动
     }
}

void MainWindow::set_grassground()
{
    for(int i=0,j=0;i<200;j+=96,i++)
        ground[i].ground_x=j;
}

void MainWindow::set_monster()//设置橙色小怪
{
    //单人模式和双人模式上方橙色小怪
    monster[0].monster_x=1660;monster[0].monster_left=1660;monster[0].monster_y=450;
    monster[1].monster_x=2041;monster[1].monster_left=2041;monster[1].monster_y=HEIGHT-GROUND_WIDTH-43-30;
    monster[2].monster_x=2196;monster[2].monster_left=2196;monster[2].monster_y=HEIGHT-GROUND_WIDTH-43-30;
    monster[3].monster_x=3558;monster[3].monster_left=3558;monster[3].monster_y=445;
    monster[4].monster_x=4411;monster[4].monster_left=4411;monster[4].monster_y=HEIGHT-GROUND_WIDTH-43-30;
    monster[5].monster_x=6195;monster[5].monster_left=6195;monster[5].monster_y=HEIGHT-GROUND_WIDTH-43-30;
    monster[6].monster_x=6435;monster[6].monster_left=6435;monster[6].monster_y=HEIGHT-GROUND_WIDTH-43-30;

    //双人模式下方橙色小怪
    if(gamemode == 0)
    {
        monster[7].monster_x=1660;monster[7].monster_left=1660;monster[7].monster_y=450+BIAS;
        monster[8].monster_x=2041;monster[8].monster_left=2041;monster[8].monster_y=HEIGHT-GROUND_WIDTH-43+BIAS-19;
        monster[9].monster_x=2196;monster[9].monster_left=2196;monster[9].monster_y=HEIGHT-GROUND_WIDTH-43+BIAS-19;
        monster[10].monster_x=3558;monster[10].monster_left=3558;monster[10].monster_y=445+BIAS;
        monster[11].monster_x=4411;monster[11].monster_left=4411;monster[11].monster_y=HEIGHT-GROUND_WIDTH-43+BIAS-19;
        monster[12].monster_x=6195;monster[12].monster_left=6195;monster[12].monster_y=HEIGHT-GROUND_WIDTH-43+BIAS-19;
        monster[13].monster_x=6435;monster[13].monster_left=6435;monster[13].monster_y=HEIGHT-GROUND_WIDTH-43+BIAS-19;
    }
}


void MainWindow::set_turtle()
{
    //单人模式和双人模式上方乌龟
    turtle[0].turtle_x=1135;turtle[0].turtle_left=1135;
    turtle[1].turtle_x=3290;turtle[1].turtle_left=3290;
    turtle[2].turtle_x=3890;turtle[2].turtle_left=3890;

    //双人模式下方乌龟
    if(gamemode == 0)
    {
        turtle[3].turtle_x=1135;turtle[3].turtle_left=1135;
        turtle[4].turtle_x=3290;turtle[4].turtle_left=3290;
        turtle[5].turtle_x=3890;turtle[5].turtle_left=3890;
        turtle[3].turtle_y=turtle[0].turtle_y+BIAS+9;
        turtle[4].turtle_y=turtle[0].turtle_y+BIAS+9;
        turtle[5].turtle_y=turtle[0].turtle_y+BIAS+9;
    }
}

void MainWindow::set_whitemonster()
{
    //设置白色鬼魂
    whitemonster[0].whitemonster_x1=whitemonster[1].whitemonster_x1=7152.5;
    whitemonster[0].whitemonster_x2=whitemonster[1].whitemonster_x2=7252.5;
    whitemonster[0].whitemonster_y1=whitemonster[0].whitemonster_y2=617;
    whitemonster[1].whitemonster_y1=whitemonster[1].whitemonster_y2=617+BIAS;
    whitemonster[0].whitemonster1_up_max=567;
    whitemonster[1].whitemonster1_up_max=567+BIAS;
    whitemonster[0].whitemonster2_up_max=467;
    whitemonster[1].whitemonster2_up_max=467+BIAS;
    whitemonster[0].whitemonster_down_max=617;
    whitemonster[1].whitemonster_down_max=617+BIAS;

    for(int i=0;i<2;i++)
    {
        whitemonster[i].whitemonster1_rec.moveTo(whitemonster[i].whitemonster_x1,whitemonster[i].whitemonster_y1);
        whitemonster[i].whitemonster2_rec.moveTo(whitemonster[i].whitemonster_x2,whitemonster[i].whitemonster_y2);
    }
}

void MainWindow::build_wall()//修建所有砖头
{
    if(gamemode == 1)//单人模式砖头
    {
        wall[0].wall_x=515;wall[1].wall_x=615;wall[2].wall_x=715;
        wall[0].wall_y=wall[1].wall_y=wall[2].wall_y=490;

        wall[3].wall_x=890;
        wall[3].wall_y=345;

        wall[4].wall_x=1040;wall[5].wall_x=1090;
        wall[4].wall_y=wall[5].wall_y=260;

        wall[6].wall_x=1500;wall[7].wall_x=1550;
        wall[6].wall_y=wall[7].wall_y=260;

        wall[8].wall_x=1635;wall[9].wall_x=1685;wall[10].wall_x=1735;
        wall[8].wall_y=wall[9].wall_y=wall[10].wall_y=490;

        wall[11].wall_x=2070;
        wall[11].wall_y=430;

        wall[12].wall_x=2270;wall[13].wall_x=2370;
        wall[12].wall_y=wall[13].wall_y=490;

        wall[14].wall_x=3560;wall[15].wall_x=3610;
        wall[14].wall_y=wall[15].wall_y=490;

        wall[16].wall_x=4245;
        wall[16].wall_y=490;

        wall[17].wall_x=4455;
        wall[17].wall_y=375;


        wall[18].wall_x=5000;wall[19].wall_x=4850;
        wall[18].wall_y=wall[19].wall_y=490;

        wall[20].wall_x=6570;wall[21].wall_x=6620;
        wall[20].wall_y=wall[21].wall_y=375;

        wall[22].wall_x=wall[23].wall_x=wall[24].wall_x=6800;
        wall[22].wall_y=617+18;
        wall[23].wall_y=567+18;
        wall[24].wall_y=517+18;
        wall[25].wall_x=6850;wall[26].wall_x=6900;
        wall[25].wall_y=wall[26].wall_y=517+18;

        wall[27].wall_x=wall[28].wall_x=7100;
        wall[29].wall_x=wall[30].wall_x=wall[31].wall_x=wall[32].wall_x=7200;
        wall[33].wall_x=wall[34].wall_x=wall[35].wall_x=wall[36].wall_x=wall[37].wall_x=wall[38].wall_x=7300;
        wall[27].wall_y=wall[29].wall_y=wall[33].wall_y=617+19;
        wall[28].wall_y=wall[30].wall_y=wall[34].wall_y=567+19;
        wall[31].wall_y=wall[35].wall_y=517+19;
        wall[32].wall_y=wall[36].wall_y=467+19;
        wall[37].wall_y=417+19;
        wall[38].wall_y=367+19;

        wall[39].wall_x=7450;
        wall[40].wall_x=7500;
        wall[41].wall_x=7550;
        wall[39].wall_y=wall[40].wall_y=wall[41].wall_y=517;

        wall[42].wall_x=7700;wall[42].wall_y=200;//
        wall[43].wall_x=7750;wall[43].wall_y=200;
        wall[44].wall_x=7800;wall[44].wall_y=200;
        wall[45].wall_x=7850;wall[45].wall_y=200;

        wall[46].wall_x=7700;wall[46].wall_y=350;
        wall[47].wall_x=7750;wall[47].wall_y=350;
        wall[48].wall_x=7800;wall[48].wall_y=350;
        wall[49].wall_x=7850;wall[49].wall_y=350;
        wall[50].wall_x=7900;wall[50].wall_y=350;
        wall[51].wall_x=7950;wall[51].wall_y=350;

        wall[52].wall_x=wall[53].wall_x=wall[54].wall_x=8000;
        wall[52].wall_y=300;
        wall[53].wall_y=250;
        wall[54].wall_y=200;
        wall[55].wall_x=7950;
        wall[55].wall_y=wall[56].wall_y=350;
        wall[56].wall_x=8000;

        wall[57].wall_x=8150;//
        wall[58].wall_x=8200;
        wall[59].wall_x=8250;
        wall[57].wall_y=wall[58].wall_y=wall[59].wall_y=570;

        wall[60].wall_x=8400;
        wall[61].wall_x=8450;
        wall[62].wall_x=8500;
        wall[60].wall_y=wall[61].wall_y=wall[62].wall_y=390;

        wall[63].wall_x=8650;wall[64].wall_x=8700;
        wall[65].wall_x=8750;wall[66].wall_x=8800;
        wall[67].wall_x=8850;wall[68].wall_x=8900;
        wall[69].wall_x=8950;wall[70].wall_x=9000;
        wall[71].wall_x=9050;wall[72].wall_x=9100;

        wall[73].wall_x=9300;wall[74].wall_x=9350;
        wall[75].wall_x=9400;wall[76].wall_x=9450;
        wall[77].wall_x=9500;wall[78].wall_x=9550;
        wall[79].wall_x=9600;wall[80].wall_x=9650;
        wall[81].wall_x=9700;wall[82].wall_x=9750;

        wall[63].wall_y=wall[64].wall_y=wall[65].wall_y=wall[66].wall_y=230;
        wall[67].wall_y=wall[68].wall_y=wall[69].wall_y=wall[70].wall_y=230;
        wall[71].wall_y=wall[72].wall_y=230;
        wall[73].wall_y=wall[74].wall_y=wall[75].wall_y=wall[76].wall_y=230;
        wall[77].wall_y=wall[78].wall_y=wall[79].wall_y=wall[80].wall_y=230;
        wall[81].wall_y=wall[82].wall_y=230;

        wall[83].wall_x=10200;wall[83].wall_y=270;
        wall[84].wall_x=10250;wall[84].wall_y=270;
        wall[85].wall_x=10300;wall[85].wall_y=270;
        wall[86].wall_x=10350;wall[86].wall_y=270;
        wall[87].wall_x=10400;wall[87].wall_y=270;
        wall[88].wall_x=10450;wall[88].wall_y=270;

        wall[89].wall_x=10650;wall[89].wall_y=500;
        wall[90].wall_x=10700;wall[90].wall_y=500;
        wall[91].wall_x=10750;wall[91].wall_y=500;

        wall[92].wall_x=5549;
        wall[92].wall_y=wall[93].wall_y=wall[94].wall_y=wall[95].wall_y=534;
        wall[93].wall_x=5499;
        wall[94].wall_x=6355;
        wall[95].wall_x=6405;

        wall[96].wall_x=3850;wall[96].wall_y=450;
        wall[97].wall_x=3900;wall[97].wall_y=450;

        wall[98].wall_x=5335;wall[98].wall_y=434;
        wall[99].wall_x=5285;wall[99].wall_y=434;
        wall[100].wall_x=5235;wall[100].wall_y=434;
        wall[101].wall_x=5185;wall[101].wall_y=434;
        wall[102].wall_x=5135;wall[102].wall_y=434;



        for(int i=0;i<103;i++)
        {
            wall[i].wall_rec.moveTo(wall[i].wall_x,wall[i].wall_y);
        }
    }

    else//双人模式
    {

        wall[0].wall_x=515;wall[1].wall_x=615;wall[2].wall_x=715;
        wall[0].wall_y=wall[1].wall_y=wall[2].wall_y=490;

        wall[3].wall_x=890;
        wall[3].wall_y=345;

        wall[4].wall_x=1040;wall[5].wall_x=1090;
        wall[4].wall_y=wall[5].wall_y=260;

        wall[6].wall_x=1500;wall[7].wall_x=1550;
        wall[6].wall_y=wall[7].wall_y=260;

        wall[8].wall_x=1635;wall[9].wall_x=1685;wall[10].wall_x=1735;
        wall[8].wall_y=wall[9].wall_y=wall[10].wall_y=490;

        wall[11].wall_x=2070;
        wall[11].wall_y=430;

        wall[12].wall_x=2270;wall[13].wall_x=2370;
        wall[12].wall_y=wall[13].wall_y=490;

        wall[14].wall_x=3560;wall[15].wall_x=3610;
        wall[14].wall_y=wall[15].wall_y=490;

        wall[16].wall_x=4245;
        wall[16].wall_y=490;

        wall[17].wall_x=4455;
        wall[17].wall_y=375;


        wall[18].wall_x=5000;wall[19].wall_x=4850;
        wall[18].wall_y=wall[19].wall_y=490;

        wall[20].wall_x=6570;wall[21].wall_x=6620;
        wall[20].wall_y=wall[21].wall_y=375;



   //下面有金币的l形平台
        wall[22].wall_x=wall[23].wall_x=wall[24].wall_x=6800;
        wall[22].wall_y=617+18;
        wall[23].wall_y=567+18;
        wall[24].wall_y=517+18;
        wall[25].wall_x=6850;wall[26].wall_x=6900;
        wall[25].wall_y=wall[26].wall_y=517+18;
//下面是白色鬼怪的柱子
        wall[27].wall_x=wall[28].wall_x=7100;
        wall[29].wall_x=wall[30].wall_x=wall[31].wall_x=wall[32].wall_x=7200;
        wall[33].wall_x=wall[34].wall_x=wall[35].wall_x=wall[36].wall_x=wall[37].wall_x=wall[38].wall_x=7300;
        wall[27].wall_y=wall[29].wall_y=wall[33].wall_y=617+19;
        wall[28].wall_y=wall[30].wall_y=wall[34].wall_y=567+19;
        wall[31].wall_y=wall[35].wall_y=517+19;
        wall[32].wall_y=wall[36].wall_y=467+19;
        wall[37].wall_y=417+19;
        wall[38].wall_y=367+19;

        //建造3个动态砖块
        wall[39].wall_x=7450;
        wall[40].wall_x=7500;
        wall[41].wall_x=7550;
        wall[39].wall_y=wall[40].wall_y=wall[41].wall_y=517;

        wall[46].wall_x=7700;wall[46].wall_y=350;
        wall[47].wall_x=7750;wall[47].wall_y=350;
        wall[48].wall_x=7800;wall[48].wall_y=350;
        wall[49].wall_x=7850;wall[49].wall_y=350;
        wall[50].wall_x=7900;wall[50].wall_y=350;
        wall[51].wall_x=7950;wall[51].wall_y=350;

        wall[52].wall_x=wall[53].wall_x=wall[54].wall_x=8000;
        wall[52].wall_y=300;
        wall[53].wall_y=250;
        wall[54].wall_y=200;
        wall[55].wall_x=7950;
        wall[55].wall_y=wall[56].wall_y=350;
        wall[56].wall_x=8000;

        wall[57].wall_x=8150;
        wall[58].wall_x=8200;
        wall[59].wall_x=8250;
        wall[57].wall_y=wall[58].wall_y=wall[59].wall_y=570;

        wall[60].wall_x=8400;
        wall[61].wall_x=8450;
        wall[62].wall_x=8500;
        wall[60].wall_y=wall[61].wall_y=wall[62].wall_y=390;

        wall[63].wall_x=8650;wall[64].wall_x=8700;
        wall[65].wall_x=8750;wall[66].wall_x=8800;
        wall[67].wall_x=8850;wall[68].wall_x=8900;
        wall[69].wall_x=8950;wall[70].wall_x=9000;
        wall[71].wall_x=9050;wall[72].wall_x=9100;

        wall[73].wall_x=9300;wall[74].wall_x=9350;
        wall[75].wall_x=9400;wall[76].wall_x=9450;
        wall[77].wall_x=9500;wall[78].wall_x=9550;
        wall[79].wall_x=9600;wall[80].wall_x=9650;
        wall[81].wall_x=9700;wall[82].wall_x=9750;

        wall[63].wall_y=wall[64].wall_y=wall[65].wall_y=wall[66].wall_y=230;
        wall[67].wall_y=wall[68].wall_y=wall[69].wall_y=wall[70].wall_y=230;
        wall[71].wall_y=wall[72].wall_y=230;

        wall[73].wall_y=wall[74].wall_y=wall[75].wall_y=wall[76].wall_y=230;
        wall[77].wall_y=wall[78].wall_y=wall[79].wall_y=wall[80].wall_y=230;
        wall[81].wall_y=wall[82].wall_y=230;

        wall[83].wall_x=10200;wall[83].wall_y=270;
        wall[84].wall_x=10250;wall[84].wall_y=270;
        wall[85].wall_x=10300;wall[85].wall_y=270;
        wall[86].wall_x=10350;wall[86].wall_y=270;
        wall[87].wall_x=10400;wall[87].wall_y=270;
        wall[88].wall_x=10450;wall[88].wall_y=270;

        wall[89].wall_x=10650;wall[89].wall_y=500;
        wall[90].wall_x=10700;wall[90].wall_y=500;
        wall[91].wall_x=10750;wall[91].wall_y=500;

        wall[92].wall_x=5549;
        wall[92].wall_y=wall[93].wall_y=wall[94].wall_y=wall[95].wall_y=534;
        wall[93].wall_x=5499;
        wall[94].wall_x=6355;
        wall[95].wall_x=6405;

        wall[96].wall_x=3850;wall[96].wall_y=450;
        wall[97].wall_x=3900;wall[97].wall_y=450;

        wall[98].wall_x=5335;wall[98].wall_y=434;
        wall[99].wall_x=5285;wall[99].wall_y=434;
        wall[100].wall_x=5235;wall[100].wall_y=434;
        wall[101].wall_x=5185;wall[101].wall_y=434;
        wall[102].wall_x=5135;wall[102].wall_y=434;

        for(int i=103;i<206;i++)
        {
            if((i-103)>=22&&(i-103)<=38)
            {
                wall[i].wall_x= wall[i - 103].wall_x;
                wall[i].wall_y = wall[i - 103].wall_y+BIAS+11;
            }
            else
            {
                wall[i].wall_x=wall[i -103].wall_x;
                wall[i].wall_y = wall[i - 103].wall_y+BIAS;
            }
        }

        for(int i=0;i<206;i++)
        {
            wall[i].wall_rec.moveTo(wall[i].wall_x,wall[i].wall_y);
        }
    }

    //修建问题砖头
    question_wall[0].question_x=565;question_wall[1].question_x=665;
    question_wall[0].question_y=question_wall[1].question_y=490;

    question_wall[2].question_x=365;
    question_wall[2].question_y=435;

    question_wall[3].question_x=2120;
    question_wall[3].question_y=430;

    question_wall[4].question_x=2320;
    question_wall[4].question_y=490;

    question_wall[5].question_x=4295;
    question_wall[5].question_y=490;

    question_wall[6].question_x=5050;
    question_wall[6].question_y=5050;
    //单人模式和双人模式下方的问题砖块

    for(int i=0;i<7;i++)
    {
        question_wall[i].question_rec.moveTo(question_wall[i].question_x,question_wall[i].question_y);
    }

    if(gamemode == 0)//双人模式下方的问题砖块
    {
        question_wall[7].question_x=565;question_wall[8].question_x=665;
        question_wall[7].question_y=question_wall[8].question_y=490+BIAS;

        question_wall[9].question_x=365;
        question_wall[9].question_y=435+BIAS;

        question_wall[10].question_x=2120;
        question_wall[10].question_y=430+BIAS;

        question_wall[11].question_x=2320;
        question_wall[11].question_y=490+BIAS;

        question_wall[12].question_x=4295;
        question_wall[12].question_y=490+BIAS;

        question_wall[13].question_x=5050;
        question_wall[13].question_y=5050+BIAS;

        for(int i=0;i<14;i++)
        {
            question_wall[i].question_rec.moveTo(question_wall[i].question_x,question_wall[i].question_y);
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if(gamemode == 1)//单人模式
    {
        QPainter painter(this);

           // Load the second background image
        QPixmap backgroundImage2("://picture/Scene.png");

           // Draw the second background image with transparency
        painter.drawPixmap(0, 0, backgroundImage2);

        QPixmap guideboard;//单人模式指示牌
           guideboard.load(GUIDEBORAD);
           painter.drawPixmap(300+bias,HEIGHT-GROUND_WIDTH-90,guideboard);

        QPixmap clock;//单人模式计时器
           clock.load(TIMER_PICTURE);
           clock = clock.scaled(50,50);
        painter.drawPixmap(time.timer_x,time.timer_y,clock);
        painter.setFont(time.font);//单人模式设置字体和颜色
        painter.setPen(Qt::white);
        painter.drawText(time.timer_x+70,time.timer_y+40, QString::number(time.timetoover));//此处坐标就不用加偏移量，因为这不随猫移动变化
        time.counter++;//单人模式实现数字变化
        if(time.counter== 16 &&time.counter>=0)
        {
            time.timetoover --;
            time.counter=0;
        }

         if(time.timetoover == 0)
            gameover_time();

    //单人模式金币计数器
    painter.drawPixmap(time.timer_x-300,time.timer_y-2,coincounter[0].coincounterpic);
    painter.drawText(time.timer_x-230,time.timer_y+40, "X "+QString::number(coincounter[0].toatalcoin));

    //单人模式分数计数器
    painter.drawText(time.timer_x-900,time.timer_y+40, "Score= "+QString::number(totalscore1));

    //单人模式生命显示
    painter.drawPixmap(50,time.timer_y-2,heath[0].m_life);
    painter.drawText(110,time.timer_y+40, "X "+QString::number(cat[0].cat_life));

    //"/////////////////////////////////////////////////////////////////////////////////////////////////"
    //单人模式绘制动态金币
    for(int i=0;i<165;i++)
    {
        if(gold[i].gold_life==false)
        {
            painter.drawPixmap(gold[i].gold_x+bias,gold[i].gold_y,gold[i].gold_pix,30*gold[i].pix_index++,0,30,33);
            if(gold[i].pix_index==8)
                gold[i].pix_index=0;
            gold[i].gold_rec.moveTo(gold[i].gold_x,gold[i].gold_y);
        }
    }

    //for(int i=0;i<2;i++)//单人模式绘制管道
    //    painter.drawPixmap(tube[i].tube_x+bias,tube[i].tube_y,tube[i].tube_pix);

    //单人模式绘制食人花
    //painter.drawPixmap(flower[0].flower_x[0]+bias,flower[0].flower_y,flower[0].flower_pix);
    //painter.drawPixmap(flower[0].flower_x[1]+bias,flower[0].flower_y,flower[0].flower_pix);

    for(int i=0;i<200;i++)
         //单人模式绘制草地
         painter.drawPixmap(ground[i].ground_x+bias,ground[i].ground_y,ground[i].ground_pix);

         //单人模式绘制洞穴
         for(int i=0;i<8;i++)
         {
              painter.drawPixmap(hole[i].hole_x+bias,hole[i].hole_y,hole[i].hole_pix);
         }
         painter.drawPixmap(fire_hole[0].fire_hole_x+bias,fire_hole[0].fire_hole_y,fire_hole[0].fire_hole_pix);
         painter.drawPixmap(fire_hole[1].fire_hole_x+bias,fire_hole[1].fire_hole_y,fire_hole[1].fire_hole_pix);

         //单人模式绘制城堡和旗帜

         painter.drawPixmap(flagandcastle[0].castle_x+bias,flagandcastle[0].castle_y,flagandcastle[0].castle_pic);

        //死亡时只需添加一句cat_dead=1；
        if(cat_dead == 0)
            painter.drawPixmap(cat[0].fakecat_x,cat[0].cat_y,cat[0].cat_pix);//绘制猫
        else
        {
            //单人模式猫死亡动画
            painter.drawPixmap(cat[0].fakecat_x,cat[0].cat_y,cat[0].cat_dead_pic,50*cat[0].cat_Dead_index++,0,50,84);
            if(cat[0].cat_Dead_index == 25)
            {
                cat[0].cat_Dead_index = 0;
                cat[0].cat_Dead();//回移函数
                cat[0].cat_life--;//生命-1
                cat_dead =false;//重置状态
            }
        }

    //painter.drawPixmap(600,ground.ground_y,ground.ground_pix);
    //单人模式绘制乌龟
    for(int i=0;i<3;i++)
    {
        painter.drawPixmap(turtle[i].turtle_x+bias,turtle[i].turtle_y,turtle[i].turtle_pix);
    }

    //单人模式绘制小怪
    for(int i=0;i<7;i++)
    {
       if(monster[i].monster_life==true)
        {
            painter.drawPixmap(monster[i].monster_x+bias,monster[i].monster_y,monster[i].monster_pix);
        }

       if(monster[i].monster_life==false&&monster[i].bian_time<10&&monster[i].monster_kill_cai==true)
        {
            //单人模式在小怪死亡后绘制小怪被踩扁的图片
            painter.drawPixmap(monster[i].monster_x+bias,monster[i].monster_y,monster[i].monster_pix);//绘制小怪
            monster[i].bian_time++;
        }
    }

    //单人模式绘制动态地面
    for(int i=0;i<4;i++)
    {
        painter.drawPixmap(moveground[i].moveground_x+bias,moveground[i].moveground_y,moveground[i].moveground_pix);
    }

    //单人模式绘制火箭
    if(rocket[0].rocket_life==true&&rocket[0].rocket_crash_life==false)
    {
         painter.drawPixmap(rocket[0].rocket_x+bias,rocket[0].rocket_y,rocket[0].rocket_pix);
    }
    if(rocket[0].rocket_life==true&&rocket[0].rocket_crash_life==true)
    {
        painter.drawPixmap(rocket[0].rocket_crash_zs_x=rocket[0].rocket_x-30+bias,rocket[0].rocket_crash_zs_y=rocket[0].rocket_y+15,rocket[0].rocket_crash_zs_pix);
        painter.drawPixmap(rocket[0].rocket_crash_zx_x=rocket[0].rocket_x-30+bias,rocket[0].rocket_crash_zx_y=rocket[0].rocket_y+15+10,rocket[0].rocket_crash_zx_pix);
        painter.drawPixmap(rocket[0].rocket_crash_ys_x=rocket[0].rocket_x+30+10+bias,rocket[0].rocket_crash_ys_y=rocket[0].rocket_y+15,rocket[0].rocket_crash_ys_pix);
        painter.drawPixmap(rocket[0].rocket_crash_yx_x=rocket[0].rocket_x+30+10+bias,rocket[0].rocket_crash_yx_y=rocket[0].rocket_y+15+10,rocket[0].rocket_crash_yx_pix);
    }


    //单人模式绘制蘑菇
    if(mushroom[0].istaste==false)
    {
        painter.drawPixmap(mushroom[0].mushroom_x+bias,mushroom[0].mushroom_y,mushroom[0].mushroom_pix);
    }

    //单人模式绘制问题砖块，这里切图不是写在封装的类里面用定时器切换，因为16张图片是一张长图
    for(int i=0;i<7;i++)
    {
        if(question_wall[i].question_state==true)
        {
            //单人模式问题砖块的背后切图，并且这里是长图
            painter.drawPixmap(question_wall[i].question_x+bias,question_wall[i].question_y,question_wall[i].question_pix,50*question_wall[i].pix_biao++,0,50,50);
            if(question_wall[i].pix_biao==16)
                question_wall[i].pix_biao=0;
        }

        if(question_wall[i].question_state==false)
        {
            //单人模式问题砖块被顶后切图
            question_wall[i].question_pix.load(QUESTION_HPICTURE);
            painter.drawPixmap(question_wall[i].question_x+bias,question_wall[i].question_y,question_wall[i].question_pix);
        }
    }

    //单人模式绘制砖头
    for(int i=0;i<103;i++)
    {
        if(wall[i].wall_state==true)
            painter.drawPixmap(wall[i].wall_x+bias,wall[i].wall_y,wall[i].wall_pix);

        if(wall[i].wall_state==false&&wall[i].wall_life==true)
        {
            //单人模式绘制砖头的破裂
            painter.drawPixmap(wall[i].wall_x-75+bias,wall[i].wall_y-75,wall[i].zs_pix);
            painter.drawPixmap(wall[i].wall_x-75+bias,wall[i].wall_y+75,wall[i].zx_pix);
            painter.drawPixmap(wall[i].wall_x+75+bias,wall[i].wall_y-75,wall[i].ys_pix);
            painter.drawPixmap(wall[i].wall_x+75+bias,wall[i].wall_y+75,wall[i].yx_pix);
            wall[i].wall_life=false;//单人模式砖头死了，破裂效果只显示一次
        }
    }

    //单人模式绘制白色鬼怪
    for(int i=0;i<1;i++)
    {
        painter.drawPixmap(whitemonster[i].whitemonster_x1+bias,whitemonster[i].whitemonster_y1,whitemonster[i].whitemonster1_pix);
        painter.drawPixmap(whitemonster[i].whitemonster_x2+bias,whitemonster[i].whitemonster_y2,whitemonster[i].whitemonster2_pix);
    }

    //单人模式绘制子弹
    for(int i=0;i<5;i++)
    {
        if(bullet0[i].bullet_free==false)//只有发射了才更新位置
        {

            painter.drawPixmap(bullet0[i].bullet_x+bias,bullet0[i].bullet_y,bullet0[i].bullet_pix);
        }
    }
    //每当猫移动到中心屏幕并且想右移时，地图开始左移
    //###############################bias的修改地方
    if(cat[0].cat_x>=700)
    {
        cat[0].fakecat_x=700;
        bias=-(cat[0].cat_x-700);
    }
}
    //"双人模式“////////////////////////////////////////////////////////////////////////////////////////////////////////
    else//双人模式
    {
        QPainter painter(this);

               // Load the second background image
        QPixmap backgroundImage2("://picture/Scene.png");

               // Draw the second background image with transparency
               painter.drawPixmap(0, 0, backgroundImage2);
               painter.drawPixmap(0, 0+BIAS+10, backgroundImage2);


        QPixmap guideboard;//双人模式指示牌
               guideboard.load(GUIDEBORAD);
               painter.drawPixmap(300+bias,HEIGHT-GROUND_WIDTH-90,guideboard);
               painter.drawPixmap(300+bias1,HEIGHT-GROUND_WIDTH-90+BIAS+10,guideboard);

        QPixmap clock;//双人模式计时器
               clock.load(TIMER_PICTURE);
               clock = clock.scaled(50,50);
        painter.drawPixmap(time.timer_x,time.timer_y,clock);
        painter.setFont(time.font);//双人模式设置字体和颜色
        painter.setPen(Qt::white);
        painter.drawText(time.timer_x+70,time.timer_y+40, QString::number(time.timetoover));
        time.counter++;//双人模式实现数字变化
        qDebug()<<time.counter;
            if(time.counter>=3)
            {
                time.timetoover+=0.1;
                time.counter=0;
            }


        painter.drawPixmap(time.timer_x,time.timer_y+BIAS+35,clock);
        painter.setFont(time.font);//双人模式设置字体和颜色
        painter.setPen(Qt::white);
        painter.drawText(time.timer_x+70,time.timer_y+40+BIAS+35, QString::number(time.timetoover));
        time.counter++;//双人模式实现数字变化
            if(time.counter>=3)
            {
                time.timetoover+=0.1;
                time.counter=0;
            }



        //双人模式金币计数器上方
        painter.drawPixmap(time.timer_x-270,time.timer_y-2,coincounter[0].coincounterpic);
        painter.drawText(time.timer_x-200,time.timer_y+40, "X "+QString::number(coincounter[0].toatalcoin));

        //双人模式金币计数器下方
        painter.drawPixmap(time.timer_x-270,time.timer_y-2+BIAS+35,coincounter[1].coincounterpic);
        painter.drawText(time.timer_x-200,time.timer_y+40+BIAS+35, "X "+QString::number(coincounter[1].toatalcoin));

        //双人模式得分计数器上方
        painter.drawText(time.timer_x-600,time.timer_y+40, "Score= "+QString::number(totalscore1));
        //双人模式得分计数器下方
        painter.drawText(time.timer_x-600,time.timer_y+40+BIAS+35, "Score= "+QString::number(totalscore2));

        //双人模式生命显示上方
        painter.setPen(Qt::black);
        painter.drawText(50,time.timer_y+40, "Player1 ");
        painter.setPen(Qt::white);
        painter.drawPixmap(250,time.timer_y-2,heath[0].m_life);
        if(cat[0].cat_life>=2)
        {
            painter.setPen(Qt::white);
            painter.drawText(310,time.timer_y+40, "X "+QString::number(cat[0].cat_life));
        }
        if(cat[0].cat_life==1)
        {
            painter.setPen(Qt::red);
            painter.drawText(310,time.timer_y+40, "X "+QString::number(cat[0].cat_life));
        }
        if(cat[0].cat_life<1)
        {
            painter.setPen(Qt::red);
            painter.drawText(310,time.timer_y+40, "is dead !");
            gameover_time();
        }

        //双人模式生命显示下方
        painter.setPen(Qt::black);
        painter.drawText(50,time.timer_y+40+BIAS+35, "Player2 ");
        painter.setPen(Qt::white);
        painter.drawPixmap(250,time.timer_y-2+BIAS+35,heath[1].m_life);
        if(cat[1].cat_life>=2)
        {
             painter.setPen(Qt::white);
             painter.drawText(310,time.timer_y+40+BIAS+35, "X "+QString::number(cat[1].cat_life));
        }
        if(cat[1].cat_life==1)
        {
            painter.setPen(Qt::red);
            painter.drawText(310,time.timer_y+40+BIAS+35, "X "+QString::number(cat[1].cat_life));
        }
        if(cat[1].cat_life<1)
        {
            painter.setPen(Qt::red);
            painter.drawText(310,time.timer_y+40+BIAS+35, "is dead !");
            gameover_time();
        }
        //"/////////////////////////////////////////////////////////////////////////////////////////////////"
        //双人模式绘制上下方的动态金币
        for(int i=0;i<165;i++)
        {
            if(gold[i].gold_life==false)
            {
                painter.drawPixmap(gold[i].gold_x+bias,gold[i].gold_y,gold[i].gold_pix,30*gold[i].pix_index++,0,30,33);
                if(gold[i].pix_index==8)
                    gold[i].pix_index=0;
                gold[i].gold_rec.moveTo(gold[i].gold_x,gold[i].gold_y);
            }
        }

        for(int i=165;i<330;i++)
        {
            if(gold[i].gold_life==false)
            {
                painter.drawPixmap(gold[i].gold_x+bias1,gold[i].gold_y,gold[i].gold_pix,30*gold[i].pix_index++,0,30,33);
                if(gold[i].pix_index==8)
                    gold[i].pix_index=0;
                gold[i].gold_rec.moveTo(gold[i].gold_x,gold[i].gold_y);
            }
        }

        //双人模式绘制草地
        for(int i=0;i<200;i++)
        {
            painter.drawPixmap(ground[i].ground_x+bias,ground[i].ground_y,ground[i].ground_pix);
            painter.drawPixmap(ground[i].ground_x+bias1,ground[i].ground_y+BIAS+12,ground[i].ground_pix);
        }

            //双人模式绘制上方洞穴
        for(int i=0;i<8;i++)
        {
             painter.drawPixmap(hole[i].hole_x+bias,hole[i].hole_y,hole[i].hole_pix);
        }
        painter.drawPixmap(fire_hole[0].fire_hole_x+bias,fire_hole[0].fire_hole_y,fire_hole[0].fire_hole_pix);
        painter.drawPixmap(fire_hole[1].fire_hole_x+bias,fire_hole[1].fire_hole_y,fire_hole[1].fire_hole_pix);
            //双人模式绘制下方洞穴
        for(int i=8;i<16;i++)
        {
             painter.drawPixmap(hole[i].hole_x+bias1,hole[i].hole_y,hole[i].hole_pix);
        }
        painter.drawPixmap(fire_hole[2].fire_hole_x+bias1,fire_hole[2].fire_hole_y,fire_hole[2].fire_hole_pix);
        painter.drawPixmap(fire_hole[3].fire_hole_x+bias1,fire_hole[3].fire_hole_y,fire_hole[3].fire_hole_pix);



            //双人模式绘制上方中终点城堡和旗帜

            painter.drawPixmap(flagandcastle[0].castle_x+bias,flagandcastle[0].castle_y,flagandcastle[0].castle_pic);


            //双人模式绘制下方中终点城堡和旗帜

            painter.drawPixmap(flagandcastle[1].castle_x+bias1,flagandcastle[1].castle_y,flagandcastle[1].castle_pic);


            music++;
            if(music == 1340)
            {
                emit soundeffect("theme");
                music = 0;
            }

            //死亡时只需添加一句cat_dead=1；
            if(cat_dead_2 == 0)
                //双人模式下方猫
                painter.drawPixmap(cat[1].fakecat_x,cat[1].cat_y,cat[1].cat_pix);//双人模式绘制下方猫
            else
            {
                //双人模式下方猫死亡动画
                painter.drawPixmap(cat[1].fakecat_x,cat[1].cat_y,cat[1].cat_dead_pic,100*cat[1].cat_Dead_index++,0,100,84);
                if(cat[1].cat_Dead_index == 25)
                {
                    cat[1].cat_Dead_index = 0;
                    cat[1].cat_Dead();//回移函数
                    cat[1].cat_life--;//生命-1
                    cat_dead_2 =false;//重置状态
                }
            }

            if(cat_dead == 0)//双人模式上方猫
                painter.drawPixmap(cat[0].fakecat_x,cat[0].cat_y,cat[0].cat_pix);//绘制猫

            else
            {
                //双人模式上方猫死亡动画
                painter.drawPixmap(cat[0].fakecat_x,cat[0].cat_y,cat[0].cat_dead_pic,100*cat[0].cat_Dead_index++,0,100,84);
                if(cat[0].cat_Dead_index == 25)
                {
                     cat[0].cat_Dead_index = 0;
                     cat[0].cat_Dead();//回移函数
                     cat[0].cat_life--;//生命-1
                     cat_dead =false;//重置状态
                }
            }
        //painter.drawPixmap(600,ground.ground_y,ground.ground_pix);
        //双人模式绘制上下方的乌龟
        for(int i=0;i<3;i++)
        {
            painter.drawPixmap(turtle[i].turtle_x+bias,turtle[i].turtle_y,turtle[i].turtle_pix);
        }

        for(int i=3;i<6;i++)
        {
            painter.drawPixmap(turtle[i].turtle_x+bias1,turtle[i].turtle_y,turtle[i].turtle_pix);
        }

        //双人模式绘制上下方的橙色小怪
        for(int i=0;i<7;i++)
        {
            //当橙色小怪活着时
            if(monster[i].monster_life==true)
            {
                painter.drawPixmap(monster[i].monster_x+bias,monster[i].monster_y,monster[i].monster_pix);
            }

            //当橙色小怪死亡时
            if(monster[i].monster_life==false&&monster[i].bian_time<10&&monster[i].monster_kill_cai==true)
            {
                //在小怪死亡后绘制小怪被踩扁的图片
                painter.drawPixmap(monster[i].monster_x+bias,monster[i].monster_y,monster[i].monster_pix);//绘制小怪
                monster[i].bian_time++;
            }
        }

        for(int i=7;i<14;i++)
        {
            //当橙色小怪活着时
            if(monster[i].monster_life==true)
            {
                painter.drawPixmap(monster[i].monster_x+bias1,monster[i].monster_y,monster[i].monster_pix);
            }

            //当橙色小怪死亡时
            if(monster[i].monster_life==false&&monster[i].bian_time<10&&monster[i].monster_kill_cai==true)
            {
                //在小怪死亡后绘制小怪被踩扁的图片
                painter.drawPixmap(monster[i].monster_x+bias1,monster[i].monster_y,monster[i].monster_pix);//绘制小怪
                monster[i].bian_time++;
            }
        }

        //双人模式绘制动态地面
        for(int i=0;i<4;i++)
        {
            painter.drawPixmap(moveground[i].moveground_x+bias,moveground[i].moveground_y,moveground[i].moveground_pix);
        }

        for(int i=4;i<8;i++)
        {
            painter.drawPixmap(moveground[i].moveground_x+bias1,moveground[i].moveground_y,moveground[i].moveground_pix);
        }

        //双人模式绘制火箭
        if(rocket[0].rocket_life==true&&rocket[0].rocket_crash_life==false)
         {
              painter.drawPixmap(rocket[0].rocket_x+bias,rocket[0].rocket_y,rocket[0].rocket_pix);
         }

         if(rocket[0].rocket_life==true&&rocket[0].rocket_crash_life==true)
         {
             painter.drawPixmap(rocket[0].rocket_crash_zs_x=rocket[0].rocket_x-20+bias,rocket[0].rocket_crash_zs_y=rocket[0].rocket_y+15,rocket[0].rocket_crash_zs_pix);
             painter.drawPixmap(rocket[0].rocket_crash_zx_x=rocket[0].rocket_x-20+bias,rocket[0].rocket_crash_zx_y=rocket[0].rocket_y+15+10,rocket[0].rocket_crash_zx_pix);
             painter.drawPixmap(rocket[0].rocket_crash_ys_x=rocket[0].rocket_x+20+bias,rocket[0].rocket_crash_ys_y=rocket[0].rocket_y+15,rocket[0].rocket_crash_ys_pix);
             painter.drawPixmap(rocket[0].rocket_crash_yx_x=rocket[0].rocket_x+20+bias,rocket[0].rocket_crash_yx_y=rocket[0].rocket_y+15+10,rocket[0].rocket_crash_yx_pix);
         }
         if(rocket[1].rocket_life==true&&rocket[1].rocket_crash_life==false)
         {
              painter.drawPixmap(rocket[1].rocket_x+bias1,rocket[1].rocket_y,rocket[1].rocket_pix);
         }
         if(rocket[1].rocket_life==true&&rocket[1].rocket_crash_life==true)
         {
             painter.drawPixmap(rocket[1].rocket_crash_zs_x=rocket[1].rocket_x-20+bias1,rocket[1].rocket_crash_zs_y=rocket[1].rocket_y+15,rocket[1].rocket_crash_zs_pix);
             painter.drawPixmap(rocket[1].rocket_crash_zx_x=rocket[1].rocket_x-20+bias1,rocket[1].rocket_crash_zx_y=rocket[1].rocket_y+15+10,rocket[1].rocket_crash_zx_pix);
             painter.drawPixmap(rocket[1].rocket_crash_ys_x=rocket[1].rocket_x+20+bias1,rocket[1].rocket_crash_ys_y=rocket[1].rocket_y+15,rocket[1].rocket_crash_ys_pix);
             painter.drawPixmap(rocket[1].rocket_crash_yx_x=rocket[1].rocket_x+20+bias1,rocket[1].rocket_crash_yx_y=rocket[1].rocket_y+15+10,rocket[1].rocket_crash_yx_pix);
         }

        //双人模式绘制上方动态蘑菇
        if(mushroom[0].istaste==false)
        {
            painter.drawPixmap(mushroom[0].mushroom_x+bias,mushroom[0].mushroom_y,mushroom[0].mushroom_pix);
        }
        //双人模式绘制下方动态蘑菇
        if(mushroom[1].istaste==false)
        {
            painter.drawPixmap(mushroom[1].mushroom_x+bias1,mushroom[1].mushroom_y,mushroom[1].mushroom_pix);
        }

        if(key[0].key_istaste==true)// paint keys
                {
                    //qDebug()<<1859;
                    painter.drawPixmap(key[0].key_x+bias,key[0].key_y-key[0].key_i,key[0].key_pix);
                    //key[0].key_istaste=false;
                }
                if(key[1].key_istaste==true)
                {
                    painter.drawPixmap(key[1].key_x+bias1,key[1].key_y-key[1].key_i,key[1].key_pix);
                    //key[1].key_istaste=false;
                }

        //绘制问题砖块，这里切图不是写在封装的类里面用定时器切换，因为16张图片是一张长图
        for(int i=0;i<7;i++)
        {
            if(question_wall[i].question_state==true)
            {//问题砖块的背后切图，并且这里是长图
                painter.drawPixmap(question_wall[i].question_x+bias,question_wall[i].question_y,question_wall[i].question_pix,50*question_wall[i].pix_biao++,0,50,50);
                if(question_wall[i].pix_biao==16)
                    question_wall[i].pix_biao=0;
            }

            if(question_wall[i].question_state==false)
            {
                //问题砖块被顶后切图
                question_wall[i].question_pix.load(QUESTION_HPICTURE);
                painter.drawPixmap(question_wall[i].question_x+bias,question_wall[i].question_y,question_wall[i].question_pix);
            }
        }

        for(int i=7;i<14;i++)
        {
            if(question_wall[i].question_state==true)
            {
                //问题砖块的背后切图，并且这里是长图
                painter.drawPixmap(question_wall[i].question_x+bias1,question_wall[i].question_y,question_wall[i].question_pix,50*question_wall[i].pix_biao++,0,50,50);
                if(question_wall[i].pix_biao==16)
                    question_wall[i].pix_biao=0;
            }

            if(question_wall[i].question_state==false)
            {
                //问题砖块被顶后切图
                question_wall[i].question_pix.load(QUESTION_HPICTURE);
                painter.drawPixmap(question_wall[i].question_x+bias1,question_wall[i].question_y,question_wall[i].question_pix);
            }
        }

        //双人模式绘制砖头
        for(int i=0;i<103;i++)
        {
            if(wall[i].wall_state==true&&!(i>=42&&i<=45))
                painter.drawPixmap(wall[i].wall_x+bias,wall[i].wall_y,wall[i].wall_pix);
            if(wall[i].wall_state==false&&wall[i].wall_life==true&&!(i>=42&&i<=45))
            {
                //绘制砖头的破裂
                painter.drawPixmap(wall[i].wall_x-75+bias,wall[i].wall_y-75,wall[i].zs_pix);
                painter.drawPixmap(wall[i].wall_x-75+bias,wall[i].wall_y+75,wall[i].zx_pix);
                painter.drawPixmap(wall[i].wall_x+75+bias,wall[i].wall_y-75,wall[i].ys_pix);
                painter.drawPixmap(wall[i].wall_x+75+bias,wall[i].wall_y+75,wall[i].yx_pix);
                wall[i].wall_life=false;//砖头死了，破裂效果只显示一次
            }
        }

        for(int i=103;i<206;i++)
        {
            if(wall[i].wall_state==true&&!(i>=145&&i<=148))
                painter.drawPixmap(wall[i].wall_x+bias1,wall[i].wall_y,wall[i].wall_pix);
            if(wall[i].wall_state==false&&wall[i].wall_life==true&&!(i>=145&&i<=148))
            {
                //绘制砖头的破裂
                painter.drawPixmap(wall[i].wall_x-75+bias1,wall[i].wall_y-75,wall[i].zs_pix);
                painter.drawPixmap(wall[i].wall_x-75+bias1,wall[i].wall_y+75,wall[i].zx_pix);
                painter.drawPixmap(wall[i].wall_x+75+bias1,wall[i].wall_y-75,wall[i].ys_pix);
                painter.drawPixmap(wall[i].wall_x+75+bias1,wall[i].wall_y+75,wall[i].yx_pix);
                wall[i].wall_life=false;//砖头死了，破裂效果只显示一次
            }
        }

        //双人模式绘制白色鬼魂
        for(int i=0;i<1;i++)
        {
            painter.drawPixmap(whitemonster[i].whitemonster_x1+bias,whitemonster[i].whitemonster_y1,whitemonster[i].whitemonster1_pix);
            painter.drawPixmap(whitemonster[i].whitemonster_x2+bias,whitemonster[i].whitemonster_y2,whitemonster[i].whitemonster2_pix);
        }

        for(int i=1;i<2;i++)
        {
            painter.drawPixmap(whitemonster[i].whitemonster_x1+bias1,whitemonster[i].whitemonster_y1+BIAS,whitemonster[i].whitemonster1_pix);
            painter.drawPixmap(whitemonster[i].whitemonster_x2+bias1,whitemonster[i].whitemonster_y2+BIAS,whitemonster[i].whitemonster2_pix);
        }


        //双人模式绘制子弹
        for(int i=0;i<5;i++)
        {
            bullet0[i].iscat=false;
            if(bullet0[i].bullet_free==false)//只有发射了才更新位置
                painter.drawPixmap(bullet0[i].bullet_x+bias,bullet0[i].bullet_y,bullet0[i].bullet_pix);
        }
        for(int i=0;i<5;i++)
        {
            bullet1[i].iscat=true;
            bullet1[i].bullet_pix.load(BULLET_BONE_PICTURE);
             bullet1[i].bullet_pix =  bullet1[i].bullet_pix.scaled(20,20);
            if(bullet1[i].bullet_free==false)//只有发射了才更新位置
                painter.drawPixmap(bullet1[i].bullet_x+bias1,bullet1[i].bullet_y,bullet1[i].bullet_pix);
        }
        //key appears on the left top of the window when it is found
        if(key[0].keypix_show)
                 painter.drawPixmap(460,time.timer_y,key[0].key_pix);
        if(key[1].keypix_show)
                 painter.drawPixmap(460,time.timer_y+BIAS+33,key[1].key_pix);

        //每当猫移动到中心屏幕并且想右移时，地图开始左移
        //###############################bias的修改地方
        if(cat[0].cat_x>=700)
        {
            cat[0].fakecat_x=700;
            bias=-(cat[0].cat_x-700);
        }
        if(cat[1].cat_x>=700)
        {
            cat[1].fakecat_x=700;
            bias1=-(cat[1].cat_x-700);
        }
    }

}


void MainWindow::keyPressEvent(QKeyEvent * event)
{
    //单人模式玩家键盘按下事件
    if(gamemode!=0)
    {
        if (cat_dead == 0)
        {
            //控制猫左右移动
            if (event->key() == Qt::Key_Left)//单人模式玩家按下左箭头，左移动
            {
                cat[0].cat_stand=true;//猫朝向左边
                cat[0].cat_rfree=true;
                cat[0].cat_lfree=false;
                cat[0].cat_can_move=true;
                        // 移动窗口向左
            }

            else if (event->key() == Qt::Key_Right)//单人模式玩家按下右箭头，右移动
            {
                cat[0].cat_stand=false;
                cat[0].cat_rfree=false;
                cat[0].cat_lfree=true;
                cat[0].cat_can_move=true;
                        // 移动窗口向右
             }

            else if (event->key() == Qt::Key_Space)//单人模式玩家按下空格，跳跃
            {if(cat[0].cat_jumpfree)
                    emit soundeffect("jump");//发出跳跃声
                cat[0].cat_jumpfree=false;//开始调用跳跃部分代码

            }

            else if (event->key() == Qt::Key_Down&&bullet0_fire==true)//单人模式玩家按下下箭头，发射子弹
                       { if(bullet0_num<=4){
                           emit soundeffect("fireball");
                           bullet0[bullet0_num].bullet_free=false;
                           bullet0[bullet0_num].timer.start(50);//开启定时器，子弹开始偏移
                           bullet0[bullet0_num].bullet_x=cat[0].cat_x;
                           bullet0[bullet0_num].bullet_y=cat[0].cat_y+30;//处于猫中央
                           if(cat[0].cat_stand==false)//控制子弹发射方向
                               bullet0[bullet0_num].bullet_pos=false;
                           if(cat[0].cat_stand==true)
                               bullet0[bullet0_num].bullet_pos=true;
                           bullet0[bullet0_num].bullet_rec.moveTo(bullet0[bullet0_num].bullet_x,bullet0[bullet0_num].bullet_y);

                           bullet0_num++;//子弹只设置了50发
                }
                       }
                       cat[0].cat_rec.moveTo(cat[0].cat_x,cat[0].cat_y);
                   }
               }

    //双人模式上方玩家键盘按下事件
    if(gamemode==0)
    {
        if (cat_dead == 0)
        {
            //控制猫左右移动
            if (event->key() == Qt::Key_Left)//双人模式上方玩家按下左箭头，左移动
            {
                cat[0].cat_stand=true;//猫朝向左边
                cat[0].cat_rfree=true;
                cat[0].cat_lfree=false;
                cat[0].cat_can_move=true;
                        // 移动窗口向左
            }

            else if (event->key() == Qt::Key_Right)//双人模式上方玩家按下右箭头，右移动
            {
                cat[0].cat_stand=false;
                cat[0].cat_rfree=false;
                cat[0].cat_lfree=true;
                cat[0].cat_can_move=true;
                        // 移动窗口向右
             }

            else if (event->key() == Qt::Key_Up)//双人模式上方玩家按下上箭头，跳跃
            { if(cat[0].cat_jumpfree)
                    emit soundeffect("jump");//发出跳跃声
              cat[0].cat_jumpfree=false;//开始调用跳跃部分代码

            }

            else if (event->key() == Qt::Key_Down&&bullet0_fire==true)//双人模式上方玩家按下下箭头，发射子弹
            {if(bullet0_num<=4){
                emit soundeffect("fireball");
                bullet0[bullet0_num].bullet_free=false;
                bullet0[bullet0_num].timer.start(50);//开启定时器，子弹开始偏移
                bullet0[bullet0_num].bullet_x=cat[0].cat_x;
                bullet0[bullet0_num].bullet_y=cat[0].cat_y+30;//处于猫中央

                if(cat[0].cat_stand==false)//控制子弹发射方向
                    bullet0[bullet0_num].bullet_pos=false;
                if(cat[0].cat_stand==true)
                    bullet0[bullet0_num].bullet_pos=true;
                bullet0[bullet0_num].bullet_rec.moveTo(bullet0[bullet0_num].bullet_x,bullet0[bullet0_num].bullet_y);

                bullet0_num++;//子弹只设置了50发
                }
            }
            cat[0].cat_rec.moveTo(cat[0].cat_x,cat[0].cat_y);
        }
    //双人模式下方玩家键盘按下事件
    if (cat_dead_2 == 0)
    {
        //控制猫左右移动
        if (event->key() == Qt::Key_A)//双人模式下方玩家按下A，左移动
        {
            cat[1].cat_stand=true;//猫朝向左边
            cat[1].cat_rfree=true;
            cat[1].cat_lfree=false;
            cat[1].cat_can_move=true;
                    // 移动窗口向左
         }

        else if (event->key() == Qt::Key_D)//双人模式下方玩家按下D，右移动
        {
            cat[1].cat_stand=false;
            cat[1].cat_rfree=false;
            cat[1].cat_lfree=true;
            cat[1].cat_can_move=true;
                    // 移动窗口向右
         }

        else if (event->key() == Qt::Key_W)//双人模式下方玩家按下W，跳跃
        {if(cat[1].cat_jumpfree)
                emit soundeffect("jump");//发出跳跃声
          cat[1].cat_jumpfree=false;//开始调用跳跃部分代码

        }

        else if (event->key() == Qt::Key_S&&bullet1_fire==true)//双人模式下方玩家按下S，发射子弹
               {    if(bullet1_num<=4){
                   emit soundeffect("fireball");
                   bullet1[bullet1_num].bullet_free=false;
                   bullet1[bullet1_num].timer.start(50);//开启定时器，子弹开始偏移
                   bullet1[bullet1_num].bullet_x=cat[1].cat_x;
                   bullet1[bullet1_num].bullet_y=cat[1].cat_y+30;//处于猫中央
                   if(cat[1].cat_stand==false)//控制子弹发射方向
                       bullet1[bullet1_num].bullet_pos=false;
                   if(cat[1].cat_stand==true)
                       bullet1[bullet1_num].bullet_pos=true;
                   bullet1[bullet1_num].bullet_rec.moveTo(bullet1[bullet1_num].bullet_x,bullet1[bullet1_num].bullet_y);

                   bullet1_num++;//子弹只设置了50发
            }
               }
               cat[1].cat_rec.moveTo(cat[1].cat_x,cat[1].cat_y);
           }
         }
       }

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    //单人模式和双人模式上方玩家键盘抬起事件
    if (event->key() == Qt::Key_Left)
    {
        cat[0].cat_rfree=true;//左右均为true，左右切图停止
        cat[0].cat_lfree=true;
        cat[0].cat_can_move=false;
                // 移动窗口向左
     }
    else if (event->key() == Qt::Key_Right)
    {
        cat[0].cat_rfree=true;
        cat[0].cat_lfree=true;
        cat[0].cat_can_move=false;
                // 移动窗口向右
    }
     cat[0].cat_rec.moveTo(cat[0].cat_x,cat[0].cat_y);

     //双人模式下方玩家键盘抬起事件
     if (event->key() == Qt::Key_A)
     {
         cat[1].cat_rfree=true;//左右均为true，左右切图停止
         cat[1].cat_lfree=true;
         cat[1].cat_can_move=false;
                 // 移动窗口向左
     }
     else if (event->key() == Qt::Key_D)
     {
         cat[1].cat_rfree=true;
         cat[1].cat_lfree=true;
         cat[1].cat_can_move=false;
                 // 移动窗口向右
     }
     cat[1].cat_rec.moveTo(cat[1].cat_x,cat[1].cat_y);
}

void MainWindow::mushroom_moving()
{
    //mushroom_moving()从crash中分离出来了，不然会建立多个信号与槽的连接，造成严重后果
    //双人模式上方蘑菇
    mushroom[0].mushroom_x=question_wall[0].question_x;//这里没有选择在封装的类中初始化因为不确定可能有多个蘑菇
    mushroom[0].mushroom_y=question_wall[0].question_y;
    connect(&mushroom[0].timer,QTimer::timeout,[=]()
    {if(mushroom[0].mushroom_up)
        {


        if(mushroom[0].i<5)
        {
            mushroom[0].i++;
            mushroom[0].mushroom_y-=10;
        }
        else
        {
            if(mushroom[0].j<20)
            {
                mushroom[0].j++;
                mushroom[0].mushroom_x+=10;
            }
            else
            {
                if(mushroom[0].mushroom_y<HEIGHT-GROUND_WIDTH-MUSHROOM_HEIGHT-30)
                    mushroom[0].mushroom_y+=10;
                else
                {
                    mushroom[0].mushroom_x-=10;
                }
            }
        }
        mushroom[0].mushroom_rec.moveTo(mushroom[0].mushroom_x,mushroom[0].mushroom_y);}
    });
    //双人模式下方蘑菇
        mushroom[1].mushroom_x=question_wall[7].question_x;
        mushroom[1].mushroom_y=question_wall[7].question_y;
        connect(&mushroom[1].timer,QTimer::timeout,[=]()
        {if(mushroom[1].mushroom_up){
            if(mushroom[1].m<5)
            {
                mushroom[1].m++;
                mushroom[1].mushroom_y-=10;
            }
            else
            {
                if(mushroom[1].n<20)
                {
                    mushroom[1].n++;
                    mushroom[1].mushroom_x+=10;
                }
                else
                {
                    if(mushroom[1].mushroom_y<HEIGHT-GROUND_WIDTH-MUSHROOM_HEIGHT+BIAS-10)//这里的数据可能要修改
                        mushroom[1].mushroom_y+=10;
                    else
                    {
                        mushroom[1].mushroom_x-=10;
                    }
                }
            }
            mushroom[1].mushroom_rec.moveTo(mushroom[1].mushroom_x,mushroom[1].mushroom_y);}
        });
    }
void MainWindow::rocket_moving1()
{
        rocket[0].rocket_x=6400;
        rocket[0].rocket_y=600;
      connect(&rocket[0].timer,QTimer::timeout,[=]()
      {
          if(rocket[0].i<=150)
          {
              rocket[0].i++;
              rocket[0].rocket_x-=15;

          }
          rocket[0].rocket_rec.moveTo(rocket[0].rocket_x,rocket[0].rocket_y);
      });
}

void MainWindow::rocket_moving2()
{
        rocket[1].rocket_x=6400;
        rocket[1].rocket_y=600+BIAS;
      connect(&rocket[1].timer,QTimer::timeout,[=]()
      {
          if(rocket[1].i<=150)
          {
              rocket[1].i++;
              rocket[1].rocket_x-=15;
          }
          rocket[1].rocket_rec.moveTo(rocket[1].rocket_x,rocket[1].rocket_y);
      });
}

void MainWindow::key_moving()
{
    connect(&key[0].timer,QTimer::timeout,[=](){
        if(key[0].key_i<50){
        key[0].key_i+=10;
        //key[0].key_rec.moveTo(key[0].key_x,key[0].key_y-=50);
        }
        //qDebug()<<key[0].key_i;
    });
    connect(&key[1].timer,QTimer::timeout,[=](){
        if(key[1].key_i<50){
        key[1].key_i+=10;
        //key[1].key_rec.moveTo(key[1].key_x,key[1].key_y-=50);
        }
    });

}
void MainWindow::crash()//碰撞箱设置
{
    //砖块碰撞检测
    for(int i=0;i<103;i++)
    {
        if((i==22||i==23||i==27||(i>=29&&i<=37)||i==52||i==53||i==54)&&cat[0].cat_rec.intersects(wall[i].wall_rec)==true){
            if(i==22||i==23){
            int dx1=cat[0].cat_rec.x() - wall[i].wall_rec.x();
            if(dx1<0)
            cat[0].cat_x=6740;
            if(dx1>0)
            cat[0].cat_x=6860;}
            if(i==27){
                cat[0].cat_x=7040;
            }
            if(i>=33&&i<=37){
                cat[0].cat_x=7360;
            }
            if(i>=52&&i<=53){
                int dx1=cat[0].cat_rec.x() - wall[i].wall_rec.x();
                if(dx1<0)
                cat[0].cat_x=7960;
                if(dx1>0)
                cat[0].cat_x=8060;
            }
        }
        //单人模式砖块碰撞和双人模式上方玩家砖块碰撞
        if(wall[i].wall_state==true&&cat[0].cat_rec.intersects(wall[i].wall_rec)==true&&!(i>=42&&i<=45)&&!(i>=22&&i<=23)&&!(i>=29&&i<=31)&&!(i>=33&&i<=37)&&!(i==27)&&!(i==52)&&!(i==53))
        {//qDebug()<<"dahjdagdhagh";
                 int dx = cat[0].cat_rec.x() - wall[i].wall_rec.x();
                 int dy = cat[0].cat_rec.y() - wall[i].wall_rec.y();
                      dy*=10;
                 if (qAbs(dx) < qAbs(dy))
                 {
                     // 竖直方向上的碰撞
                     if (dy > 0&&i!=24&&i!=28&&i!=38&&i!=32&&i!=54)//第24块砖头是特例
                     {
                         emit soundeffect("wall");
                         wall[i].wall_state=false;//检测到碰撞后开始绘制砖头破碎图
                         cat[0].cat_jump_height=wall[i].wall_y+WALL_HEIGHT;
                         cat[0].cat_up=false;//这里有小误差故需要加上手动变为下落
                      }
                      else
                      {
                          cat[0].cat_down=1;//告诉跳跃函数猫脚下有砖块
                          cat[0].cat_y=wall[i].wall_y-cat_HEIGHT;
                      }
                 }
        }
   }
   //双人模式下方玩家砖块碰撞
   for(int i=103;i<206;i++)
   {
       if((i==125||i==126||i==129||(i>=132&&i<=140)||i==155||i==156||i==157)&&cat[1].cat_rec.intersects(wall[i].wall_rec)==true){
           if(i==125||i==126){
           int dx1=cat[1].cat_rec.x() - wall[i].wall_rec.x();
           if(dx1<0)
           cat[1].cat_x=6740;
           if(dx1>0)
           cat[1].cat_x=6860;}
           if(i==130||i==131){
               cat[1].cat_x=7040;
           }
           if(i>=136&&i<=140){
               cat[1].cat_x=7360;
           }
           if(i>=52+92+11&&i<=53+92+11){
               int dx1=cat[1].cat_rec.x() - wall[i].wall_rec.x();
               if(dx1<0)
               cat[1].cat_x=7960;
               if(dx1>0)
               cat[1].cat_x=8060;
           }
       }
        if(wall[i].wall_state==true&&cat[1].cat_rec.intersects(wall[i].wall_rec)==true&&!(i>=145&&i<=148)&&!(i>=125&&i<=126)&&!(i>=132&&i<=134)&&!(i>=136&&i<=140)&&!(i==130)&&!(i==155)&&!(i==156))
        {

                   int dx1 = cat[1].cat_rec.x() - wall[i].wall_rec.x();
                   int dy1 = cat[1].cat_rec.y() - wall[i].wall_rec.y();
                       dy1*=10;
                   if (qAbs(dx1) < qAbs(dy1))
                   {
                       // 竖直方向上的碰撞
                       if (dy1 > 0&&i!=127&&i!=131&&i!=141&&i!=135&&i!=157)
                       {
                           emit soundeffect("wall");
                           wall[i].wall_state=false;//检测到碰撞后开始绘制砖头破碎图
                           cat[1].cat_jump_height=wall[i].wall_y+WALL_HEIGHT;
                           cat[1].cat_up=false;//这里有小误差故需要加上手动变为下落
                       }
                       else
                       {
                           cat[1].cat_down=1;//告诉跳跃函数猫脚下有砖块
                           cat[1].cat_y=wall[i].wall_y-cat_HEIGHT;
                       }
                   }
          }
    }

    //问号砖块碰撞检测
    for(int i=0;i<7;i++)
    {
           //这里不用检查state因为不管问号是否存在,对于每一个问号砖块都要碰撞检测
           //单人模式问号砖块碰撞和双人模式上方玩家问号砖块碰撞
           if(cat[0].cat_rec.intersects(question_wall[i].question_rec)==true)
           {
                      int dx = cat[0].cat_rec.x() - question_wall[i].question_rec.x();
                      int dy = cat[0].cat_rec.y() - question_wall[i].question_rec.y();
                      if (qAbs(dx) < qAbs(dy))
                      {
                          // 竖直方向上的碰撞
                          if (dy > 0)
                          {
                              if(i==key[0].random_num1&&question_wall[i].question_state == true){
                                  qDebug()<<key[0].random_num1;
                                  key[0].key_istaste=true;
                                  key[0].timer.start(100);
                              qDebug()<<2335;}
                              if(question_wall[i].question_state == true)
                                   emit soundeffect("questionwall");

                              question_wall[i].question_state=false;//检测到碰撞后开始绘制砖头破碎图

                              cat[0].cat_jump_height=question_wall[i].question_y+QUESTION_WALL_HEIGHT;
                              cat[0].cat_up=false;//这里有小误差故需要加上手动变猫为下落状态
                              if(i==0)
                                 {mushroom[0].timer.start(100);
                             mushroom[0].mushroom_up = 1; }//蘑菇开始移动
                          }
                          else
                          {
                              cat[0].cat_down=2;//告诉跳跃函数猫脚下有问题砖块
                              cat[0].cat_y=question_wall[i].question_y-cat_HEIGHT;
                          }
                      }
           }
   }
   //双人模式下方玩家砖块碰撞
   for(int i=7;i<14;i++)
   {
           if(cat[1].cat_rec.intersects(question_wall[i].question_rec)==true)
           {
                      int dx1 = cat[1].cat_rec.x() - question_wall[i].question_rec.x();
                      int dy1 = cat[1].cat_rec.y() - question_wall[i].question_rec.y();
                      if (qAbs(dx1) < qAbs(dy1))
                      {
                          // 竖直方向上的碰撞
                          if (dy1 > 0)
                          {
                              if(i==key[1].random_num2&&question_wall[i].question_state == true){
                                  key[1].key_istaste=true;
                                  key[1].timer.start(100);
                                  qDebug()<<2369;
                              }
                              if(question_wall[i].question_state == true)
                                    emit soundeffect("questionwall");
                              question_wall[i].question_state=false;//检测到碰撞后开始绘制砖头破碎图
                              cat[1].cat_jump_height=question_wall[i].question_y+QUESTION_WALL_HEIGHT;
                              cat[1].cat_up=false;//这里有小误差故需要加上手动变猫为下落状态
                              if(i==7)
                                 {mushroom[1].timer.start(100);
                             mushroom[1].mushroom_up = 1; }//蘑菇开始移动
                          }
                          else
                          {
                              cat[1].cat_down=2;//告诉跳跃函数猫脚下有问题砖块
                              cat[1].cat_y=question_wall[i].question_y-cat_HEIGHT;
                          }
                      }
               }
    }
      int dm0=cat[0].cat_rec.x() - hole[0].hole_rec.x();
      int dm1=cat[0].cat_rec.x()-hole[4].hole_rec.x();
      int dm2=cat[0].cat_rec.x() - hole[1].hole_rec.x();
      int dm3=cat[0].cat_rec.x()-hole[5].hole_rec.x();
      int dm4=cat[0].cat_rec.x() - hole[2].hole_rec.x();
      int dm5=cat[0].cat_rec.x()-hole[6].hole_rec.x();
      int dm6=cat[0].cat_rec.x() - hole[3].hole_rec.x();
      int dm7=cat[0].cat_rec.x()-hole[7].hole_rec.x();
      if(cat[0].cat_rec.intersects(hole[0].hole_rec)==true||cat[0].cat_rec.intersects(hole[4].hole_rec)==true)
      {
           cat[0].cat_x=2520-75;
      }
      if(cat[0].cat_rec.intersects(hole[1].hole_rec)==true||cat[0].cat_rec.intersects(hole[5].hole_rec)==true)
      {
          if(dm2>0||dm3>0)
              cat[0].cat_x=2520+Hole_LENGTH+GreenGround_Width+30;
      }
      if(cat[0].cat_rec.intersects(hole[2].hole_rec)==true||cat[0].cat_rec.intersects(hole[6].hole_rec)==true)
      {
          if(dm4<0||dm5<0)
              cat[0].cat_x=4550-75;
      }
      if(cat[0].cat_rec.intersects(hole[3].hole_rec)==true||cat[0].cat_rec.intersects(hole[7].hole_rec)==true)
      {
          if(dm6>0||dm7>0)
              cat[0].cat_x=4550+Hole_LENGTH+GreenGround_Width+30;
      }
      int dm8=cat[1].cat_rec.x() - hole[8].hole_rec.x();
      int dm9=cat[1].cat_rec.x()-hole[12].hole_rec.x();
      int dm10=cat[1].cat_rec.x() - hole[9].hole_rec.x();
      int dm11=cat[1].cat_rec.x()-hole[13].hole_rec.x();
      int dm12=cat[1].cat_rec.x() - hole[10].hole_rec.x();
      int dm13=cat[1].cat_rec.x()-hole[14].hole_rec.x();
      int dm14=cat[1].cat_rec.x() - hole[11].hole_rec.x();
      int dm15=cat[1].cat_rec.x()-hole[15].hole_rec.x();
      if(cat[1].cat_rec.intersects(hole[8].hole_rec)==true||cat[1].cat_rec.intersects(hole[12].hole_rec)==true)
      {
          if(dm8<0||dm9<0)
              cat[1].cat_x=2520-75;
      }
      if(cat[1].cat_rec.intersects(hole[9].hole_rec)==true||cat[1].cat_rec.intersects(hole[13].hole_rec)==true)
      {
          if(dm10>0||dm11>0)
              cat[1].cat_x=2520+Hole_LENGTH+GreenGround_Width+30;
      }
      if(cat[1].cat_rec.intersects(hole[10].hole_rec)==true||cat[1].cat_rec.intersects(hole[14].hole_rec)==true)
      {
          if(dm12<0||dm13<0)
              cat[1].cat_x=4550-75;
      }
      if(cat[1].cat_rec.intersects(hole[11].hole_rec)==true||cat[1].cat_rec.intersects(hole[15].hole_rec)==true)
      {
          if(dm14>0||dm15>0)
              cat[1].cat_x=4550+Hole_LENGTH+GreenGround_Width+30;
      }

    //猫与蘑菇的碰撞箱
    //单人模式的猫和双人模式上方的猫与蘑菇的碰撞箱
    if(cat[0].cat_rec.intersects(mushroom[0].mushroom_rec)==true)
    {
        bullet0_fire=true;//可以发射子弹了
        mushroom[0].istaste=true;//蘑菇被吃掉了，此后将不再显示
    }
    //双人模式下方的猫与蘑菇的碰撞箱
    if(cat[1].cat_rec.intersects(mushroom[1].mushroom_rec)==true)
    {
        bullet1_fire=true;//可以发射子弹了
        mushroom[1].istaste=true;//蘑菇被吃掉了，此后将不再显示
    }
    //猫与钥匙的碰撞箱
    if(cat[0].cat_rec.intersects(key[0].key_rec)==true&&key[0].key_istaste==true)
    {

        key[0].keypix_show = true;
        key[0].key_istaste=false;//蘑菇被吃掉了，此后将不再显示
    }
    //双人模式下方的猫与钥匙的碰撞箱
    if(cat[1].cat_rec.intersects(key[1].key_rec)==true&&key[1].key_istaste==true)
    {


        key[1].keypix_show = true;
        key[1].key_istaste=false;//蘑菇被吃掉了，此后将不再显示
    }
    //猫与火球的碰撞箱
    for(int i=0;i<2;i++)
    {
        if(cat[0].cat_rec.intersects(fire_hole[i].fire_hole_rec)==true)
            cat_dead = 1;
    }
    for(int i=2;i<4;i++)
    {
        if(cat[1].cat_rec.intersects(fire_hole[i].fire_hole_rec)==true)
            cat_dead_2 = 1;
    }

    //猫与白色鬼怪的碰撞箱
    if(cat[0].cat_rec.intersects(whitemonster[0].whitemonster1_rec)==true)
        cat_dead = 1;
    if(cat[0].cat_rec.intersects(whitemonster[0].whitemonster2_rec)==true)
        cat_dead = 1;
    if(cat[1].cat_rec.intersects(whitemonster[1].whitemonster1_rec)==true)
        cat_dead_2 = 1;
    if(cat[1].cat_rec.intersects(whitemonster[1].whitemonster2_rec)==true)
        cat_dead_2 = 1;

//    //小怪与子弹的碰撞箱
    for(int i=0;i<7;i++)
    {
         for(int j=0;j<5;j++)
         {
            if(bullet0[j].bullet_free==false && monster[i].monster_life==true)
            {
                //只有发射了才检测是否碰撞了
                if(bullet0[j].bullet_rec.intersects(monster[i].monster_rec) == true)
                {
                    emit soundeffect("stomp");
                    bullet0[j].bullet_free=true;
                    monster[i].monster_life=false;//小怪死亡，不再绘制
                    totalscore1+=80;
                }
             }
         }
    }
    for(int i=7;i<14;i++)
    {
         for(int j=0;j<5;j++)
         {
            if(bullet1[j].bullet_free==false&&monster[i].monster_life==true)
            {
                //只有发射了才检测是否碰撞了
                if(bullet1[j].bullet_rec.intersects(monster[i].monster_rec)==true)
                {
                    emit soundeffect("stomp");
                    bullet1[j].bullet_free=true;
                    monster[i].monster_life=false;//小怪死亡，不再绘制
                    totalscore2+=80;
                }
             }
         }
    }
    //小怪与猫踩踏的碰撞箱
    //单人模式和双人模式上方界面的碰撞
        for(int i=0;i<7;i++)
        {
            if(monster[i].monster_life==true&&cat[0].cat_rec.intersects(monster[i].monster_rec)==true)
            {
                    int dx = cat[0].cat_rec.x() - monster[i].monster_rec.x();
                    int dy = cat[0].cat_rec.y() - monster[i].monster_rec.y();

                    if (qAbs(dx) < qAbs(dy))
                    {
                        // 竖直方向上的碰撞
                        if (dy < 0&& cat[0].cat_crash_monster==0)
                        {
                             monster[i].bian();
                             emit soundeffect("stomp");
                             monster[i].monster_life=false;//小怪死亡，不再绘制
                             monster[i].monster_kill_cai=true;
                             totalscore1+=150;
                         }
                    }
                    if (qAbs(dx) > qAbs(dy))
                    {
                         cat_dead = 1;
                         cat[0].cat_crash_monster=1;
                    }
            }
        }
        //双人模式下方界面的碰撞
        for(int i=7;i<14;i++)
        {
            if(monster[i].monster_life==true&&cat[1].cat_rec.intersects(monster[i].monster_rec)==true)
            {
                    int dx = cat[1].cat_rec.x() - monster[i].monster_rec.x();
                    int dy = cat[1].cat_rec.y() - monster[i].monster_rec.y();

                    if (qAbs(dx) < qAbs(dy))
                    {
                        // 竖直方向上的碰撞
                        if (dy < 0&& cat[1].cat_crash_monster==0)
                        {
                             monster[i].bian();
                             emit soundeffect("stomp");
                             monster[i].monster_life=false;//小怪死亡，不再绘制
                             monster[i].monster_kill_cai=true;
                             totalscore2+=150;
                         }
                    }
                    if (qAbs(dx) > qAbs(dy))
                    {
                         cat_dead_2 = 1;
                         cat[1].cat_crash_monster=1;
                    }
            }
        }

       //猫与火箭的碰撞箱
        if(cat[0].cat_x>=5300&&cat[0].cat_x<=5350)
        {
            rocket[0].rocket_life=true;
            rocket[0].timer.start(Rocket_move);
            //rocket_moving1();
        }

        if(cat[1].cat_x>=5300&&cat[1].cat_x<=5350)
        {
            rocket[1].rocket_life=true;
            rocket[1].timer.start(Rocket_move);
        }

       //单人模式和双人模式上方
        if(rocket[0].rocket_life==true&&cat[0].cat_rec.intersects(rocket[0].rocket_rec)==true)
        {
            rocket[0].rocket_crash();
            rocket[0].rocket_crash_life=true;
            totalscore1-=12;
         }
        //双人模式下方
        if(rocket[1].rocket_life==true&&cat[1].cat_rec.intersects(rocket[1].rocket_rec)==true)
        {
            rocket[1].rocket_crash();
            rocket[1].rocket_crash_life=true;
            totalscore2-=12;
         }

    //乌龟与子弹的碰撞箱
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(bullet0[j].bullet_free==false&&turtle[i].turtle_isroll==false)
            {
                if(bullet0[j].bullet_rec.intersects(turtle[i].turtle_rec)==true)
                {
                    emit soundeffect("stomp");
                    bullet0[j].bullet_free=true;
                    turtle[i].turtle_isroll=true;
                    turtle[i].turtle_y+=30;
                    turtle[i].timer3.start(TURTLE_MOVE);//子弹与乌龟碰撞，乌龟蜷缩
                    totalscore1+=60;
                }
            }
         }
    }
    for(int i=3;i<6;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(bullet1[j].bullet_free==false&&turtle[i].turtle_isroll==false)
            {
                if(bullet1[j].bullet_rec.intersects(turtle[i].turtle_rec)==true)
                {
                    emit soundeffect("stomp");
                    bullet1[j].bullet_free=true;
                    turtle[i].turtle_isroll=true;
                    turtle[i].turtle_y+=30;
                    turtle[i].timer3.start(TURTLE_MOVE);//子弹与乌龟碰撞，乌龟蜷缩
                    totalscore2+=60;
                }
            }
         }
    }
    //猫与乌龟的碰撞箱
    //单人模式的猫和双人模式上方界面的猫与乌龟的碰撞
    for(int i=0;i<3;i++)
    {
        if(cat[0].cat_rec.intersects(turtle[i].turtle_rec)==true&&turtle[i].turtle_isroll==false)
        {
            int dx = cat[0].cat_rec.x() - turtle[i].turtle_rec.x();
            int dy = cat[0].cat_rec.y() - turtle[i].turtle_rec.y();
             if (qAbs(dx) < qAbs(dy))
             {
                bullet0[i].bullet_free=true;
                turtle[i].turtle_isroll=true;
                turtle[i].turtle_y+=30;
                turtle[i].timer3.start(TURTLE_MOVE);
                totalscore1+=95;
                //这里选择的是每次碰撞重新启动定时器而不是调用函数是为了
                //防止多次启动函数建立信号与槽使得时间间隔越来越快,这里代码要执行多次不能这样做
                emit soundeffect("shellkick");
             }
             if (qAbs(dx) > qAbs(dy)&&turtle[i].turtle_isroll==false)
             {
                 cat_dead = 1;
             }
        }
    }

    //双人模式下方界面的猫与乌龟的碰撞
    for(int i=3;i<6;i++)
    {
        if(cat[1].cat_rec.intersects(turtle[i].turtle_rec)==true&&turtle[i].turtle_isroll==false)
        {
            int dx1 = cat[1].cat_rec.x() - turtle[i].turtle_rec.x();
            int dy1= cat[1].cat_rec.y() - turtle[i].turtle_rec.y();
             if (qAbs(dx1) < qAbs(dy1))
             {
                bullet1[i].bullet_free=true;
                turtle[i].turtle_isroll=true;
                turtle[i].turtle_y+=30;
                turtle[i].timer3.start(TURTLE_MOVE);
                totalscore2+=95;
                //这里选择的是每次碰撞重新启动定时器而不是调用函数是为了防止多次启动函数建立信号与槽使得时间间隔越来越快,这里代码要执行多次不能这样做
                emit soundeffect("shellkick");
             }

             if (qAbs(dx1) > qAbs(dy1)&&turtle[i].turtle_isroll==false)
             {
                 cat_dead_2 = 1;
             }
        }
    }

    //猫与火球的碰撞箱
   for(int i=0;i<2;i++)
   {
        if(cat[0].cat_rec.intersects(fire_hole[0].fire_hole_rec))
        {
            cat_dead = 1;
            totalscore1-=75;
            emit soundeffect("stomp");
        }
    }

    for(int i=2;i<4;i++)
    {
        if(cat[1].cat_rec.intersects(fire_hole[i].fire_hole_rec))
        {
            cat_dead_2 = 1;
            totalscore2-=75;
            emit soundeffect("stomp");
        }
    }
    //猫与金币的碰撞箱
        for(int i=0;i<165;i++)
        {
            if(gold[i].gold_rec.intersects(cat[0].cat_rec))
            {
                double k=1.02,m=1.00;
                const int j=15;
                emit soundeffect("coin");//发出拾取金币的声音
                gold[i].gold_life = 1;
                gold[i].gold_rec.moveTo(0,0);
                coincounter[0].toatalcoin++;
                for(int l=0;l<coincounter[0].toatalcoin;l++)
                {
                    m*=k;
                }
                m=(int)m;
                totalscore1+=m*j;
                m=1.00;
            }
        }
        for(int i=165;i<330;i++)
            {
                if(gold[i].gold_rec.intersects(cat[1].cat_rec))
                {
                    double k=1.02,m=1.00;
                    const int j=15;
                    emit soundeffect("coin");//发出拾取金币的声音
                    gold[i].gold_life = 1;
                    gold[i].gold_rec.moveTo(0,0);
                    coincounter[1].toatalcoin++;
                    for(int l=0;l<coincounter[1].toatalcoin;l++)
                    {
                        m*=k;
                    }
                    m=(int)m;
                    totalscore2+=m*j;
                    m=1.00;
                }
            }


    //城堡与猫的碰撞箱->游戏结束

    if(gamemode==1)
    {
        if(cat[0].cat_rec.intersects(flagandcastle[0].castle_rec))
        {
            update_timer.stop();//暂停计时器
            emit soundeffect("stop");//让原先的背景音乐停止
            winwindow.show();
        }
    }
    if(gamemode==0)
    {
        if(cat[0].cat_rec.intersects(flagandcastle[0].castle_rec) && key[0].keypix_show)
        {
           update_timer.stop();//暂停计时器
            emit soundeffect("stop");//让原先的背景音乐停止
            cat1_win = 1;
            gameover_time();
        }
        if(cat[1].cat_rec.intersects(flagandcastle[1].castle_rec) && key[1].keypix_show)
        {
            update_timer.stop();//暂停计时器
            emit soundeffect("stop");//让原先的背景音乐停止
            cat2_win = 1;
            gameover_time();
        }


    }

}

//这里想到两个碰撞检测方法，一种使用intersected与contains来检测，但是前提是要设置多个碰撞检测点，需要的东西比较多
//第二种是利用砖块的x,y坐标以及厚度与高度来检测碰撞范围(利用到猫此时的坐标)，以此来确定猫在下方还是上方
//最后发现是第三种的判断比较好用

void MainWindow::cat_moveground_down()
{
    if(cat[0].cat_move_state==false&&cat[0].cat_down!=0)
    {
        if((cat[0].cat_x>9825&&cat[0].cat_x<9851)||(cat[0].cat_x>10146&&cat[0].cat_x<10195))
        {
            cat[0].cat_jumpfree=false;
            cat[0].cat_up=false;
            cat[0].cat_down=0;
         }
     }
    //
    if(cat[1].cat_move_state==false&&cat[1].cat_down!=0)
    {
        if((cat[1].cat_x>9825&&cat[1].cat_x<9851)||(cat[1].cat_x>10146&&cat[1].cat_x<10195))
        {
            cat[1].cat_jumpfree=false;
            cat[1].cat_up=false;
            cat[1].cat_down=0;
         }
     }
}


void MainWindow::cat_any_down()
{
    for(int i=0;i<103;i++)
    {
              //单人模式和双人模式上方猫自由落体
              if(wall[i].wall_state==false&&cat[0].cat_down!=0)
              {
                  if(cat[0].cat_x>wall[i].wall_x-25&&cat[0].cat_x<wall[i].wall_x+30)
                  {
                      cat[0].cat_jumpfree=false;//如果觉得不好右边数据可以改为50左边的25也可调节
                      cat[0].cat_up=false;
                      cat[0].cat_down=0;
                   }
               }
     }
    for(int i=103;i<206;i++)
    {
        //双人模式下方猫自由落体
        if(wall[i].wall_state==false&&cat[1].cat_down!=0)
        {
           if(cat[1].cat_x>wall[i].wall_x-25&&cat[1].cat_x<wall[i].wall_x+30)
           {
                cat[1].cat_jumpfree=false;//如果觉得不好右边数据可以改为50左边的25也可调节
                cat[1].cat_up=false;
                cat[1].cat_down=0;
           }
        }
    }
}//这段代码实现了猫的掉落效果，如果不想要直接注释掉



void MainWindow::cat_float()
{
    if(cat[0].cat_x<9830||cat[0].cat_x>10156&&cat[0].cat_down==0)//猫脚下无东西
    {
        cat[0].cat_move_state=false;
        cat[0].cat_label=true;
        cat[0].cat_height_min=HEIGHT-GROUND_WIDTH-cat_HEIGHT-20;
    }
    if(cat[0].cat_x>=9830&&cat[0].cat_x<=10156&&cat[0].cat_jumpfree==false&&cat[0].cat_y+50<=moveground[0].moveground_y)
    {
        cat[0].cat_height_min=moveground[0].moveground_y-50;
        cat[0].cat_label=false;
    }
    if(cat[0].cat_label==false)
    {
        cat[0].cat_move_state=true;
        cat[0].cat_down=1;
        cat[0].cat_y=moveground[0].moveground_y-50;
     }

    if(cat[1].cat_x<9830||cat[1].cat_x>10156&&cat[1].cat_down==0)//猫脚下无东西
    {
        cat[1].cat_move_state=false;
        cat[1].cat_label=true;
        cat[1].cat_height_min=HEIGHT-GROUND_WIDTH-cat_HEIGHT-20;
    }
    if(cat[1].cat_x>=9830&&cat[1].cat_x<=10156&&cat[1].cat_jumpfree==false&&cat[1].cat_y+50<=moveground[4].moveground_y)
    {
        cat[1].cat_height_min=moveground[4].moveground_y-50;
        cat[1].cat_label=false;
    }
    if(cat[1].cat_label==false)
    {
        cat[1].cat_move_state=true;
        cat[1].cat_down=1;
        cat[1].cat_y=moveground[4].moveground_y-50;
     }
}

void MainWindow::gameover_time()
{
update_timer.stop();
    gameover.type = 0;

    if(gamemode==0)
    {
        if(cat1_win)//玩家1先接触到castle
        {

                winner.winnerplayer=true;//玩家1胜利
                winner.score = totalscore1;


        }
        if(cat2_win)//玩家2先接触到castle
        {

                winner.winnerplayer=false;//玩家2胜利
                winner.score = totalscore2;


        }
        if(cat[0].cat_life == 0)
        {
            winner.winnerplayer=false;//玩家2胜利
            winner.score = totalscore2;
        }
        if(cat[1].cat_life == 0)
        {
            winner.winnerplayer=true;//玩家2胜利
            winner.score = totalscore1;
        }
    }
 winner.show();
 connect(winner.exitbutton, &QPushButton::clicked, this,[=](){
    playagian();
    winner.hide();
 });

    winner.time = time.timetoover;
    emit soundeffect("stop");//让原先的背景音乐停止
   // emit soundeffect("gameover");

}
void MainWindow::playagian(){
    emit soundeffect("stop");
    emit soundeffect("theme");
    update_timer.start();
    build_wall();
    set_whitemonster();
    set_turtle();
    set_monster();
    set_moveground();
    set_grassground();
    setCoin();
    set_hole();
    set_flagandcastle();
    cat[0].cat_x = 100;
    cat[0].fakecat_x = 100;
    cat[1].cat_x = 100;
    cat[1].fakecat_x = 100;


    bias = 0;
    bias1 = 0;
    setFocusPolicy(Qt::StrongFocus);
    if(gamemode == 1)
        time.timetoover= GAMETIME1;//计时开始，时间结束后游戏结束
    if(gamemode == 0)
        time.timetoover= GAMETIME2;//计时开始，时间结束后游戏结束
emit soundeffect("theme");
    for(int i =0 ;i < 330; i++)
        gold[i].gold_life = 0;
    for(int i = 0 ;i < 14; i++)
    {


        monster[i].bian_time=0;//用于绘制小怪被踩扁后绘制踩扁图片，因为这里要让扁的图片存在一段时间
        monster[i].monster_lfree = true;//默认一开始怪物朝右进行移动
        monster[i].monster_rfree = false;
        monster[i]. monster_life = true;
        monster[i]. monster_kill_cai = false;//这个变量用于区分在绘图小怪踩扁图片如果用子弹打死小怪不会绘制扁小怪图片
        monster[i].timer.start(MONSTER_MOVE);
    }
    for(int i = 0 ;i < 206; i++)
    {wall[i].wall_life = 1;
    wall[i].wall_state = 1;}

 for(int i = 0; i < 14; i++)
 {question_wall[i].question_state = 1;
 question_wall[i].question_pix.load(QUESTION_PICTURE);
  question_wall[i].question_pix = question_wall[i].question_pix .scaled(800,50);}
    totalscore1 = 0;
    totalscore2 = 0;

  for(int i = 0;i <5 ; i++)
    {
       bullet0[i].bullet_free=true;
       bullet1[i].bullet_free=true;
    }
  bullet0_num =0; bullet1_num = 0;
  bullet0_fire=false;//开始时猫不能发射子弹
  bullet1_fire=false;//开始时猫不能发射子弹
  mushroom[0].mushroom_x = question_wall[0].question_x;
  mushroom[0].mushroom_y = question_wall[0].question_y;
  mushroom[1].mushroom_x = question_wall[7].question_x;
  mushroom[1].mushroom_y = question_wall[7].question_y;
    mushroom[0].mushroom_up = 0;
    mushroom[1].mushroom_up = 0;
      mushroom[0].istaste = 0;mushroom[1].istaste = 0;
      mushroom[0].i=0;mushroom[0].j=0;mushroom[0].m=0;mushroom[0].n=0;
      mushroom[1].i=0;mushroom[1].j=0;mushroom[1].m=0;mushroom[1].n=0;
      key[0].key_x=question_wall[key[0].random_num1].question_x;
      key[0].key_y=question_wall[key[0].random_num1].question_y;
      key[0].key_rec.moveTo(question_wall[key[0].random_num1].question_x,question_wall[key[0].random_num1].question_y-50);
      key[0].key_add1=0;key[0].key_add2=0;
      key[0].key_istaste=false;
      key[0].key_i=0;
      key[1].key_x=question_wall[key[1].random_num2].question_x;
      key[1].key_y=question_wall[key[1].random_num2].question_y;
      key[1].key_rec.moveTo(question_wall[key[1].random_num2].question_x,question_wall[key[1].random_num2].question_y-50);
      key[1].key_add1=0;key[1].key_add2=0;
      key[1].key_istaste=false;
      key[1].key_i=0;
    coincounter[0].toatalcoin = 0;coincounter[1].toatalcoin = 0;
    cat[0].cat_life = 5; cat[1].cat_life = 5;
    key[0].keypix_show = 0;
    key[1].keypix_show = 0;
    rocket[0].rocket_x=6400;
    rocket[0].rocket_y=600;
    rocket[1].rocket_x=6400;
    rocket[1].rocket_y=600+BIAS;
    rocket[0].rocket_crash_zs_x=rocket[0].rocket_x-20+bias;rocket[0].rocket_crash_zs_y=rocket[0].rocket_y+15;
    rocket[0].rocket_crash_zx_x=rocket[0].rocket_x-20+bias;rocket[0].rocket_crash_zx_y=rocket[0].rocket_y+15+10;
    rocket[0].rocket_crash_ys_x=rocket[0].rocket_x+20+bias;rocket[0].rocket_crash_ys_y=rocket[0].rocket_y+15;
    rocket[0].rocket_crash_yx_x=rocket[0].rocket_x+20+bias;rocket[0].rocket_crash_yx_y=rocket[0].rocket_y+15+10;
    rocket[1].rocket_crash_zs_x=rocket[1].rocket_x-20+bias;rocket[1].rocket_crash_zs_y=rocket[1].rocket_y+15;
    rocket[1].rocket_crash_zx_x=rocket[1].rocket_x-20+bias;rocket[1].rocket_crash_zx_y=rocket[1].rocket_y+15+10;
    rocket[1].rocket_crash_ys_x=rocket[1].rocket_x+20+bias;rocket[1].rocket_crash_ys_y=rocket[1].rocket_y+15;
    rocket[1].rocket_crash_yx_x=rocket[1].rocket_x+20+bias;rocket[1].rocket_crash_yx_y=rocket[1].rocket_y+15+10;
    rocket[0].rocket_crash_life=false;
    rocket[1].rocket_crash_life=false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

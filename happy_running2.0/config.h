#ifndef CONFIG_H
#define CONFIG_H
/*********屏幕窗口资源文件**********/
#define HEIGHT 740 // 窗口高度
#define WIDTH  1460 // 窗口宽度
/*********草地资源文件**********/
#define GROUND_PICTURE "://picture/b_waterB_top.png"//紫色草地图片
#define GROUND_LENGTH 96//紫色草地的长
#define GROUND_WIDTH  24//紫色草地的厚度
#define GreenGround_PICTURE "://picture/b_posiplain_top(1).png"//竖直绿色地面图片
#define GreenGround_Width 32 //竖直绿色地面的宽
#define GreenGround_Height 112 //数值绿色地面的高
#define GreenGround_l_PICTURE "://picture/b_posiplain_top.png"//水平绿色地面图片
#define GreenGround_l_Length 112//水平绿色地面的长度
#define GreenGround_l_Height 32//水平绿色地面的宽度
#define GreenGround_l_Time 100//设置地面移动时间间隔
/*********乌龟资源文件**********/
#define TURTLE_HEIGHT  66//乌龟的高度
#define TURTLE_ROLL  ":/picture/roll.png"//乌龟缩回去照片
#define TURTLE_PICTURE  ":/picture/w%1.png"//乌龟向左走共12张从下标0开始
#define TURTLE_RPICTURE ":/picture/wr%1.png"//乌龟向右走共12张从下标0开始
//切图时间间隔最好与移动时间间隔一样
#define TURTLE_CHANGE_PIX 100//乌龟切图时间间隔
#define TURTLE_MOVE 100//乌龟移动时间间隔
#define TURTLE_LEFT_MAX  100//乌龟初始x坐标
#define TURTLE_MOVE_MAX  400//乌龟的最大移动距离
/*********猫资源文件**********/
#define cat_PICTURE  ":/picture/ml%1.png"//猫向左走共22张从下标0开始
#define DOG_PICTURE ":/picture/bl%1.png"
#define cat_RPICTURE  ":/picture/mr%1.png"//猫向右走共22张从下标0开始
#define DOG_RPICTURE ":/picture/br%1.png"
#define cat_STAND    ":/picture/mr_stand.png"//猫向右站立图
#define DOG_STAND   ":/picture/br_stand01.png"
#define cat_LSTAND   ":/picture/ml_stand.png"//猫向左站立图
#define DOG_LSTAND        "://picture/bl_stand01.png"
#define cat_JUMP     ":/picture/mr_jump.png"//猫向右跳跃图
#define DOG_JUMP       "://picture/br_jump01.png"
#define cat_LJUMP     ":/picture/ml_jump.png"//猫向左跳跃图
#define DOG_LJUMP "://picture/bl_jump01.png"
#define cat_CHANGE_PIX 25//猫切图时间间隔
#define cat_HEIGHT  70//猫的高度
#define cat_RGREEN    ":/picture/walk_right2.png"//猫绿色皮肤向右
#define cat_LGREEN    ":/picture/walk_left2.png"//猫绿色皮肤向左
#define cat_RBLUE    ":/picture/walk_right3.png"//猫蓝色皮肤向右
#define cat_LBLUE    ":/picture/walk_left3.png"//猫蓝色皮肤向左
#define cat_DEAD "://picture/mariodead.png"  //猫死了的图片
#define DOG_DEAD ":/picture/dogdead.png"
//#define cat_JUMP_HEIGHT 100//猫跳跃高度
/*********墙资源文件**********/
//#define WALL_PICTURE ":/picture/ml1.png"
#define WALL_PICTURE ":/picture/normalwall.png"//墙图片
#define WALL_MEW_PICTURE "://picture/rock_packed.png"//新砖块图片
#define WALL_MEW_WIDTH 162//新砖块的宽度
#define WALL_NEW_HEIGHT 162//新砖块的高度
#define WALL_WIDTH    50  //墙的宽度
#define WALL_HEIGHT   50  //墙的高度
#define WALL_QUESTION_PICTURE ":/picture/abnormalwall.png"//掉落蘑菇的随机墙
#define WALL_KONG__PICTURE    ":/picture/afterabnormalwall.png"//掉落蘑菇的墙
#define WALL_BREAK_ZS ":/picture/zs.png"//墙破碎左上图片
#define WALL_BREAK_ZX ":/picture/zx.png"//墙破碎左下图片
#define WALL_BREAK_YS ":/picture/ys.png"//墙破碎右上图片
#define WALL_BREAK_YX ":/picture/yx.png"//墙破碎右下图片
/*********问号墙资源文件**********/
#define QUESTION_PICTURE   ":/picture/unknown.png"//问号墙顶前图片//包含16张小图，规格要设为800*50的
#define QUESTION_HPICTURE  ":/picture/afterabnormalwall.png"//问号墙顶后图片
#define QUESTION_WALL_WIDTH    50  //墙的宽度
#define QUESTION_WALL_HEIGHT   50  //墙的高度
/*********小怪资源文件**********/
#define MONSTER_RPICTURE  ":/picture/master_1.png"//小怪向右图片
#define MONSTER_LPICTURE  ":/picture/master_0.png"//小怪向左图片
#define MONSTER_MOVE    150//小怪移动时间间隔
#define MONSTER_LEFT_MAX  200//小怪初始x坐标
#define MONSTER_RIGHT_MAX  100//小怪的最大移动距离
/*********蘑菇资源文件**********/
#define GREEN_MUSHROOM ":/picture/mushroom1.png"//绿色蘑菇，吃了免疫一次伤害
#define BLUE_MUSHROOM  ":/picture/mushroom2.png"//蓝色蘑菇，得在绿色蘑菇效果存在时吃了才管用
#define MUSHROOM_HEIGHT 50   //蘑菇的高度
/*********子弹资源文件**********/
#define BULLET_PICTURE ":/picture/fire.png"//子弹图片
#define BULLET_FISH_PICTURE ":/picture/bo.png"//小鱼图片
#define BULLET_BONE_PICTURE ":/picture/yang (1).png"//骨头图片
//除了免疫一次伤害还可以发射子弹，

/*********指示牌资源文件**********/
#define GUIDEBORAD "://picture/sign.png"

/*********状态栏资源文件**********/
#define TIMER_PICTURE "://picture/clock.png"//时钟的图标
#define COINCOUNTER_PICTURE "://picture/money.png"//右上角硬币栏的图标
#define LITTLEcat "://picture/smallMarioStop.png"//用于生命显示的猫图标

/*********gameover资源文件**********/
#define YELLOWBUTTON "://picture/pushButton.png"
#define REDBUTTON "://picture/pushButton1.png"

//管道设置
#define Pipe_PICTURE "://picture/pipe.png"//管道图片
#define Pipe_LENGTH 71//管道图片的长度
#define Pipe_WIDTH  147//管道图片的高度

//食人花设置
#define Flower_PICTURE "://picture/%1.png"//食人花图片
#define Flower_CHANGE_PIX 50//设置食人花切图时间间隔

//红色蘑菇设置
#define RedBrick_PICTURE "://C:/Users/杨鹏宇/Desktop/photo/picture/normalwall.png"//普通砖块图片
#define RedMushroom_PICTURE "://C:/Users/杨鹏宇/Desktop/photo/picture/m5.png"//红色蘑菇图片
#define RedMushroom_CHANGE_PIX 100//设置红色蘑菇切图时间间隔
#define RedMushroom_HEIGHT 50//设置红色蘑菇高度

//金币设置
#define Gold_PICTURE ":/picture/coin.png"//设置金币图片
#define Gold_LENGTH 50 //金币图片的长度
#define Gold_WIDTH 50 //金币图片的宽度

//小悬崖设置
#define Hole_PICTURE "://picture/hole.png"//设置小悬崖图片
#define Hole_LENGTH 167 //小悬崖图片的长度
#define Hole_WIDTH 73 //小悬崖图片的宽度

//炸弹设置
#define Bomb_PICTURE "://C:/Users/杨鹏宇/Desktop/photo/picture/bomb(1).png"//炸弹图片
#define Bomb_HEIGHT  122//炸弹的高度
#define Bomb_WIDTH 128//炸弹的宽度

//分数图标设置
#define Score_PICTURE "://C:/Users/杨鹏宇/Desktop/photo/picture/scoretext(1).png"//分数图标图片
#define Score_WIDTH 83//分数图标图片宽度
#define Score_HEIGHT 26//分数图标图片高度
#define Score_GOLDNUMBERADD 15//设置单个金币可以获得的分数


//悬浮地面设置
#define SFloatGround_PICTURE "://picture/wallg(1).png"//小型悬浮地面图
#define LFloatGround_PICTURE "://picture/walli(1).png"//长悬浮地面图
#define SFloatGround_LENGTH 400//小型悬浮地面长度
#define SFloatGround_HEIGHT 349//小型悬浮地面高度
#define LFloatGround_LENGTH 800//长悬浮地面长度
#define LFloatGround_HEIGHT 151//长悬浮地面高度

//音乐砖块设置
#define MusicBrick_PICTURE "://C:/Users/杨鹏宇/Desktop/photo/picture/notebox(1).png"//音乐砖块图片
#define MusicBrick_HEIGHT 65//设置音乐砖块的高度
#define MusicBrick_WIDTH 65//设置音乐砖块的宽度

//白色鬼魂设置
#define WhiteMonster_PICTURE "://picture/monster.png"//设置白色鬼魂图片
#define WhiteMonster_WIDTH 45//设置白色鬼魂图片的宽度
#define WhiteMonster_HEIGHT 45//设置白色鬼魂图片的高度
#define WhiteMonster_Time 100//设置白色鬼魂时间间隔

//旗帜和城堡
#define FLAG_PIC "://picture/flag.png"//旗帜
#define FLAGPOLE_PIC "://picture/final.png"//旗杆
#define FLAGPOLE_HEIGHT 451 //旗杆高度
#define CASTLE_PIC "://picture/castle.png"//城堡
#define CASTLE_HEIGHT 396//城堡高度

//小火箭设置
#define Rocket_PICTURE "://picture/rocket2.png"//加载小火箭图片
#define Rocket_length 843//小火箭长度
#define Rocket_height 448//小火箭宽度
#define Rocket_move 100//火箭移动时间间隔
#define Rocket_crash_PICTURE "://picture/fire.png"//设置火球图片
#define Rocket_crash_WIDTH 217//火球宽度
#define Rocket_crash_HEIGHT 209//火球高度
#define fire_TIME 100//设置火球切换时间间隔

//游戏结束设置
#define GAMETIME1 300//单人游戏初始时间
#define GAMETIME2 0.0//双人游戏初始时间
#define Gameover_PICTURE "://picture/gameovers.png"//游戏结束图片
#define Gameover_HEIGHT 720//游戏结束图片高度
#define Gameover_WIDTH 1280//游戏结束图片宽度
#define YOUDIED_TEXT "://picture/youdied.png"//文字：死了
#define TIMEUP_TEXT "://picture/TIMEUp.png"//文字：时间到
#define WIN_PIC "://picture/winwindowtext.png"//游戏胜利
#define BIAS 630//上下偏移
#define WINNER_PICTURE "://picture/over.png"//双人游戏结束初界面
/*********钥匙资源文件**********/
#define KEY_PICTURE "://picture/key.png"//钥匙图片
#endif // CONFIG_H

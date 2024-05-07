#include "dj.h"

DJ::DJ(QWidget *parent) : QDialog(parent)
{
           this->theme = new QMediaPlayer;//背景音乐
           theme->setSource(QUrl("qrc:/audio/ThemeSong.MP3"));




           this->cat_jump = new QSoundEffect;  //跳跃音效
           cat_jump->setSource(QUrl("qrc:/audio/jump.wav"));
           cat_jump->setLoopCount(0);//不循环
           cat_jump->setVolume(.20f);

           this->fireball = new QSoundEffect;  //火球音效
           fireball->setSource(QUrl("qrc:/audio/fireball.wav"));
           fireball->setLoopCount(0);//不循环
           fireball->setVolume(.20f);

           this->button = new QSoundEffect;//按钮按下的声音
           button->setSource(QUrl("qrc:/audio/Select.wav"));
           button->setLoopCount(0);//不循环
           button->setVolume(.20f);

           this->coin = new QSoundEffect;//拾取金币的声音
           coin->setSource(QUrl("qrc:/audio/coin.wav"));
           coin->setLoopCount(0);//不循环
           coin->setVolume(.20f);

           this->shellkick = new QSoundEffect;//踩扁乌龟的的声音
           shellkick->setSource(QUrl("qrc:/audio/shellkick.wav"));
           shellkick->setLoopCount(0);//不循环
           shellkick->setVolume(.20f);

           this->stomp = new QSoundEffect;//踩扁栗子头的的声音
           stomp->setSource(QUrl("qrc:/audio/kick.wav"));
           stomp->setLoopCount(0);//不循环
           stomp->setVolume(.20f);

           this->wall = new QSoundEffect;//砖头碎掉的声音的声音
           wall->setSource(QUrl("qrc:/audio/breakblock.wav"));
          wall->setLoopCount(0);//不循环
           wall->setVolume(.20f);

           this->questionwall = new QSoundEffect;//问号砖头碎掉的声音的声音
          questionwall->setSource(QUrl("qrc:/audio/messageblockopen.wav"));
         questionwall->setLoopCount(0);//不循环
           questionwall->setVolume(.20f);

           this->gameover = new QSoundEffect;//gameover的声音
          gameover->setSource(QUrl("qrc:/audio/death.wav"));
         gameover->setLoopCount(0);//不循环
          gameover->setVolume(.20f);
}



void DJ::playsoundeffect(QString sound){
    if (sound == "theme")
    {
        theme->play();

    }
    if (sound == "jump")
    {
       cat_jump->play();


    }
    if(sound == "coin")
    {
        coin->play();
    }

    if(sound == "fireball")
    {
        fireball->play();
    }
    if(sound == "button")
    {
        button->play();
    }

    if(sound == "shellkick")
    {
        shellkick->play();
    }
    if(sound == "stomp")
    {
        stomp->play();
    }

    if(sound == "wall")
    {
        wall->play();
    }

    if(sound == "questionwall")
    {
        questionwall->play();
    }

    if(sound == "gameover")
    {
        gameover->play();
    }

    if(sound == "stop")
    {
        theme->stop();
    }

}

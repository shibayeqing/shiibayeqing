#ifndef DJ_H
#define DJ_H

#include <QMainWindow>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QDialog>
class DJ : public QDialog
{
public:
   DJ(QWidget *parent);
   QMediaPlayer* theme;

   QSoundEffect *coin, *cat_jump, *fireball, *button,*shellkick, *stomp, *wall, *questionwall, *gameover;


 public slots:
   void playsoundeffect(QString);
};

#endif // DJ_H

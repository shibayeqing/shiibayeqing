#ifndef cat_HEATH_H
#define cat_HEATH_H

#include <QMainWindow>
#include <QPixmap>
#include <config.h>
class cat_heath : public QMainWindow
{
    Q_OBJECT
public:
    explicit cat_heath(QWidget *parent = nullptr);
    int life=5;
    QPixmap m_life;
signals:

public slots:
};

#endif // cat_HEATH_H

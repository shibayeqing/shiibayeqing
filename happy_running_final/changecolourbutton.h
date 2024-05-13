#ifndef CHANGECOLOURBUTTON_H
#define CHANGECOLOURBUTTON_H

#include <QPushButton>

class Changecolourbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit Changecolourbutton(QWidget *parent = nullptr);
    QFont font;
    QString text ;
    QPixmap red;
    QPixmap yellow;
public slots: void changecolor();
};

#endif // CHANGECOLOURBUTTON_H

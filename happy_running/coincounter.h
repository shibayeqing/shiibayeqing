#ifndef COINCOUNTER_H
#define COINCOUNTER_H

#include <QMainWindow>

class CoinCounter : public QMainWindow
{
    Q_OBJECT
public:
    explicit CoinCounter(QWidget *parent = nullptr);
    int toatalcoin=0;
    QPixmap coincounterpic;
signals:

public slots:
};

#endif // COINCOUNTER_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFullscreen;
    QAction *actionABOUT_US;
    QAction *music;
    QAction *playagian;
    QAction *introduction;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(663, 477);
        actionFullscreen = new QAction(MainWindow);
        actionFullscreen->setObjectName(QStringLiteral("actionFullscreen"));
        actionABOUT_US = new QAction(MainWindow);
        actionABOUT_US->setObjectName(QStringLiteral("actionABOUT_US"));
        music = new QAction(MainWindow);
        music->setObjectName(QStringLiteral("music"));
        playagian = new QAction(MainWindow);
        playagian->setObjectName(QStringLiteral("playagian"));
        introduction = new QAction(MainWindow);
        introduction->setObjectName(QStringLiteral("introduction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(320, 210, 1450, 700));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 663, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(373, 87, 120, 76));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(actionABOUT_US);
        menu->addAction(introduction);
        menu_2->addSeparator();
        menu_2->addAction(music);
        menu_2->addAction(playagian);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionFullscreen->setText(QApplication::translate("MainWindow", "Fullscreen", Q_NULLPTR));
        actionABOUT_US->setText(QApplication::translate("MainWindow", "ABOUT US", Q_NULLPTR));
        music->setText(QApplication::translate("MainWindow", "\351\237\263\344\271\220\345\274\200\345\205\263", Q_NULLPTR));
        playagian->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", Q_NULLPTR));
        introduction->setText(QApplication::translate("MainWindow", "\347\216\251\346\263\225\344\273\213\347\273\215", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\233\264\345\244\232", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

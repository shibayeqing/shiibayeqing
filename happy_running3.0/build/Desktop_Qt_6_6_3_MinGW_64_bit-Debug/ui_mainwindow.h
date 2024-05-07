/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
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
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(663, 477);
        actionFullscreen = new QAction(MainWindow);
        actionFullscreen->setObjectName("actionFullscreen");
        actionABOUT_US = new QAction(MainWindow);
        actionABOUT_US->setObjectName("actionABOUT_US");
        music = new QAction(MainWindow);
        music->setObjectName("music");
        playagian = new QAction(MainWindow);
        playagian->setObjectName("playagian");
        introduction = new QAction(MainWindow);
        introduction->setObjectName("introduction");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(320, 210, 1450, 700));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 663, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(373, 87, 120, 76));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionFullscreen->setText(QCoreApplication::translate("MainWindow", "Fullscreen", nullptr));
        actionABOUT_US->setText(QCoreApplication::translate("MainWindow", "ABOUT US", nullptr));
        music->setText(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220\345\274\200\345\205\263", nullptr));
        playagian->setText(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        introduction->setText(QCoreApplication::translate("MainWindow", "\347\216\251\346\263\225\344\273\213\347\273\215", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\233\264\345\244\232", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

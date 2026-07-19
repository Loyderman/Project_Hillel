/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *exitBtn;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSlider *threadSlider;
    QLabel *threadCountLable;
    QTextEdit *resultTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1111, 741);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 211, 41));
        startBtn = new QPushButton(centralwidget);
        startBtn->setObjectName("startBtn");
        startBtn->setGeometry(QRect(530, 40, 161, 31));
        stopBtn = new QPushButton(centralwidget);
        stopBtn->setObjectName("stopBtn");
        stopBtn->setGeometry(QRect(790, 40, 141, 31));
        exitBtn = new QPushButton(centralwidget);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setGeometry(QRect(30, 450, 111, 31));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(280, 40, 161, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 220, 51, 16));
        threadSlider = new QSlider(centralwidget);
        threadSlider->setObjectName("threadSlider");
        threadSlider->setGeometry(QRect(90, 220, 501, 16));
        threadSlider->setOrientation(Qt::Orientation::Horizontal);
        threadCountLable = new QLabel(centralwidget);
        threadCountLable->setObjectName("threadCountLable");
        threadCountLable->setGeometry(QRect(640, 220, 131, 16));
        resultTextEdit = new QTextEdit(centralwidget);
        resultTextEdit->setObjectName("resultTextEdit");
        resultTextEdit->setGeometry(QRect(370, 430, 281, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1111, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \321\207\320\270\321\201\320\273\320\276, \321\211\320\276 \321\224 \320\272\321\226\320\275\321\206\320\265\320\274 \320\264\321\226\320\260\320\277\320\260\320\267\320\276\320\275\321\203 ", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "startBtn", nullptr));
        stopBtn->setText(QCoreApplication::translate("MainWindow", "stopBtn", nullptr));
        exitBtn->setText(QCoreApplication::translate("MainWindow", "exitBtn", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\202\320\276\320\272\320\270", nullptr));
        threadCountLable->setText(QCoreApplication::translate("MainWindow", "threadCountLable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

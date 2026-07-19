#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFutureWatcher>
#include <atomic>
#include "collatzh.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startBtn_clicked();
    void on_stopBtn_clicked();
    void on_exitBtn_clicked();
    void on_threadSlider_valueChanged(int value); // Оновлення тексту кількості потоків
    void onCalculationFinished();

private:
    Ui::MainWindow *ui;
    QFutureWatcher<CollatzResult> watcher;
    std::atomic_bool isStopRequested; // Прапорець для миттєвої зупинки розрахунків
};
#endif
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "collatzh.h"
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <thread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isStopRequested(false)
{
    ui->setupUi(this);


    ui->spinBox->setRange(1000000, 2000000000);
    ui->spinBox->setValue(1000000);


    int maxThreads = std::thread::hardware_concurrency();
    ui->threadSlider->setRange(1, maxThreads);
    ui->threadSlider->setValue(maxThreads);
    ui->threadCountLable->setText(QString("Потоки: %1").arg(maxThreads)); 


    ui->resultTextEdit->setReadOnly(true);


    ui->startBtn->setEnabled(true);
    ui->stopBtn->setEnabled(false);

    connect(&watcher, &QFutureWatcher<CollatzResult>::finished, this, &MainWindow::onCalculationFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_threadSlider_valueChanged(int value)
{
    ui->threadCountLable->setText(QString("Потоки: %1").arg(value));
}

void MainWindow::on_startBtn_clicked()
{
    std::uint64_t n = ui->spinBox->value();
    unsigned short int threads = ui->threadSlider->value();

    isStopRequested.store(false);


    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(true);
    ui->resultTextEdit->setText("Розрахунки запущено...");


    QFuture<CollatzResult> future = QtConcurrent::run(calculateCollatzPool, n, threads, std::ref(isStopRequested));
    watcher.setFuture(future);
}

void MainWindow::on_stopBtn_clicked()
{
    isStopRequested.store(true);
    ui->resultTextEdit->append("\nСпроба зупинки розрахунків...");
}

void MainWindow::on_exitBtn_clicked()
{
    isStopRequested.store(true);
    this->close();
}

void MainWindow::onCalculationFinished()
{

    ui->startBtn->setEnabled(true);
    ui->stopBtn->setEnabled(false);

    CollatzResult result = watcher.result();

    if (!result.errorMessage.isEmpty()) {
        ui->resultTextEdit->setText("Повідомлення: " + result.errorMessage);
        return;
    }


    QString report = QString(
                         "Число з найдовшим ланцюгом: %1\n"
                         "Довжина цього ланцюга: %2\n"
                         "Час затрачений на розрахунки: %3 мс."
                         )
                         .arg(result.bestNumber)
                         .arg(result.maxSteps)
                         .arg(result.elapsedTimeMs, 0, 'f', 2);

    ui->resultTextEdit->setText(report);
}

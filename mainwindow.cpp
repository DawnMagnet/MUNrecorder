#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_change()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::timer_change()
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->statusbar->showMessage(tr("当前时间:").append(current_date));
    ui->statusbar->repaint();
}

void MainWindow::on_exitButton_clicked(){ exit(0);}

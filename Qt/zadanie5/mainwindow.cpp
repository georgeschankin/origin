#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
    ui->l_valTime->setText(QString::number(s->getCurrentTime()) + " сек");
   ui->pB_Circle->setEnabled(s->isStart());

   connect(s, &StopWatch::sig_Start, this, &MainWindow::Start);
   connect(s, &StopWatch::sig_Stop, this, &MainWindow::Stop);
   connect(s, &StopWatch::sig_Clear, this, &MainWindow::Clear);
   connect(s, &StopWatch::sig_Circle, this, &MainWindow::Circle);
   connect(s->getQTimer(), &QTimer::timeout, this, &MainWindow::ShowTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pB_Start_Stop_clicked()
{
    if (!s->isStart())
        {
            s->Start();
            ui->pB_Start_Stop->setText("Стоп");
        }
        else
        {
            s->Stop();
            ui->pB_Start_Stop->setText("Старт");
        }
        ui->pB_Circle->setEnabled(s->isStart());
}


void MainWindow::on_pB_Clear_clicked()
{
    s->Clear();
}


void MainWindow::on_pB_Circle_clicked()
{
    s->countCircle();
}

void MainWindow::Start()
{

}

void MainWindow::Stop()
{

}

void MainWindow::Clear()
{
    ui->l_valTime->setText(QString::number(s->getCurrentTime()) + " сек");
    ui->textBrowser->clear();
}

void MainWindow::Circle()
{
    ui->textBrowser->append("Круг " + QString::number(s->getCurrentCircle()) + ", время: " +
                       QString::number(s->getCurrentTime() - s->getStartTime()) + " сек");
    s->setCircle(s->getCurrentCircle() + 1);
}

void MainWindow::ShowTime()
{
    if(s->isStart())
    {
        ui->l_valTime->setText(QString::number(s->getCurrentTime()) + " сек");
        s->setTime(s->getCurrentTime() + 0.1);
    }
}


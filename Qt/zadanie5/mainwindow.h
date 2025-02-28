#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QLabel>

#include "stopwatch.h"

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
    void on_pB_Start_Stop_clicked();

    void on_pB_Clear_clicked();

    void on_pB_Circle_clicked();

    void ShowTime();
    void Start();
    void Stop();
    void Clear();
    void Circle();

private:
    Ui::MainWindow *ui;
    StopWatch* s;
};
#endif // MAINWINDOW_H

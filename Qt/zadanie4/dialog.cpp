#include "dialog.h"
#include "ui_dialog.h"

#include <QStringList>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("Группа кнопок");
    ui->radioButton->setText("RB1");
    ui->radioButton_2->setText("RBB2");
    QStringList list = {"abc", "det", "qwy"};
    ui->listWidget->addItems(list);
    ui->radioButton->setCheckable(true);
    ui->radioButton_2->setCheckable(true);
    ui->progressBar->setMaximum(0);
    ui->progressBar->setMaximum(100);
    i = 0;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    i += 10;
    ui->progressBar->setValue(i);
    if(i >= 100) ui->progressBar->reset();
}


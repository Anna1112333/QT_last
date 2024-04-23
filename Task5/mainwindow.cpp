#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QListWidgetItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stw= new Stopwatch(this);
     this->setWindowTitle("Таймер кругов");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_t_toggled(bool checked)
{
    if(ui->pb_t->isChecked())
        ui->tbr->setStyleSheet("background-color: red");
    else
        ui->tbr->setStyleSheet("background-color: white");
}


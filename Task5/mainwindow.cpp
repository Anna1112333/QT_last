#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QListWidgetItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stw = new Stopwatch(this);
    this->setWindowTitle("Таймер кругов");
    ui->pb_ss->toggle();
    ui->pb_ss->setCheckable(true);

    ui->tbr->setText("Начало");
connect(stw, &Stopwatch::sig_to_mw_label
        , this, &MainWindow::get_string);   //параметры не пишутся
 connect (stw->time, &QTimer::timeout, this, &MainWindow::time_sl0);
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_t_toggled(bool checked)
{
    if(ui->pb_t->isChecked())
        ui->tbr->setStyleSheet("color: white; background-color: rgb(50,100,100)");
    else
        ui->tbr->setStyleSheet("background-color: white");
}


void MainWindow::time_sl0()
{
   ui->tbr->setText(Stopwatch::time_now);
}



void MainWindow::get_string(QString str)
{
   ui->tbr->setText("yjdsq"+str);
}

void MainWindow::on_pb_ss_toggled(bool agv)
{
    if(agv)        
    {
        ui->pb_ss->setText("стоп");
        stw->Stopwatch::SendSignal_string(agv);
    }
    else
        ui->pb_ss->setText("продолжить");
}


void MainWindow::on_pb_clear_clicked()
{
    //if(!ui->pb_clear->isChecked())
        ui->lb_time->setText("Время");
    ui->pb_ss->setText("старт");
}


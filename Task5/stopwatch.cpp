#include "Stopwatch.h"

Stopwatch::Stopwatch(QObject* parent):QObject{parent}
{
time0=new QTimer(this);
time00=new QTimer(this);
time = new QTimer(this);
time->setInterval(1);
startTimer(1000);
time0->setInterval(1000);
connect (time0, &QTimer::timeout, this, &Stopwatch::time_sl);
}


Stopwatch::~Stopwatch()
{
    qDebug()<<"Деструктор Stopwatch. ";
}

void Stopwatch::time_sl()
{
qDebug() << "Получен time_st";
int a, b, c, d;
    a=time21%1000; //milliseconds
    b=time21/1000%60; //seconds
    c=time21/60000%60; //minutes
    d=time21/3600000%60; //hours
    time1++; time21++;

 time_now=("Время после старта: "
                      +QString::number(d)+" "
                      +QString::number(c)+" "
                      +QString::number(b)+" "
                      +QString::number(a)+" "); 
}
void Stopwatch::SendSignal_string(bool agv)
{
   /* time0->start();
    Stopwatch::time_sl();
emit sig_to_mw_label(time_now);
    qDebug()<<"получен "<<time_now;*/
    int a, b, c, d;
        a=time21%1000; //milliseconds
        b=time21/1000%60; //seconds
        c=time21/60000%60; //minutes
        d=time21/3600000%60; //hours
    if(agv) {time->start();
       // ui->pb_ss->setText("Стоп");

   time_now0=("Время после старта: "
                         +QString::number(d)+" "
                         +QString::number(c)+" "
                         +QString::number(b)+" "
                         +QString::number(a)+" ");

    }
    else {time->stop();
       // ui->pb_ss->setText("Продолжить");
        time_now0=("Время после старта: "
                               +QString::number(d)+" "
                               +QString::number(c)+" "
                               +QString::number(b)+" "
                               +QString::number(a)+" ");
    }
}

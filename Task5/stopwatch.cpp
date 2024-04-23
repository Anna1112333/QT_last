#include "Stopwatch.h"

Stopwatch::Stopwatch(QObject* parent):QObject{parent}
{

}
Stopwatch::~Stopwatch()
{
    qDebug()<<"Деструктор Stopwatch. ";
}

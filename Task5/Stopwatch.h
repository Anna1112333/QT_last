#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QTimer>

class Stopwatch: public QObject
{
    Q_OBJECT
public:
explicit Stopwatch(QObject *parent = nullptr);

    ~Stopwatch();

    QTimer *tm;
};

#endif // STOPWATCH_H

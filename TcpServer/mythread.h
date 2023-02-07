#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QTcpSocket *s);
    void run();//继承自QThread的虚函数

signals:

private slots:
    void clientInfoSlot();

private:
    QTcpSocket *socket;
};

#endif // MYTHREAD_H

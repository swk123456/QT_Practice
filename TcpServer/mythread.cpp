#include "mythread.h"

myThread::myThread(QTcpSocket *s)
{
    socket = s;
}

void myThread::run()
{
    connect(socket, &QTcpSocket::readyRead, this, &myThread::clientInfoSlot);
}

//不能在其他类里操作页面
void myThread::clientInfoSlot()
{
    QString s = QString(socket->readAll());
    qDebug() << s;
    emit sendToWidget(s);//发送信号给widget
}

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    server = new QTcpServer;

    server->listen(QHostAddress::AnyIPv4, 8000);
    //客户端发起连接，server发出信号
    connect(server, &QTcpServer::newConnection, this, &Widget::newClientHandler);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newClientHandler()
{
    //建立TCP连接
    QTcpSocket *socket = server->nextPendingConnection();

    ui->lineEditIP->setText(socket->peerAddress().toString());
    ui->lineEditPort->setText(QString::number(socket->peerPort()));

    //收到消息,socket发出readyread信号
    //connect(socket, &QTcpSocket::readyRead, this, &Widget::clientInfoSlot);

    //启动线程
    myThread *t = new myThread(socket);
    t->start();

    //接受myThread中的信号
    connect(t, &myThread::sendToWidget, this, &Widget::threadSlot);
}

/*void Widget::clientInfoSlot()
{
    //获取信号的发出者
    QTcpSocket *s = (QTcpSocket *)sender();
    ui->textEdit->setText(QString(s->readAll()));
}*/

void Widget::threadSlot(QString s)
{
    ui->textEdit->append(s);
}

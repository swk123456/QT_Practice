#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket = new QTcpSocket;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonCancel_clicked()
{
    this->close();
}


void Widget::on_pushButtonConnect_clicked()
{
    //获取IP与端口
    QString ip = ui->lineEditIP->text();
    QString port = ui->lineEditPort->text();

    //连接服务器
    socket->connectToHost(QHostAddress(ip), port.toShort());

    //连接成功
    connect(socket, &QTcpSocket::connected, [this]()
    {
        QMessageBox::information(this, "连接提示", "连接服务器成功");

        this->hide();
        Chat *c = new Chat(socket);
        c->show();
    });

    //连接异常
    connect(socket, &QTcpSocket::disconnected, [this]()
    {
        QMessageBox::warning(this, "连接提示", "连接异常 网络断开");
    });
}


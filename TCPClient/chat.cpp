#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QTcpSocket *s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    socket = s;
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_pushButtonClear_clicked()
{
    ui->textEditLine->clear();
}


void Chat::on_pushButtonSend_clicked()
{
    QString message = ui->textEditLine->toPlainText();
    socket->write(message.toUtf8());
    ui->textEditLine->clear();
}


#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //连接信号与槽 谁发出信号 信号是什么  谁处理信号  怎么处理
    connect(ui ->lineEditOpen, SIGNAL(returnPressed()), this, SLOT(on_pushButtonYes_clicked()));
    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &Widget::on_pushButtonCancel_clicked);
    connect(ui->pushButtonBrowser, &QPushButton::clicked, [this]()
    {
        QMessageBox::information(this, "信息", "点击浏览");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonYes_clicked()
{
    //获取输入内容
    QLineEdit *lineEditOpen =  ui->lineEditOpen;
    QString str = lineEditOpen -> text();

    //打开
    QProcess *myProcess = new QProcess(this);
    myProcess ->start(str);
}


void Widget::on_pushButtonCancel_clicked()
{
    this ->close();
}


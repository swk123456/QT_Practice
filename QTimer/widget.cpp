#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer;

    picId = 0;
    showPicture();
    connect(timer, &QTimer::timeout, this, &Widget::timeoutSlot);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonStart_clicked()
{
    timer->start(TIMEOUT);
}

void Widget::timeoutSlot()
{
    picId++;
    picId %= 4;
    showPicture();
}

void Widget::showPicture()
{
    QString path = "E:\\QtCode\\objectTimer\\";
    path += QString::number(picId) + ".jpg";
    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void Widget::on_pushButtonStop_clicked()
{
    timer->stop();
}


void Widget::on_pushButtonSingle_clicked()
{
    //QTimer::singleShot(0, this, SLOT(timeoutSlot()));
    QTimer::singleShot(1000, this, SLOT(timeoutSlot()));
}


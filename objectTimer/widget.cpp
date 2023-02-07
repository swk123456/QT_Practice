#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->picSize = 4;//设置图片总数
    this->picId = 0;
    showPicture();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonStart_clicked()
{
    myTimerId = this->startTimer(TIMEOUT);//开始计时器
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == myTimerId)
    {
        this->picId++;
        this->picId %= this->picSize;

        showPicture();
    }
}

void Widget::showPicture()
{
    QString path("E:\\QtCode\\objectTimer\\");
    path += QString::number(picId) + ".jpg";

    QPixmap pix(path);
    ui->label->setPixmap(pix);
}

void Widget::on_pushButtonStop_clicked()
{
    this->killTimer(myTimerId);
}


#include "myimage.h"

MyImage::MyImage(QWidget *parent)
    : QWidget{parent}
{
    image.load(":/icon.png");
}

MyImage::~MyImage()
{

}

void MyImage::paintEvent(QPaintEvent *event)
{
    int width = this -> width();
    int height = this -> height();

    QPainter painter(this);
    painter.save();
    //调整图片大小为窗体大小
    image.scaled(width, height);

    //绘制图片
    painter.drawImage(this -> rect(), image);
    painter.restore();
    painter.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);

    //设置成正方形，最小大小为200*200
    //int side = qMin(width, height);
    //painter.scale(side/200, side/200);
}

void MyImage::setImage(QImage image)
{
    this -> image = image;
    update();
}

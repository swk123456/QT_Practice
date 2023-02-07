#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <QWidget>
#include <QPainter>
#include <QImage>

class MyImage : public QWidget
{
    Q_OBJECT
public:
    explicit MyImage(QWidget *parent = nullptr);
    ~MyImage();
    void setImage(QImage image);

protected:
    void paintEvent(QPaintEvent *event);//让图片随widget的大小自适应

private:
    QImage image;

signals:

};

#endif // MYIMAGE_H

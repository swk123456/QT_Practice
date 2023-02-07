#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#define TIMEOUT  1000//1秒

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void timerEvent(QTimerEvent *event);//继承过来的函数, event获取计时器编号
    ~Widget();

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

private:
    Ui::Widget *ui;
    int myTimerId;//计时器编号
    int picId;//图片编号
    int picSize;//图片总数

    void showPicture();
};
#endif // WIDGET_H

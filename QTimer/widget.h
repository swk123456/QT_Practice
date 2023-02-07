#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

#define TIMEOUT 1000

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonStop_clicked();
    void timeoutSlot();

    void on_pushButtonSingle_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer;
    int picId;

    void showPicture();
};
#endif // WIDGET_H

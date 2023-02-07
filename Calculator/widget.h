#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStack>
#include <string.h>

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
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButtonLeft_clicked();

    void on_pushButtonRight_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonSub_clicked();

    void on_pushButtonMul_clicked();

    void on_pushButtonDiv_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonEqual_clicked();

private:
    Ui::Widget *ui;
    QString expression;

    int Priority(char ch);
};
#endif // WIDGET_H

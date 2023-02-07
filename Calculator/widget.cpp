#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_1_clicked()
{
    expression += "1";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButton_2_clicked()
{
    expression += "2";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButton_3_clicked()
{
    expression += "3";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButton_4_clicked()
{
    expression += "4";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButton_5_clicked()
{
    expression += "5";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButton_6_clicked()
{
    expression += "6";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButton_7_clicked()
{
    expression += "7";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButton_8_clicked()
{
    expression += "8";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButton_9_clicked()
{
    expression += "9";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButton_0_clicked()
{
    expression += "0";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButtonLeft_clicked()
{
    expression += "(";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButtonRight_clicked()
{
    expression += ")";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButtonAdd_clicked()
{
    expression += "+";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButtonSub_clicked()
{
    expression += "-";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButtonMul_clicked()
{
    expression += "*";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButtonDiv_clicked()
{
    expression += "/";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_pushButtonClear_clicked()
{
    expression.clear();
    ui->mainLineEdit->clear();
}


void Widget::on_pushButtonDelete_clicked()
{
    expression.chop(1);
    ui->mainLineEdit->setText(expression);
}


int Widget::Priority(char ch)
{
    switch(ch)
    {
    case '(':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void Widget::on_pushButtonEqual_clicked()
{
    QStack<int> s_num, s_opt;

    char opt[128] = {0};
    int i = 0, tmp = 0, num1, num2;

    QByteArray ba = expression.toLatin1();
    strcpy(opt, ba.data());

    while(opt[i] != 0 || !s_opt.empty()) {
        if(opt[i] >= '0' && opt[i] <= '9') {
            tmp = tmp * 10 + opt[i] - '0';
            i++;
            if(opt[i] < '0' || opt[i] > '9') {
                s_num.push(tmp);
                tmp = 0;
            }
        } else {
            if(s_opt.empty() || Priority(opt[i]) > Priority(s_opt.top()) || (s_opt.top() == '(' && opt[i] != ')'))
            {
                s_opt.push(opt[i]);
                i++;
                continue;
            }
            if(s_opt.top() == '(' && opt[i] == ')')
            {
                s_opt.pop();
                i++;
                continue;
            }
            if(Priority(opt[i]) <= Priority(s_opt.top()) || (opt[i] ==')' && s_opt.top() != ')') || (opt[i] == '\0' && !s_opt.empty()))
            {
                char ch = s_opt.top();
                s_opt.pop();
                switch(ch)
                {
                case '+':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1 + num2);
                    break;
                case '-':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num2 - num1);
                    break;
                case '*':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1 * num2);
                    break;
                case '/':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num2 / num1);
                    break;
                }
            }
        }
    }
    ui->mainLineEdit->setText(QString::number(s_num.top()));
    expression = QString::number(s_num.top());
}

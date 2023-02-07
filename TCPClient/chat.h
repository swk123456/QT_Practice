#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QTcpSocket *s, QWidget *parent = nullptr);
    ~Chat();

private slots:
    void on_pushButtonClear_clicked();

    void on_pushButtonSend_clicked();

private:
    Ui::Chat *ui;
    QTcpSocket *socket;
};

#endif // CHAT_H

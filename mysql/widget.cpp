#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //连接数据库
    /*//本地数据库
    db = QSqlDatabase::addDatabase("QMYSQL");//加载MYSQL数据库驱动
    db.setDatabaseName("login_test");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");*/
    //远程数据库
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ubuntu20.04");//ODBC中配置的名字
    db.setHostName("192.168.10.12");
    db.setUserName("test1");
    db.setPassword("test1");

    if(db.open()){
        QMessageBox::information(this, "连接提示", "连接成功");

        m = new QSqlTableModel;
        m->setTable("user");
        ui->tableView->setModel(m);

    } else {
        QMessageBox::warning(this, "连接提示", "连接失败");
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonInsert_clicked()
{
    QString id = ui->lineEditID->text();
    QString name = ui->lineEditName->text();
    QString password = ui->lineEditPassword->text();

    QString sql = QString("insert into user values('%1','%2', '%3');").arg(id).arg(name).arg(password);

    QSqlQuery query;
    if(query.exec(sql)) {
        QMessageBox::information(this, "插入提示", "插入成功");
    } else {
        QMessageBox::information(this, "插入提示", "插入失败");
    }
}


void Widget::on_pushButtonSearch_clicked()
{
    m->select();
    /*ui->textEditSearch->clear();
    QSqlQuery query;
    query.exec("select * from user;");
    while(query.next()) {
        QString s = "ID:" + query.value(0).toString() + "  用户名:" + query.value(1).toString() + "  密码:" + query.value(2).toString();
        ui->textEditSearch->append(s);
    }*/
}

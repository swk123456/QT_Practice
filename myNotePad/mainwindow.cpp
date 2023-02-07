#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mBar = menuBar();
    initBar();

    connect(pNew, &QAction::triggered, this, &MainWindow::newActionSlot);
    connect(pOpen, &QAction::triggered, this, &MainWindow::openActionSlot);
    connect(pSave, &QAction::triggered, this, &MainWindow::saveActionSlot);
}

void MainWindow::initBar()
{
    QMenu *pFile = mBar->addMenu("文件(&F)");
    pNew = pFile->addAction("新建(&N)");
    pOpen = pFile->addAction("打开(&O)");
    pSave = pFile->addAction("另存为(&S)");

    QMenu *pEdit = mBar->addMenu("编辑(&E)");

    QMenu *pBuild = mBar->addMenu("构建(&B)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newActionSlot()
{
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档.txt");
}

void MainWindow::openActionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开"), QCoreApplication::applicationFilePath(), "*.*");
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this, "警告", "请选择一个文件");
    } else {
        qDebug() << fileName;//调试信息输出
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        ui->textEdit->setText(QString(ba));
        file.close();
    }
}

void MainWindow::saveActionSlot()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), QCoreApplication::applicationFilePath());
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this, "警告", "请选择一个文件");
    } else {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QByteArray ba = ui->textEdit->toPlainText().toUtf8();
        file.write(ba);
        file.close();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *kEvent)//键盘事件
{
    if(kEvent->modifiers() == Qt::ControlModifier && kEvent->key() == Qt::Key_S)//ctrl+S保存文件
    {
        saveActionSlot();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *mEvent)
{
    QPoint pt = mEvent->pos();
    qDebug() << pt;

    if(mEvent->button() == Qt::LeftButton) {
        qDebug() << "leftButton press";
    } else if(mEvent->button() == Qt::RightButton) {
        qDebug() << "rightButton press";
    }
}

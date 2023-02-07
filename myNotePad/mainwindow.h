#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *kEvent);
    void mousePressEvent(QMouseEvent *mEvent);

private slots:
    void newActionSlot();
    void openActionSlot();
    void saveActionSlot();

private:
    Ui::MainWindow *ui;
    QMenuBar *mBar;
    QAction *pNew;
    QAction *pOpen;
    QAction *pSave;

    void initBar();
};
#endif // MAINWINDOW_H

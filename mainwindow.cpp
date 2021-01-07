#include "MainWindow.h"
#include "ui_mainwindow.h"

#include "QPixmap"
#include "QApplication"
#include "QDesktopWidget"
#include <QList>
#include <QScreen>
#include "QPainter"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QDesktopWidget* dw = QApplication::desktop();
    QPixmap pixmap = QPixmap::grabWindow(dw->winId(), 0, 0,
                                         dw->width(), dw->height());
    pixmap.save(name, "JPG", screenshot_quality);

}

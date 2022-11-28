#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

#include "dialog.h"
#include "secdialog.h"

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



void MainWindow::on_pushButton_3_clicked()
{
    QApplication::quit();
}




void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Dialog dialoG;
    dialoG.setModal(true);
    dialoG.exec();
    show();
}




void MainWindow::on_pushButton_clicked()
{
  hide();
  secdialog secdialoG;
  secdialoG.setModal(true);
  secdialoG.exec();
  show();
}


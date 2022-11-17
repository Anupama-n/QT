#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Lz77");
    ui->comboBox->addItem("hauffman");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString file_name=QFileDialog::getOpenFileName(this,"Open a file","C://");
    QMessageBox::information(this,"..",file_name);

}


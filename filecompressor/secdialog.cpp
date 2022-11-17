#include "secdialog.h"
#include "ui_secdialog.h"
#include <QFileDialog>
#include <QMessageBox>


secdialog::secdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secdialog)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Lz77");
    ui->comboBox->addItem("hauffman");
}

secdialog::~secdialog()
{
    delete ui;
}

void secdialog::on_pushButton_clicked()
{
    QString file_name=QFileDialog::getOpenFileName(this,"Open a file","C://");
    QMessageBox::information(this,"..",file_name);
}


#include "secdialog.h"
#include "ui_secdialog.h"

secdialog::secdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secdialog)
{
    ui->setupUi(this);
}

secdialog::~secdialog()
{
    delete ui;
}

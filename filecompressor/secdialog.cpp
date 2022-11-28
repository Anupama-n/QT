#include "secdialog.h"
#include "ui_secdialog.h"
#include <QFileDialog>
#include <QMessageBox>


secdialog::secdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secdialog)
{
    ui->setupUi(this);
    ui->comboBox->addItem("LZ77");
    ui->comboBox->addItem("Huffman");
}


secdialog::~secdialog()
{
    delete ui;
}

void secdialog::getOriginalFileName(){
    std::string fileName = getFileName(inFile.toLocal8Bit().constData());
    std::string ogFileName = fileName.substr(0,fileName.size()-4);
    outFile+=QString::fromLocal8Bit("/");
    outFile+=QString::fromLocal8Bit(ogFileName);
}

void secdialog::on_pushButton_clicked()
{
    QString file_name=QFileDialog::getOpenFileName(this,"Open compressed file","C:\\");
    if(!file_name.isEmpty()){
        if(!file_name.contains(".jwc")){
            QMessageBox::warning(this,"JWC","Unknown file typed opened.\nPlease Open a \".jwc\"file");
            return;
        }
        inFile = file_name;
        ui->inputPath->setText(inFile);
        ui->inputPath->setAlignment(Qt::AlignmentFlag::AlignCenter);
    }else{
        QMessageBox::warning(this,"JWC","Please Select A Valid File.");
    }
}

void secdialog::on_pushButton_3_clicked()
{
    QString file_name=QFileDialog::getExistingDirectory(this,"Select directory for Decompressed file.","C:\\");
    if(!file_name.isEmpty()){
        outFile = file_name;
        ui->outputName->setText(outFile);
        ui->outputName->setAlignment(Qt::AlignmentFlag::AlignCenter);
    }else{
        QMessageBox::warning(this,"JWC","Please Select A Valid File.");
    }
}

void secdialog::clearFilePaths(){
    inFile = "";
    outFile = "";
}
void secdialog::on_pushButton_2_clicked(){
    if(inFile.isEmpty()|| outFile.isEmpty()){
        QMessageBox::information(this,"JWC","Please Select Files before proceeding");
    }
    else{
        qInfo()<<"Decompressing...";
        getOriginalFileName();
        qInfo()<<inFile;
        qInfo()<<outFile;
        if(ui->comboBox->currentText()=="LZ77")
        {
            decompress(inFile.toLocal8Bit().constData(),outFile.toLocal8Bit().constData());

        }else if(ui->comboBox->currentText()=="Huffman")
        {
            huffman decoder(inFile.toLocal8Bit().constData(),outFile.toLocal8Bit().constData());
            decoder.recreate_huffman_tree();
            decoder.decoding_s();
        }
        QMessageBox::information(this,"JWC","Decompression Finished.");
    }

    clearFilePaths();

}

void secdialog::on_backButton_clicked(){
    close();
}


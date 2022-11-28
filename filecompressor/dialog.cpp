#include "dialog.h"

#include <ui_dialog.h>
#include <QFileDialog>

#include <QMessageBox>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    setWindowTitle("Compress File");
    ui->setupUi(this);
    ui->comboBox->addItem("LZ77");
    ui->comboBox->addItem("Huffman");
}

Dialog::~Dialog()
{
    delete ui;

}

void Dialog::getCompressedFileName(){
    std::string name_ = getFileName(inFile.toLocal8Bit().constData());
    QString Qname = QString::fromLocal8Bit(name_);
    outFile+=QString::fromLocal8Bit("/");
    outFile+=Qname;
    outFile+=QString::fromLocal8Bit(".jwc");
}

void Dialog::clearFilePaths(){
    inFile = "";
    outFile = "";
}

//on input file button being clicked
void Dialog::on_pushButton_clicked()
{
    QString file_name=QFileDialog::getOpenFileName(this,"Open a file","C:\\");
    if(!file_name.isEmpty()){
      inFile = file_name;
      ui->inputPath->setText(inFile);
      ui->inputPath->setAlignment(Qt::AlignmentFlag::AlignCenter);
    }else{
        QMessageBox::warning(this,"JWC","Please Select A Valid File.");
    }

}

//on output file button being clicked.
void Dialog::on_pushButton_3_clicked()
{

    QString file_name=QFileDialog::getExistingDirectory(this,"Select directory to store compressed file.","C:\\");
    if(!file_name.isEmpty()){
        outFile = file_name;
        ui->outputName->setText(outFile);
        ui->outputName->setAlignment(Qt::AlignmentFlag::AlignCenter);
    }else{
        QMessageBox::warning(this,"JWC","Please Select A Valid File.");
    }

}

//on compress button being clicked.
void Dialog::on_pushButton_2_clicked(){
    if(inFile.isEmpty()|| outFile.isEmpty()){
        QMessageBox::information(this,"JWC","Please Select Files before proceeding");
    }
    else{
        getCompressedFileName();
        qInfo()<<"Compressing...";
        qInfo()<<inFile;
        qInfo()<<outFile;
        if(ui->comboBox->currentText()=="LZ77")
        {
            compress(inFile.toLocal8Bit().constData(),outFile.toLocal8Bit().constData());
        }else if(ui->comboBox->currentText()=="Huffman")
        {

            huffman compressor(inFile.toLocal8Bit().constData(),outFile.toLocal8Bit().constData());
            compressor.create_pq();
            compressor.create_huffman_tree();
            compressor.huffman_codes();
            compressor.encoding_s();
        }
        QMessageBox::information(this,"JWC","Compression Finished.");
    }

    clearFilePaths();

}
void Dialog::on_backButton_clicked(){
    close();
}


#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "include/LZ77.hpp"
#include "include/misc.hpp"
#include "include/huffman.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
private:
       QString inFile;
       QString outFile;
       void getCompressedFileName();
       void clearFilePaths();

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked(); //input file
    void on_pushButton_3_clicked(); //output file
    void on_pushButton_2_clicked(); //compression
    void on_backButton_clicked();


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

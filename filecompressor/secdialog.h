#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include "include/LZ77.hpp"
#include "include/misc.hpp"
#include "include/huffman.h"

namespace Ui {
class secdialog;
}

class secdialog : public QDialog
{
    Q_OBJECT
private:
       QString inFile;
       QString outFile;
       void getOriginalFileName();
       void clearFilePaths();


public:
    explicit secdialog(QWidget *parent = nullptr);
    ~secdialog();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_backButton_clicked();

private:
    Ui::secdialog *ui;
};

#endif // SECDIALOG_H

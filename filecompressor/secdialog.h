#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

namespace Ui {
class secdialog;
}

class secdialog : public QDialog
{
    Q_OBJECT

public:
    explicit secdialog(QWidget *parent = nullptr);
    ~secdialog();

private:
    Ui::secdialog *ui;
};

#endif // SECDIALOG_H

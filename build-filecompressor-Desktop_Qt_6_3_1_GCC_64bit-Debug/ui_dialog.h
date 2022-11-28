/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QLabel *description_;
    QComboBox *comboBox;
    QLabel *Algorithm_;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *inputPath;
    QLabel *outputName;
    QPushButton *backButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(422, 367);
        Dialog->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 160, 80, 25));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220)"));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        description_ = new QLabel(Dialog);
        description_->setObjectName(QString::fromUtf8("description_"));
        description_->setGeometry(QRect(20, 60, 381, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        font.setBold(true);
        description_->setFont(font);
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(140, 260, 131, 21));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 238);\n"
"alternate-background-color: rgb(171, 171, 171);"));
        Algorithm_ = new QLabel(Dialog);
        Algorithm_->setObjectName(QString::fromUtf8("Algorithm_"));
        Algorithm_->setGeometry(QRect(20, 260, 91, 21));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 320, 90, 25));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220)"));
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 210, 81, 25));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220)"));
        inputPath = new QLabel(Dialog);
        inputPath->setObjectName(QString::fromUtf8("inputPath"));
        inputPath->setGeometry(QRect(140, 160, 230, 25));
        inputPath->setFocusPolicy(Qt::StrongFocus);
        inputPath->setAutoFillBackground(false);
        inputPath->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 229, 229); color : black;\n"
"border-color: rgb(20, 20, 20);"));
        outputName = new QLabel(Dialog);
        outputName->setObjectName(QString::fromUtf8("outputName"));
        outputName->setGeometry(QRect(140, 210, 230, 25));
        outputName->setFocusPolicy(Qt::StrongFocus);
        outputName->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 229, 229); color : black;\n"
"border-color: rgb(20, 20, 20);"));
        outputName->setWordWrap(true);
        backButton = new QPushButton(Dialog);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(30, 320, 90, 25));
        backButton->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220)"));

        retranslateUi(Dialog);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Input File", nullptr));
        description_->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; color:#0f0f0f;\">Choose Compression Algorithm</span></p></body></html>", nullptr));
        comboBox->setCurrentText(QString());
        Algorithm_->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Algorithm:</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "Compress", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dialog", "Output File", nullptr));
        inputPath->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt; font-style:italic;\">No File Selected</span></p></body></html>", nullptr));
        outputName->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt; font-style:italic;\">No Directory Selected</span></p></body></html>", nullptr));
        backButton->setText(QCoreApplication::translate("Dialog", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

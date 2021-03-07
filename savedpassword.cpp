#include "savedpassword.h"
#include "ui_savedpassword.h"
#include <iostream>
#include <fstream>
#include "savefile.h"
#include <QFile>
#include <QFileDialog>

QString readFile(QString file);

SavedPassword::SavedPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SavedPassword)
{
    ui->setupUi(this);
}

SavedPassword::~SavedPassword()
{
    delete ui;
}

void SavedPassword::on_okBtn_clicked()
{
    accept();
}

void SavedPassword::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/Saved/", tr("Data files (*.sec)"));

    if (fileName == NULL) return;

    ui->selectedFileName->setText(fileName);

    QString data = "";

    QFile file(fileName);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        data += file.readAll();
        file.close();
    }

    std::string unlkData = SaveFile::encryptDecrypt(data.toUtf8().constData());
    std::cout << unlkData << std::endl;
    QList strings = QString::fromUtf8(unlkData.c_str()).split('\n');

    QString pass = strings[2].split(' ')[1];
    QString password = "";
    for (int i = 0; i < pass.length(); i++) {
        password += pass[i];
    }

    ui->websiteLE->setText(strings[0].split(' ')[1]);
    ui->loginLE->setText(strings[1].split(' ')[1]);
    ui->passwordLE->setText(password);
}

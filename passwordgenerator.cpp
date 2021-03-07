#include "passwordgenerator.h"
#include "ui_passwordgenerator.h"
#include "generator.h"
#include "dialogisempty.h"
#include "savefileui.h"
#include <QFileDialog>
#include "savedpassword.h"

PasswordGenerator::PasswordGenerator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PasswordGenerator)
{
    ui->setupUi(this);
}

PasswordGenerator::~PasswordGenerator()
{
    delete ui;
}

void PasswordGenerator::on_GenerateBtn_clicked()
{
    if (ui->OutputTB->toPlainText().length() > 0) ui->OutputTB->clear();

    if (ui->AcronymGenerationRB->isChecked()) {
        if (!(ui->acronymTextInput->toPlainText() > 0)) {
            DialogIsEmpty emptyDlg;
            emptyDlg.exec();
            return;
        }

        QString text = ui->acronymTextInput->toPlainText();
        QStringList words = text.replace('\n', ' ').split(' ');
        QString acrSymbols;

        for (int i = 0; i <= words.length() - 1; i++) {
            QString word = words[i];
            QChar nextChar = word.at(0);
            acrSymbols.append(nextChar);
        }

        QString outputData = "Generated password: " + acrSymbols;

        ui->OutputTB->insertPlainText(outputData);
    }

    if (ui->DefaultGenerationRB->isChecked()) {
        QString symbols;
        if (ui->specSymbols->isChecked()) symbols = PasswordGenerator::symbolsSpec;
        else symbols = PasswordGenerator::symbols;

        int lenght = ui->lenghtLB->value();

        QString result = GeneratePassword(lenght, symbols);

        QString outputData = "Generated password: " + result;

        ui->OutputTB->insertPlainText(outputData);
    }

    if (ui->OutputTB->toPlainText().length() > 0) ui->saveToFileBtn->setEnabled(true);
}

void PasswordGenerator::on_DefaultGenerationRB_clicked()
{
    if (ui->DefaultGenerationRB->isChecked()) {
        ui->acronymTextInput->setDisabled(true);
        ui->specSymbols->setEnabled(true);
        ui->lenghtLB->setEnabled(true);
    }
}

void PasswordGenerator::on_AcronymGenerationRB_clicked()
{
    if (ui->AcronymGenerationRB->isChecked()) {
        ui->acronymTextInput->setEnabled(true);
        ui->specSymbols->setDisabled(true);
        ui->lenghtLB->setDisabled(true);
    }
}

void PasswordGenerator::on_clearOutputBtn_clicked()
{
    ui->OutputTB->clear();
    ui->saveToFileBtn->setDisabled(true);
}

void PasswordGenerator::on_clearInputBtn_clicked()
{
    ui->acronymTextInput->clear();
}

void PasswordGenerator::on_saveToFileBtn_clicked()
{
    SaveFileUI *saveFile = new SaveFileUI();
    QList password = ui->OutputTB->toPlainText().split(' ');
    saveFile->setPassword(password[2]);
    saveFile->exec();
}

void PasswordGenerator::on_acronymTextInput_textChanged()
{
    if (!(ui->acronymTextInput->toPlainText().length() > 0)) ui->clearInputBtn->setDisabled(true);
    else ui->clearInputBtn->setEnabled(true);
}

void PasswordGenerator::on_OutputTB_textChanged()
{
    if (!(ui->OutputTB->toPlainText().length() > 0)) ui->clearOutputBtn->setDisabled(true);
    else ui->clearOutputBtn->setEnabled(true);
}

void PasswordGenerator::on_readSavePass_clicked()
{
    SavedPassword *saved = new SavedPassword();
    saved->exec();
}

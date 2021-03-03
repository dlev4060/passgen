#include "passwordgenerator.h"
#include "ui_passwordgenerator.h"
#include "Generator.cpp"
#include "dialogisempty.h"

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

bool lowercase = false;
bool uppercase = false;
QString outputData;

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

        if (lowercase) outputData = "Generated password: " + acrSymbols.toLower();
        if (uppercase) outputData = "Generated password: " + acrSymbols.toUpper();
        else outputData = "Generated password: " + acrSymbols;

        ui->OutputTB->insertPlainText(outputData);
    }

    if (ui->DefaultGenerationRB->isChecked()) {
        QString symbols;
        if (ui->specSymbols->isChecked()) symbols = PasswordGenerator::symbolsSpec;
        else symbols = PasswordGenerator::symbols;

        int lenght = ui->lenghtLB->value();

        QString result = GeneratePassword(lenght, symbols);

        if (lowercase) outputData = "Generated password: " + result.toLower();
        else if (uppercase) outputData = "Generated password: " + result.toUpper();
        else outputData = "Generated password: " + result;

        ui->OutputTB->insertPlainText(outputData);
    }
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

void PasswordGenerator::on_lowercaseGeneration_clicked()
{
    lowercase = true;
}

void PasswordGenerator::on_uppercaseSymbolsRB_clicked()
{
    lowercase = false;
    uppercase = true;
}

void PasswordGenerator::on_defaultGenerationRB_clicked()
{
    lowercase = false;
    uppercase = false;
}

void PasswordGenerator::on_clearOutputBtn_clicked()
{
    ui->OutputTB->clear();
}

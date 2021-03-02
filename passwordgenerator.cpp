#include "passwordgenerator.h"
#include "ui_passwordgenerator.h"
#include "Generator.cpp"

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
        QString text = ui->acronymTextInput->toPlainText();
        QStringList words = text.split(' ');
        QString acrSymbols;

        for (int i = 0; i <= words.length() - 1; i++) {
            QString word = words[i];
            QChar nextChar = word.at(0);
            acrSymbols.append(nextChar);
        }

        ui->OutputTB->insertPlainText(acrSymbols);
    }

    if (ui->DefaultGenerationRB->isChecked()) {
        QString symbols;
        if (ui->specSymbols->isChecked()) symbols = PasswordGenerator::symbolsSpec;
        else symbols = PasswordGenerator::symbols;

        int lenght = ui->lenghtLB->value();

        QString result = GeneratePassword(lenght, symbols);
        ui->OutputTB->insertPlainText(result);
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

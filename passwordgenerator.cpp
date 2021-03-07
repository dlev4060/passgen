#include "passwordgenerator.h"
#include "ui_passwordgenerator.h"
#include "generator.h"
#include "dialogisempty.h"
#include "savefileui.h"
#include <QFileDialog>
#include "savedpassword.h"
#include "passwordrequipments.h"

QString sustainability(std::string password);

PasswordGenerator::PasswordGenerator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PasswordGenerator)
{
    ui->setupUi(this);
    connect(this, &PasswordGenerator::on_PasswordGenerated, this, &PasswordGenerator::on_PasswordGeneratedSlot);
}

PasswordGenerator::~PasswordGenerator()
{
    delete ui;
}

void PasswordGenerator::on_PasswordGeneratedSlot(QString password) {
    if (password == "weak") {
        ui->sustainabilityLabel->setText("Weak password");
        ui->sustainabilityLabel->setStyleSheet("font-size: 20px; color: red");
    }
    else if (password == "middle") {
        ui->sustainabilityLabel->setText("Middle password");
        ui->sustainabilityLabel->setStyleSheet("font-size: 20px; color: Gold");
    }
    else if (password == "strong") {
        ui->sustainabilityLabel->setText("Strong password");
        ui->sustainabilityLabel->setStyleSheet("font-size: 20px; color: LightGreen");
    }
    else if (password == "very_strong") {
        ui->sustainabilityLabel->setText("Very strong password");
        ui->sustainabilityLabel->setStyleSheet("font-size: 20px; color: Green");
    }
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

        QString sustainabilityPassword = sustainability(acrSymbols.toUtf8().constData());
        emit on_PasswordGenerated(sustainabilityPassword);
    }

    if (ui->DefaultGenerationRB->isChecked()) {
        QString symbols;
        if (ui->specSymbols->isChecked()) symbols = PasswordGenerator::symbolsSpec;
        else symbols = PasswordGenerator::symbols;

        int lenght = ui->lenghtLB->value();

        QString result = GeneratePassword(lenght, symbols);

        QString outputData = "Generated password: " + result;

        ui->OutputTB->insertPlainText(outputData);

        QString sustainabilityPassword = sustainability(result.toUtf8().constData());
        emit on_PasswordGenerated(sustainabilityPassword);
    }

    if (ui->OutputTB->toPlainText().length() > 0) ui->actionSave_password->setEnabled(true);
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
    ui->actionSave_password->setDisabled(true);
}

void PasswordGenerator::on_clearInputBtn_clicked()
{
    ui->acronymTextInput->clear();
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

void PasswordGenerator::on_actionSave_password_triggered()
{
    SaveFileUI *saveFile = new SaveFileUI();
    QList password = ui->OutputTB->toPlainText().split(' ');
    saveFile->setPassword(password[2]);
    saveFile->exec();
}

void PasswordGenerator::on_actionRead_saved_password_triggered()
{
    SavedPassword *saved = new SavedPassword();
    saved->exec();
}

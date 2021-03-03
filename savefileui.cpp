#include "savefileui.h"
#include "ui_savefileui.h"
#include "savefile.h"

SaveFileUI::SaveFileUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveFileUI)
{
    ui->setupUi(this);
}

SaveFileUI::~SaveFileUI()
{
    delete ui;
}


/*void SaveFileUI::on_buttonBox_accepted()
{
    if (!(ui->webSiteLE->text().length() > 0 || !(ui->loginLE->text().length() > 0))) {

    }

    saveFile(
            ui->webSiteLE->text(),
            ui->loginLE->text(),
            password.toUtf8().constData()
    );
    //const char* lol = password.toStdString().c_str();

    printf("%s\n", password.toUtf8().constData());

    accept();
}

void SaveFileUI::on_buttonBox_rejected()
{
    reject();
}*/

void SaveFileUI::on_saveBtn_clicked()
{
    saveFile(
            ui->webSiteLE->text(),
            ui->loginLE->text(),
            password.toUtf8().constData()
    );

    printf("%s\n", password.toUtf8().constData());

    accept();
}

void SaveFileUI::on_cancelBtn_clicked()
{
    reject();
}

void SaveFileUI::on_webSiteLE_textEdited(const QString &arg1)
{
    if (ui->webSiteLE->text().length() > 0 && ui->loginLE->text().length() > 0)
        ui->saveBtn->setEnabled(true);
    else ui->saveBtn->setDisabled(true);
}

void SaveFileUI::on_loginLE_textEdited(const QString &arg1)
{
    if (ui->webSiteLE->text().length() > 0 && ui->loginLE->text().length() > 0)
        ui->saveBtn->setEnabled(true);
    else ui->saveBtn->setDisabled(true);
}

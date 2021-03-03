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


void SaveFileUI::on_buttonBox_accepted()
{
    saveFile(
            ui->webSiteLE->text(),
            ui->loginLE->text(),
            password.toUtf8().constData()
    );

    printf("%s\n", password.toUtf8().constData());

    accept();
}

void SaveFileUI::on_buttonBox_rejected()
{
    reject();
}

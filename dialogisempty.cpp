#include "dialogisempty.h"
#include "ui_dialogisempty.h"

DialogIsEmpty::DialogIsEmpty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogIsEmpty)
{
    ui->setupUi(this);
    setModal(true);                 // this dialog should be modal
    setWindowFlags(Qt::Window);
}

DialogIsEmpty::~DialogIsEmpty()
{
    delete ui;
}

void DialogIsEmpty::on_pushButton_clicked()
{
    accept();
}

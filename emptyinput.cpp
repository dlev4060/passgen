#include "emptyinput.h"
#include "ui_passwordgenerator.h"
#include "Generator.cpp"

EmptyInput::EmptyInput(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmptyInput)
{
    ui->setupUi(this);
}

EmptyInput::~EmptyInput()
{
    delete ui;
}

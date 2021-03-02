#ifndef EMPTYINPUT_H
#define EMPTYINPUT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EmptyInput; }
QT_END_NAMESPACE

class EmptyInput : public QWidget
{
    Q_OBJECT

public:
    EmptyInput(QWidget *parent = nullptr);
    ~EmptyInput();

private slots:


private:
    Ui::EmptyInput *ui;
};

#endif // EMPTYINPUT_H

#ifndef DIALOGISEMPTY_H
#define DIALOGISEMPTY_H

#include <QDialog>

namespace Ui {
class DialogIsEmpty;
}

class DialogIsEmpty : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIsEmpty(QWidget *parent = nullptr);
    ~DialogIsEmpty();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogIsEmpty *ui;
};

#endif // DIALOGISEMPTY_H

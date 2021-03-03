#ifndef SAVEFILEUI_H
#define SAVEFILEUI_H

#include <QDialog>

namespace Ui {
class SaveFileUI;
}

class SaveFileUI : public QDialog
{
    Q_OBJECT

public:
    explicit SaveFileUI(QWidget *parent = nullptr);
    ~SaveFileUI();

    void setPassword(QString pass) {
        password = pass;
    }

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::SaveFileUI *ui;

    QString password;
};

#endif // SAVEFILEUI_H

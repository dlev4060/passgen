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
    void on_saveBtn_clicked();

    void on_cancelBtn_clicked();

    void on_webSiteLE_textEdited(const QString &arg1);

    void on_loginLE_textEdited(const QString &arg1);

private:
    Ui::SaveFileUI *ui;

    QString password;
};

#endif // SAVEFILEUI_H

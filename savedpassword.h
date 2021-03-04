#ifndef SAVEDPASSWORD_H
#define SAVEDPASSWORD_H

#include <QDialog>

void showData();

namespace Ui {
class SavedPassword;
}

class SavedPassword : public QDialog
{
    Q_OBJECT

public:
    Ui::SavedPassword *ui;

    explicit SavedPassword(QWidget *parent = nullptr);
    ~SavedPassword();

    void setFileName(QString name) {
        fileName = name;
    }

    void setWebSite(QString site) {
        webSite = site;
    }

    void setLogin(QString usrLogin) {
        login = usrLogin;
    }

    void setPassword(QString pass) {
        password = pass;
    }

    QString getFileName() {
        return fileName;
    }

private slots:
    void on_okBtn_clicked();

    void on_pushButton_clicked();

private:
    QString fileName;
    QString webSite;
    QString login;
    QString password;
};

#endif // SAVEDPASSWORD_H

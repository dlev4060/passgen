#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <iostream>
#include <fstream>
#include <QDir>

bool saveFile(QString webSite, QString login, QString password);

class SaveFile
{
public:
    SaveFile();

    void setFName(QString name) { fName = name; }
    void setWebSiteName(QString webSite) { webSiteName = webSite; }
    void setLogin(QString usrLogin) { login = usrLogin; }
    void setPassword(QString usrPassword) { password = usrPassword; }

    const QString path = "Saved/";

    void Save() {
        if (!QDir().cd(path)) QDir().mkdir(path);

        QString data = "webSiteName> " + webSiteName + ";\nlogin> " + login + ";\npassword> " + password + ";";

        std::ofstream outfile (fName.toUtf8().constData());
        outfile << data.toUtf8().constData() << std::endl;
        outfile.close();
    }
private:
    QDir pathDir = QDir(path);

    QString fName;
    QString webSiteName;
    QString login;
    QString password;
};

#endif // SAVEFILE_H

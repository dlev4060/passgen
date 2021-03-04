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

    static std::string encryptDecrypt(std::string toEncrypt) {
        char key[3] = {'R', 'P', 'G'}; //Any chars will work, in an array of any size
        std::string output = toEncrypt;

        for (int i = 0; i < toEncrypt.size(); i++)
            output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

        return output;
    }

    void Save() {
        if (!QDir().cd(path)) QDir().mkdir(path);

        QString data = "webSiteName> " + webSiteName + "\nlogin> " + login + "\npassword> " + password;

        std::cout << "Saving data: " << data.toUtf8().constData() << std::endl;

        std::ofstream outfile (fName.toUtf8().constData());
        outfile << encryptDecrypt(data.toUtf8().constData()) << std::endl;
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

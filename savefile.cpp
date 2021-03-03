#include "savefile.h"

SaveFile::SaveFile()
{

}

bool saveFile(QString webSite, QString login, QString password) {
    bool result = false;

    SaveFile *file = new SaveFile();

    file->setWebSiteName(webSite);
    file->setLogin(login);
    file->setPassword(password);
    file->setFName(file->path + webSite + ".sec");

    file->Save();

    return result;
}

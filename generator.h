#include <passwordgenerator.h>

QString GeneratePassword(int lenght, QString symbols) {
    QString result;

    for (int i = 0; i <= lenght; i++) {
        int rndIndex = rand() % symbols.length();
        QChar nextChar = symbols.at(rndIndex);
        result.append(nextChar);
    }

    return result;
}

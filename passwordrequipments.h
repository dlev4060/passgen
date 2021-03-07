#ifndef PASSWORDREQUIPMENTS_H
#define PASSWORDREQUIPMENTS_H

#pragma once

#include <iostream>
#include <QString>

QString sustainability(std::string password);

class PasswordRequipments
{
public:
    PasswordRequipments();

    unsigned int getRequipmentLength() { return requipmentLength; }
    QString getSpecSymbols() { return specSymbols; }
    QString getNumbers() { return numbers; }

    void setOverRequipmentsLenght(bool value) { overRequipmentsLenght = value; }
    bool getOverRequipmentsLenght() { return overRequipmentsLenght; }
    void setContainsUppercaseSymbols(bool value) { containsUppercaseSymbols = value; }
    bool getContainsUppercaseSymbols() { return containsUppercaseSymbols; }
    void setContainsLowercaseSymbols(bool value) { containsLowercaseSymbols = value; }
    bool getContainsLowercaseSymbols() { return containsLowercaseSymbols; }
    void setContainsNumbers(bool value) { containsNumbers = value; }
    bool getContainsNumbers() { return containsNumbers; }
    void setContainsSpecSymbols(bool value) { containsSpecSymbols = value; }
    bool getContainsSpecSymbols() { return containsSpecSymbols; }

private:
    unsigned int requipmentLength = 12;
    QString specSymbols = "!@#$%&*-_=~";
    QString numbers = "1234567890";

    bool overRequipmentsLenght = false;
    bool containsUppercaseSymbols = false;
    bool containsLowercaseSymbols = false;
    bool containsNumbers = false;
    bool containsSpecSymbols = false;
};

#endif // PASSWORDREQUIPMENTS_H

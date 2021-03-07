#include "passwordrequipments.h"
#include <iostream>

PasswordRequipments::PasswordRequipments()
{

}

QString sustainability(std::string password) {
    QString result = "";
    PasswordRequipments *pr = new PasswordRequipments();

    for (unsigned long i = 0; i <= password.length(); i++) {
        if (pr->getNumbers().contains(password[i])) pr->setContainsNumbers(true);

        if (pr->getSpecSymbols().contains(password[i])) pr->setContainsSpecSymbols(true);

        if (pr->getRequipmentLength() <= password.length()) pr->setOverRequipmentsLenght(true);

        if (isupper(password[i])) pr->setContainsUppercaseSymbols(true);

        if (islower(password[i])) pr->setContainsLowercaseSymbols(true);
    }

    if (!pr->getOverRequipmentsLenght()) {
        result = "weak";
        return result;
    }

    if (!pr->getContainsNumbers()) {
        result = "middle";
    }

    if (!(pr->getContainsLowercaseSymbols() && pr->getContainsUppercaseSymbols())) {
        result = "middle";

        std::cout << "Нема больших или маленьких символов" << std::endl;
        std::cout << pr->getContainsLowercaseSymbols() << std::endl;
        std::cout << pr->getContainsUppercaseSymbols() << std::endl;
    }

    if (!pr->getContainsSpecSymbols()) {
        result = "middle";

        std::cout << !pr->getContainsSpecSymbols() << std::endl;
    }

    if (pr->getOverRequipmentsLenght()
            && pr->getContainsNumbers()
            && (pr->getContainsLowercaseSymbols() && pr->getContainsUppercaseSymbols())) {
        result = "strong";
    }

    if (pr->getOverRequipmentsLenght()
            && pr->getContainsNumbers()
            && (pr->getContainsLowercaseSymbols() && pr->getContainsUppercaseSymbols())
            && pr->getContainsSpecSymbols()) {
        result = "very_strong";
    }


    return result;
}

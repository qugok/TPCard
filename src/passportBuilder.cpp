//
// Created by iesek on 09.04.2018.
//

#include <passportBuilder.h>

PassportBuilder::PassportBuilder() = default;

Card PassportBuilder::createPassport() const {
    PassportCard passportCard(firstName, lastName, bornDate, personalCode);
    return passportCard.getCard();
}

void PassportBuilder::setFirstName(const std::string &firstName)  {
    PassportBuilder::firstName = firstName;
}

void PassportBuilder::setLastName(const std::string &lastName) {
    PassportBuilder::lastName = lastName;
}

void PassportBuilder::setBornDate(const std::string &bornDate) {
    PassportBuilder::bornDate = bornDate;
}

void PassportBuilder::setPersonalCode(const std::string &personalCode) {
    PassportBuilder::personalCode = personalCode;
}

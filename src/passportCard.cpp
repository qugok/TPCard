//
// Created by iesek on 08.04.2018.
//

#include <passportCard.h>

PassportCard::PassportCard(const std::shared_ptr<Card> &card) : MasterCard(card) {
    if (this->getId() != 2)
        throw "WRONG_CARD_TYPE";
}

PassportCard::PassportCard(std::string firstName, std::string secondName, std::string bornDate,
                           std::string personalCode)  : MasterCard(){
    this->setId(2);
    this->writeString(firstName);
    this->writeString(secondName);
    this->writeString(bornDate);
    this->writeString(personalCode);
}

std::string PassportCard::getFirstName() const {
    //todo найти правильный индекс
    return this->readAllStrings()[4];
}

std::string PassportCard::getSecondName() const {
    //todo найти правильный индекс
    return this->readAllStrings()[3];
}

std::string PassportCard::getBornDate() const {
    //todo найти правильный индекс
    return this->readAllStrings()[2];
}

std::string PassportCard::getPersonalCode() const {
    //todo найти правильный индекс
    return this->readAllStrings()[1];
}

Card PassportCard::getCard() const {
    return *this;
}
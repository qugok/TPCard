//
// Created by iesek on 08.04.2018.
//

#include <passportCard.h>

PassportCard::PassportCard(const std::shared_ptr<Card> &card) : MasterCard(card) {
    if (this->getId() != cardId) {
        throw Wrong_Card_Type_Exception();
    }
}

PassportCard::PassportCard(const std::string& firstName, const std::string& lastName, const std::string& bornDate,
                           const std::string& personalCode)  : MasterCard(){
    this->setId(cardId);
    this->writeString(firstName);
    this->writeString(lastName);
    this->writeString(bornDate);
    this->writeString(personalCode);
}

std::string PassportCard::getFirstName() const {
    return this->readAllStrings()[3];
}

std::string PassportCard::getSecondName() const {
    return this->readAllStrings()[2];
}

std::string PassportCard::getBornDate() const {
    return this->readAllStrings()[1];
}

std::string PassportCard::getPersonalCode() const {
    return this->readAllStrings()[0];
}

Card PassportCard::getCard() const {
    return this->getCurrentCard();
}
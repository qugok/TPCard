//
// Created by iesek on 08.04.2018.
//

#include <bankCard.h>

BankCard::BankCard(const std::shared_ptr<Card> &card) : MasterCard(card) {
    if (this->getId() != cardId)
        throw Wrong_Card_Type_Exception();
}

BankCard::BankCard(std::string number, std::string endDate, std::string csvCode, std::string code) : MasterCard() {
    this->setId(cardId);
    this->writeString(code);
    this->writeString(csvCode);
    this->writeString(endDate);
    this->writeString(number);
}

std::string BankCard::getNumber() const {
    return this->readLast();
}

std::string BankCard::getEndDate() const {
    return this->readAllStrings()[1];
}

bool BankCard::checkCsvCode(std::string userCode) const {
    return this->readAllStrings()[2] == userCode;
}

bool BankCard::checkCode(std::string userCode) const {
    return this->readAllStrings()[3] == userCode;
}

Card BankCard::getCard() const {
    return this->getCurrentCard();
}

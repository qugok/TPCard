//
// Created by iesek on 09.04.2018.
//

#include <bankCardBuilder.h>

bankCardBuilder::bankCardBuilder() = default;

void bankCardBuilder::setNumber(const std::string &number) {
    bankCardBuilder::number = number;
}

void bankCardBuilder::setEndDate(const std::string &endDate) {
    bankCardBuilder::endDate = endDate;
}

void bankCardBuilder::setCsvCode(const std::string &csvCode) {
    bankCardBuilder::csvCode = csvCode;
}

void bankCardBuilder::setCode(const std::string &code) {
    bankCardBuilder::code = code;
}

Card bankCardBuilder::createBankCard() {
    BankCard bankCard(number,endDate,csvCode,code);
    return bankCard.getCard();
}

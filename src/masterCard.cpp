//
// Created by iesek on 08.04.2018.
//

#include <masterCard.h>
#include <algorithm>

bool MasterCard::deleteLastBytes(int count) {
    return m_card->deleteLastBytes(count);
}

bool MasterCard::writeBytesToCard(const std::vector<char> &bytes) {
    return m_card->writeBytesToCard(bytes);
}

std::vector<char> MasterCard::readAllBytes() const {
    return m_card->readAllBytes();
}

bool MasterCard::setId(char id) {
    return m_card->setId(id);
}

bool MasterCard::writeString(const std::string& value) {
    std::vector<char> bytes;
    bytes.push_back(0);
    for (char i : value) {
        bytes.push_back(i);
    }
    return m_card->writeBytesToCard(bytes);
}

std::string MasterCard::readLast(int since) const{
    std::string ans;
    std::vector<char> chars = this->readAllBytes();
    for (int i = chars.size() - since; i < chars.size();  i++)
    {
        if (chars[chars.size() - i - 1] == 0)
            break;
        ans += chars[chars.size() - i - 1];
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

bool MasterCard::clear() {
    return deleteLastBytes(this->readAllBytes().size() - 1);
}

std::vector<std::string> MasterCard::readAllStrings() const{
    std::vector<std::string> ans;
    int index = readAllBytes().size();
    while (index > 1)
    {
        ans.push_back(readLast(index));
        index -= ans.back().size() + 1;
    }
    return ans;
}

std::string MasterCard::readLast() const {
    return readLast(readAllBytes().size());
}

MasterCard::MasterCard(std::shared_ptr<Card> card) : m_card(std::move(card)){}

MasterCard::MasterCard() : MasterCard(std::make_shared<Card>()){}

Card MasterCard::getCurrentCard() const{
    Card card;
    card.writeBytesToCardForced(this->m_card.get()->readAllBytes());
    return card;
}

char MasterCard::getId() {
    return m_card.get()->getId();
}

const char *Wrong_Card_Type_Exception::what() const throw(){
    return "Wrong_Card_Type_Exception";
}

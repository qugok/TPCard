//
// Created by iesek on 08.04.2018.
//

#include <defaultCardInterface.h>



bool Card::writeBytesToCard(const std::vector<char>& bytes) {
    if (this->bytes.empty())
        return false;
    if (bytes.size() + this->bytes.size() > this->maxSize)
        return false;
    for (char byte : bytes) {
        this->bytes.push_back(byte);
    }
    return true;
}

std::vector<char> Card::readAllBytes() const {
    return this->bytes;
}

bool Card::deleteLastBytes(int count) {
    if (count > this->bytes.size() - 1)
        return false;
    bytes.erase(bytes.begin() + (bytes.size() - count), bytes.end());
    return true;
}

Card::Card(char cardId) {
    bytes.push_back(cardId);
}

bool Card::setId(char id) {
    if (!bytes.empty())
    {
        return false;
    } else {
        bytes.push_back(id);
        return true;
    }
}

char Card::getId() {
    if (bytes.empty())
        return 0;
    return bytes[0];
}

Card::Card() = default;

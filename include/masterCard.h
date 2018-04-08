//
// Created by iesek on 08.04.2018.
//

#pragma once

#include <defaultCardInterface.h>
#include <string>
#include <exception>
#include <memory>

class MasterCard : public Card
{
private:
    std::shared_ptr<Card> m_card;

    std::string readLast(int since) const;
public:
    explicit MasterCard(std::shared_ptr<Card> card);

    MasterCard();

    bool setId(char id) override;

    std::vector<char> readAllBytes() const override;

    bool writeBytesToCard(const std::vector<char> &bytes) override;

    bool deleteLastBytes(int count) override;

    bool writeString(std::string value);

    std::string readLast() const ;

    std::vector<std::string> readAllStrings() const;

    bool clear();

};

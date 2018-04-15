//
// Created by iesek on 08.04.2018.
//

#pragma once

#include <defaultCardInterface.h>
#include <string>
#include <exception>
#include <memory>
/**
 * @brief улучшеный интерфейс карты \brief так же не рекомендуется для использования пользователем
 */
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

    char getId() override;

    bool writeBytesToCard(const std::vector<char> &bytes) override;

    bool deleteLastBytes(int count) override;

    bool writeString(const std::string& value);

    std::string readLast() const ;

    std::vector<std::string> readAllStrings() const;

    Card getCurrentCard() const;

    bool clear();

};

class Wrong_Card_Type_Exception : public std::exception{
public:
    const char *what() const throw() override;
};
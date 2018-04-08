//
// Created by iesek on 08.04.2018.
//

#pragma once

#include <masterCard.h>

class PassportCard : private MasterCard {
public:

    /**
     * @brief считывание карты с паспортом
     * @param card
     */
    explicit PassportCard(const std::shared_ptr<Card> &card);

    /**
     * @brief создание карты с паспортом
     * @param firstName имя
     * @param secondName фамилия
     * @param bornDate дата рождения
     * @param personalCode номер паспорта в формате строки
     */
    PassportCard(std::string firstName, std::string secondName, std::string bornDate, std::string personalCode);

    /**
     * @brief имя
     * @return
     */
    std::string getFirstName() const;
    /**
     * @brief фамилия
     * @return
     */
    std::string getSecondName() const;
    /**
     * @brief дата рождения
     * @return
     */
    std::string getBornDate() const;
    /**
     * @brief номер паспорта
     * @return
     */
    std::string getPersonalCode() const;

    /**
     * @brief получение созданной карты
     * @return
     */
    Card getCard() const;

};
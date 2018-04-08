//
// Created by iesek on 09.04.2018.
//
#pragma once

#include <passportCard.h>

/**
 * @brief билдер для карты паспорта
 */
class PassportBuilder {
private:
    std::string firstName;
    std::string lastName;
    std::string bornDate;
    std::string personalCode;

public:
    /**
     * @brief инициализация
     */
    PassportBuilder();
    /**
     * @brief установка имени
     * @param firstName значение
     */
    void setFirstName(const std::string &firstName);
    /**
     * @brief установка фамилии
     * @param lastName значение
     */
    void setLastName(const std::string &lastName);
    /**
     * @brief установка даты рождения
     * @param bornDate значение
     */
    void setBornDate(const std::string &bornDate);
    /**
     * @brief установка номера паспорта
     * @param personalCode значение
     */
    void setPersonalCode(const std::string &personalCode);
    /**
     * @brief создание карты с паспортными данными
     * @return карта
     */
    Card createPassport() const;
};
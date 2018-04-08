//
// Created by iesek on 09.04.2018.
//

#pragma once

#include <bankCard.h>

/**
 * @brief билдер для банковскоё карты
 */
class bankCardBuilder{
private:
    std::string number;
    std::string endDate;
    std::string csvCode;
    std::string code;
public:
    /**
     * @brief инициализация
     */
    bankCardBuilder();
    /**
     * @brief уствновка номера карты
     * @param number значение
     */
    void setNumber(const std::string &number);
    /**
     * @brief установка даты окончания карты
     * @param endDate значение
     */
    void setEndDate(const std::string &endDate);
    /**
     * @brief установка csv кода
     * @param csvCode значение
     */
    void setCsvCode(const std::string &csvCode);
    /**
     * @brief установка пинкода
     * @param code значение
     */
    void setCode(const std::string &code);
    /**
     * @brief создание карты с банковскими данными
     * @return карта
     */
    Card createBankCard();
};
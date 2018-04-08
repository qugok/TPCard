//
// Created by iesek on 08.04.2018.
//

#pragma once

#include <masterCard.h>

class BankCard : private  MasterCard {
public:

    /**
     * @brief считывание банковской карты
     * @param card
     */
    explicit BankCard(const std::shared_ptr<Card> &card);

    /**
     * @brief создание банковской карты
     * @param number номер карты
     * @param endDate дата окончания действия
     * @param csvCode csv код
     * @param code пин-код
     */
    BankCard(std::string number, std::string endDate, std::string csvCode, std::string code);

    /**
     * @brief номер банковской карты
     * @return
     */
    std::string getNumber() const ;

    /**
     * @brief дата окончания действия банковской карты
     * @return
     */
    std::string getEndDate() const ;

    /**
     * @brief проверка csv кода
     * @param userCode пользовательский код
     * @return true, если совпали \n false иначе
     */
    bool checkCsvCode(std::string userCode) const ;

    /**
     * @brief проверка пин-кода, введённого пользователем
     * @param userCode пользовательский код
     * @return true, если совпали \n false иначе
     */
    bool checkCode(std::string userCode) const ;

    /**
     * @brief получение созданной карты
     * @return
     */
    Card getCard() const;
};

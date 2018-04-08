//
// Created by iesek on 09.04.2018.
//

#pragma once

#include <passportCard.h>
#include <bankCard.h>
#include <cardType.h>
/**
 * @brief получение типа карты
 * @param card неизвестная карта
 * @return cardType тип карты
 */
cardType getCardType(Card card)
{
    return cardType (card.getId());
//    if (card.getId() == PassportCard::cardId)
//    {
//        return "PassportCard";
//    }
//    if (card.getId() == BankCard::cardId)
//    {
//        return "BankCard";
//    }

}
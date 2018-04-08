//
// Created by iesek on 21.03.2018.
//

#include <gtest/gtest.h>
#include <defaultCardInterface.h>
#include <masterCard.h>
#include <passportCard.h>
#include <bankCard.h>

TEST(all, defaul_card) {
    Card card(5);
    EXPECT_FALSE(card.deleteLastBytes(5));
    EXPECT_TRUE(card.writeBytesToCard(std::vector<char>({(char) 123, (char) 234, (char) 255, 'r'})));
    EXPECT_EQ(card.readAllBytes()[2], (char)234);
    EXPECT_EQ(card.readAllBytes()[0], (char)5);
    EXPECT_EQ(card.readAllBytes().size(), 5);
    EXPECT_TRUE(card.deleteLastBytes(3));
    EXPECT_EQ(card.readAllBytes().size(), 2);
}

TEST(all, masterCard){
    std::shared_ptr<Card> card = std::make_shared<Card>();
    MasterCard masterCard(card);
    masterCard.setId(5);
    masterCard.writeString("wdsfvsdfv");
    masterCard.writeString("sdfsdf");
    EXPECT_EQ(masterCard.readAllStrings().size(), 2);
    masterCard.writeString("adfgadsf");
    EXPECT_EQ(masterCard.readAllStrings()[0],"adfgadsf");
    EXPECT_EQ(masterCard.readAllStrings()[1],"sdfsdf");
    EXPECT_EQ(masterCard.readAllStrings()[2],"wdsfvsdfv");
    Card c = masterCard.getCurrentCard();
}

TEST(all, passportCard) {
    PassportCard card("alex", "dls", "16.04.1234", "123123");
    EXPECT_EQ(card.getBornDate(), "16.04.1234");
    EXPECT_EQ(card.getFirstName(), "alex");
    EXPECT_EQ(card.getPersonalCode(), "123123");
    EXPECT_EQ(card.getSecondName(), "dls");
//    std::shared_ptr<Card> c(*(card.getCard()));
    std::shared_ptr<Card> c(new Card(card.getCard()));
//    c.get()->writeBytesToCard(card.getCard().readAllBytes());
//    *c = card.getCard();
    PassportCard passportCard(c);
    EXPECT_EQ(passportCard.getBornDate(), "16.04.1234");
    EXPECT_EQ(passportCard.getFirstName(), "alex");
    EXPECT_EQ(passportCard.getPersonalCode(), "123123");
    EXPECT_EQ(passportCard.getSecondName(), "dls");
}

TEST(all, bankCard) {
    BankCard card("1234567890", "16.04.1234", "123", "1234");
    EXPECT_EQ(card.getEndDate(), "16.04.1234");
    EXPECT_EQ(card.getNumber(), "1234567890");
    EXPECT_TRUE(card.checkCsvCode("123"));
    EXPECT_TRUE(card.checkCode("1234"));
//    std::shared_ptr<Card> c(*(card.getCard()));
    std::shared_ptr<Card> c(new Card(card.getCard()));
//    c.get()->writeBytesToCard(card.getCard().readAllBytes());
//    *c = card.getCard();
    EXPECT_ANY_THROW(PassportCard passportCard(c));
    BankCard bankCard(c);
    EXPECT_EQ(bankCard.getEndDate(), "16.04.1234");
    EXPECT_EQ(bankCard.getNumber(), "1234567890");
    EXPECT_TRUE(bankCard.checkCsvCode("123"));
    EXPECT_TRUE(bankCard.checkCode("1234"));
}
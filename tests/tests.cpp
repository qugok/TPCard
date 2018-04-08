//
// Created by iesek on 21.03.2018.
//

#include <gtest/gtest.h>
#include <defaultCardInterface.h>
#include <masterCard.h>

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

TEST(all, masterCard)
{
    std::shared_ptr<Card> card = std::make_shared<Card>();
    MasterCard masterCard(card);
    masterCard.setId(5);
    masterCard.writeString("wdsfvsdfv");
    masterCard.writeString("sdfsdf");
    EXPECT_EQ(masterCard.readAllStrings().size(), 2);
}
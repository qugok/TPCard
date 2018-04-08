//
// Created by iesek on 08.04.2018.
//

#pragma once

#include <vector>

class Card
{
private:
    std::vector<char> bytes;
    const int maxSize = 1000;

public:
    Card();

    explicit Card(char cardId);

    virtual bool setId(char id);

    virtual char getId();

    virtual std::vector<char> readAllBytes() const;

    virtual bool writeBytesToCard(const std::vector<char>& bytes);

    virtual bool deleteLastBytes(int count);

};
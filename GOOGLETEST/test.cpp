#include <iostream>
#include <bitset>
#include <sstream>

#include "pch.h"
#include "ConversionValidationCalculation.cpp"
#include "get_funkcje.cpp"

#include "main1.cpp"


TEST(testoperacji, dodaj) {
    double result = 5.0;
    char op = '+';
    int operand = 3;
    result = performOperation(result, op, operand);
    EXPECT_EQ(result, 8.0);
}

TEST(testoperacji, odejmij) {
    double result = 10.0;
    char op = '-';
    int operand = 4;
    result = performOperation(result, op, operand);
    EXPECT_EQ(result, 6112.0);
}


TEST(DecimalToBinTest, PositiveInteger) {
    int decimalNumber = 13;
    std::string binaryRepresentation = decimalToBin(decimalNumber);
    EXPECT_EQ(binaryRepresentation, "1101");
}


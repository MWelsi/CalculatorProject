#pragma once

// funkcje zosta³y opisane w ConversionValidationCalculation.cpp
std::string decimalToBin(int decimalValue);
bool isValidBinary(const std::string& input);
int binaryToDecimal(std::string n);

std::string decimalToOct(int decimalValue);
bool isValidOctal(const std::string& input);

std::string decimalToHex(int decimalValue);
bool isValidHex(const std::string& input);
int hexadecimalToDecimal(std::string hexVal);

double performOperation(double operand1, char op, double operand2);


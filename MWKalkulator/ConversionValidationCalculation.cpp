#include <iostream>
#include <bitset>                  // Biblioteka do obs³ugi operacji na bitach.
#include <sstream>                 // Biblioteka do obs³ugi strumieni napisów, u¿ywana do konwersji liczby dziesiêtnej na szesnastkow¹.

#include "ConversionValidationCalculation.h"


//Dok³adnie opisana zosta³a grupa systemu szesnastkowego, reszta zosta³a wykonana w podobny sposób


///////////////////////////////////////////////////////////
// GRUPA FUNKCJI OPDPOWIADAJACA ZA SYSTEM BINARNY
///////////////////////////////////////////////////////////



std::string decimalToBin(int decimalValue) {
    std::stringstream binaryStream;
    binaryStream << std::bitset<32>(decimalValue);
    return binaryStream.str();
}
bool isValidBinary(const std::string& input) {
    for (char c : input) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}
int binaryToDecimal(std::string n)
{
    std::string num = n;
    int dec_value = 0;

    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}


///////////////////////////////////////////////////////////
// GRUPA FUNKCJI OPDPOWIADAJACA ZA SYSTEM OSEMKOWY
///////////////////////////////////////////////////////////



std::string decimalToOct(int decimalValue) {
    std::stringstream octalStream;
    octalStream << std::oct << decimalValue;
    return octalStream.str();
}
bool isValidOctal(const std::string& input) {
    for (char c : input) {
        if (!std::isdigit(c) || c < '0' || c > '7') {
            return false;
        }
    }
    return true;
}







///////////////////////////////////////////////////////////
// GRUPA FUNKCJI OPDPOWIADAJACA ZA SYSTEM SZESNASTKOWY
///////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////
// Funkcja konwertuje liczbê dziesiêtn¹ na szesnastkow¹.
///////////////////////////////////////////////////////////
//		
// WEJŒCIE:
//      - decimalValue: liczba ca³kowita do przekszta³cenia na szesnastkow¹.
//    
//		
// WYJŒCIE:
//      - std::string: reprezentacja szesnastkowa liczby dziesiêtnej.
//      
//		
// UWAGI:
//    Funkcja wykorzystuje std::stringstream do przekszta³cenia liczby dziesiêtnej
//    na jej reprezentacjê szesnastkow¹ i zwraca wynik jako std::string.
//		
std::string decimalToHex(int decimalValue) {
    std::stringstream hexStream;
    hexStream << std::hex << decimalValue;
    return hexStream.str();
}





///////////////////////////////////////////////////////////
// Funkcja sprawdza poprawnoœæ reprezentacji szesnastkowej.
///////////////////////////////////////////////////////////
//		
// WEJŒCIE:
//      - input: std::string - liczba szesnastkowa do sprawdzenia.
//      
//		
// WYJŒCIE:
//      - bool: true, jeœli reprezentacja jest poprawna; false, jeœli niepoprawna.
//      
//		
// UWAGI:
//    Funkcja iteruje po ka¿dym znaku w ci¹gu szesnastkowym i sprawdza,
//    czy jest to poprawny znak (cyfra lub litera A-F).
//    Zwraca true, jeœli wszystkie znaki s¹ poprawne, w przeciwnym razie false.
//		
bool isValidHex(const std::string& input) {
    for (char c : input) {
        if (!std::isxdigit(c)) {
            return false;
        }
    }
    return true;
}




///////////////////////////////////////////////////////////
// Funkcja konwertuje liczbê szesnastkow¹ na jej reprezentacjê dziesiêtn¹.
///////////////////////////////////////////////////////////
//		
// WEJŒCIE:
//     -std::string - liczba szesnastkowa do przekszta³cenia.
//      
//		
// WYJŒCIE:
//      - int: reprezentacja dziesiêtna liczby szesnastkowej.
//      
//		
// UWAGI:
//    Funkcja iteruje po ka¿dym znaku w ci¹gu szesnastkowym, przekszta³ca go
//    na liczbê dziesiêtn¹ i sumuje, aby uzyskaæ reprezentacjê dziesiêtn¹ ca³ej liczby.
//
//		
int hexadecimalToDecimal(std::string hexVal)
{
    int len = hexVal.size();

    int base = 1;

    int dec_val = 0;


    for (int i = len - 1; i >= 0; i--) {

        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (int(hexVal[i]) - 48) * base;


            base = base * 16;
        }

        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (int(hexVal[i]) - 55) * base;


            base = base * 16;
        }
    }
    return dec_val;
}






///////////////////////////////////////////////////////////
// Funkcja wykonuj¹ca obliczenia na dwóch zmiennych.
///////////////////////////////////////////////////////////
//		
// WEJŒCIE:
//      - operand1: pierwszy operand.
//      - op: operator arytmetyczny (+, -, *, /).
//      - operand2: drugi operand.
//		
// WYJŒCIE:
//      - double: wynik operacji arytmetycznej.
//      
// UWAGI:
//    Funkcja u¿ywa switch do wykonania operacji zgodnie z podanym operatorem.
//    Obs³uguje operatory dodawania, odejmowania, mno¿enia oraz dzielenia.
//    W przypadku dzielenia sprawdza, czy drugi operand nie jest zerem.
//    W przypadku b³êdnego operatora lub dzielenia przez zero, wyœwietla komunikat b³êdu
//    i zwraca poprzedni wynik (operand1) bez wykonania operacji.
//		
double performOperation(double operand1, char op, double operand2) {

    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 != 0) {
            return operand1 / operand2;
        }
        else {
            std::cout << "Error: Cannot divide by zero. Returning previous result." << std::endl;
            return operand1;
        }
    default:
        std::cout << "Invalid operator. Returning previous result." << std::endl;
        return operand1;
    }
}
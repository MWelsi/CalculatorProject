#include <iostream>
#include <bitset>                  // Biblioteka do obs�ugi operacji na bitach.
#include <sstream>                 // Biblioteka do obs�ugi strumieni napis�w, u�ywana do konwersji liczby dziesi�tnej na szesnastkow�.

#include "ConversionValidationCalculation.h"


//Dok�adnie opisana zosta�a grupa systemu szesnastkowego, reszta zosta�a wykonana w podobny spos�b


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
// Funkcja konwertuje liczb� dziesi�tn� na szesnastkow�.
///////////////////////////////////////////////////////////
//		
// WEJ�CIE:
//      - decimalValue: liczba ca�kowita do przekszta�cenia na szesnastkow�.
//    
//		
// WYJ�CIE:
//      - std::string: reprezentacja szesnastkowa liczby dziesi�tnej.
//      
//		
// UWAGI:
//    Funkcja wykorzystuje std::stringstream do przekszta�cenia liczby dziesi�tnej
//    na jej reprezentacj� szesnastkow� i zwraca wynik jako std::string.
//		
std::string decimalToHex(int decimalValue) {
    std::stringstream hexStream;
    hexStream << std::hex << decimalValue;
    return hexStream.str();
}





///////////////////////////////////////////////////////////
// Funkcja sprawdza poprawno�� reprezentacji szesnastkowej.
///////////////////////////////////////////////////////////
//		
// WEJ�CIE:
//      - input: std::string - liczba szesnastkowa do sprawdzenia.
//      
//		
// WYJ�CIE:
//      - bool: true, je�li reprezentacja jest poprawna; false, je�li niepoprawna.
//      
//		
// UWAGI:
//    Funkcja iteruje po ka�dym znaku w ci�gu szesnastkowym i sprawdza,
//    czy jest to poprawny znak (cyfra lub litera A-F).
//    Zwraca true, je�li wszystkie znaki s� poprawne, w przeciwnym razie false.
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
// Funkcja konwertuje liczb� szesnastkow� na jej reprezentacj� dziesi�tn�.
///////////////////////////////////////////////////////////
//		
// WEJ�CIE:
//     -std::string - liczba szesnastkowa do przekszta�cenia.
//      
//		
// WYJ�CIE:
//      - int: reprezentacja dziesi�tna liczby szesnastkowej.
//      
//		
// UWAGI:
//    Funkcja iteruje po ka�dym znaku w ci�gu szesnastkowym, przekszta�ca go
//    na liczb� dziesi�tn� i sumuje, aby uzyska� reprezentacj� dziesi�tn� ca�ej liczby.
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
// Funkcja wykonuj�ca obliczenia na dw�ch zmiennych.
///////////////////////////////////////////////////////////
//		
// WEJ�CIE:
//      - operand1: pierwszy operand.
//      - op: operator arytmetyczny (+, -, *, /).
//      - operand2: drugi operand.
//		
// WYJ�CIE:
//      - double: wynik operacji arytmetycznej.
//      
// UWAGI:
//    Funkcja u�ywa switch do wykonania operacji zgodnie z podanym operatorem.
//    Obs�uguje operatory dodawania, odejmowania, mno�enia oraz dzielenia.
//    W przypadku dzielenia sprawdza, czy drugi operand nie jest zerem.
//    W przypadku b��dnego operatora lub dzielenia przez zero, wy�wietla komunikat b��du
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
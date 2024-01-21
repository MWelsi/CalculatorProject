#include <iostream>
#include <sstream> //zapewnia klasê std::stringstream, która umo¿liwia konwersje ró¿nych typów danych na napisy lub odwrotnie.

#include "ConversionValidationCalculation.h"
#include "get_funkcje.h"




///////////////////////////////////////////////////////////
// Funkcja pobiera od u¿ytkownika wybór systemu liczbowego.
///////////////////////////////////////////////////////////
//		
// WEJŒCIE:
//    - u¿ytkownik wewn¹trz funkcji ma opcjê wyboru poœród 4 liczb.
//		
// WYJŒCIE:
//     - int: wybór systemu liczbowego (1 - binarny, 2 - ósemkowy, 3 - szesnastkowy, 4 - float).
//      
//		
// UWAGI:
//    Funkcja wyœwietla menu wyboru systemu liczbowego, pobiera od u¿ytkownika wybór
//    i sprawdza poprawnoœæ wprowadzonej liczby. Jeœli wprowadzona liczba nie jest poprawna,
//    wyœwietla komunikat b³êdu i prosi u¿ytkownika o ponowne wprowadzenie.
//	
int getNumberSystem() {

    int choice;

    while (true) {
        std::cout << "\nChoose a number system:\n"
            << "1. Binary (bin)\n"
            << "2. Octal (oct)\n"
            << "3. Hexadecimal (hex)\n"
            << "4. Float\n\n"
            << "Enter your choice (1-4): ";

        if (std::cin >> choice && choice >= 1 && choice <= 4) {
            std::cout << '\n';
            break;
        }
        else {

            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return choice;
}



///////////////////////////////////////////////////////////
// Funkcja pobiera od u¿ytkownika iloœæ liczb do wykonania operacji.
///////////////////////////////////////////////////////////
//		
//  Zachowuje siê w podobny sposób do poprzedniej getNumberSystem()
//
int getQuantityOfNumbers() {

    int number;

    // formu³a pomagaj¹ca zidentyfikowaæ czy liczba jest liczb¹ czy te¿ innym znakiem //

    while (true) {

        std::cout << "Enter the quantity of numbers: ";

        if (std::cin >> number) {
            std::cout << '\n';
            break;
        }
        else {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return number;
}




///////////////////////////////////////////////////////////
// GRUPA FUNKCJI POBIERAJACE INFORMACJE OD UZYTKOWNIKA I
// ZWRACAJACA WARTOSC LICZBY W ODPOWIEDNIM SYSTEMIE
///////////////////////////////////////////////////////////
//		
// WEJŒCIE:
//      - index: numer porz¹dkowy liczby.
//      - u¿ytkownik wpisuje wartoœci które wykorzystuje do obliczeñ.
//     
//		
// WYJŒCIE:
//    Zwraca:
//      - int: wartoœæ liczby.
//		
// UWAGI:
//    Funkcja prosi u¿ytkownika o podanie wartoœci liczby,
//    sprawdza poprawnoœæ wprowadzonej liczby. Jeœli wprowadzona liczba nie jest poprawna,
//    wyœwietla komunikat b³êdu i prosi u¿ytkownika o ponowne wprowadzenie.
//    Konwertuje wprowadzon¹ liczbê bin/oct/hex na dziesiêtn¹.
//		
int getBinaryOperand(int index) {
    std::string binaryValue;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Enter value of " << index + 1 << " number in binary (0 or 1): ";

        std::cin >> binaryValue;
        if (isValidBinary(binaryValue)) {
            validInput = true;
            std::cout << "\n";
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid binary value (0 or 1)\n";
        }

    }

    int decimalValue = binaryToDecimal(binaryValue);
    return decimalValue;
}
int getOctalOperand(int index) {

    std::string octalValue;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Enter value of " << index + 1 << " number in octal: ";

        std::cin >> octalValue;
        if (isValidOctal(octalValue)) {
            validInput = true;
            std::cout << "\n";
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid octal value (0-7)\n";

            return getOctalOperand(index);

        }

        std::istringstream octalStream(octalValue);
        int decimalValue;
        octalStream >> std::oct >> decimalValue;
        return decimalValue;

    }
}
int getHexOperand(int index) {

    std::string hexValue;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Enter value of " << index + 1 << " number: ";

        std::cin >> hexValue;
        if (isValidHex(hexValue)) {
            validInput = true;
            std::cout << "\n";
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid hexadecimal value (0-9, A-F)\n";

            return getHexOperand(index);
        }
    }

    int decimalValue = hexadecimalToDecimal(hexValue);
    return decimalValue;
}
double getFloatOperand(int index) {

    double operand;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Enter value of " << index + 1 << " number: ";

        if (std::cin >> operand && std::cin.peek() == '\n') {
            validInput = true;
            std::cout << "\n";
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter only numbers\n";
        }
    }
    return operand;
}





///////////////////////////////////////////////////////////
// Funkcja pobiera od u¿ytkownika operator.
///////////////////////////////////////////////////////////
//		
// WEJŒCIE:
//      Brak parametrów wejsciowych funkcji
//      u¿ytkownik wybiera okreœlony przez niego operator
//		
// WYJŒCIE:
//      Zwraca:
//          - char: operator arytmetyczny (+, -, *, /).
//		
// UWAGI:
//    Funkcja prosi u¿ytkownika o podanie operatora arytmetycznego,
//    sprawdza poprawnoœæ wprowadzonego znaku. Jeœli wprowadzony znak nie jest poprawny,
//    wyœwietla komunikat b³êdu i prosi u¿ytkownika o ponowne wprowadzenie.
//    Eliminuje równie¿ mo¿liwoœæ wprowadzenia dodatkowych znaków po poprawnym wyborze operatora.
//		
char getOperator() {

    char op;
    bool isValidInput = false;


    // formu³a pomagaj¹ca wyeliminowaæ wpisywanie innych znaków ni¿ +, -, *, /  //
    while (!isValidInput) {
        std::cout << "Enter an operator (+, -, *, /): ";
        std::cin >> op;


        if (op == '+' || op == '-' || op == '*' || op == '/') {
            isValidInput = true;
            std::cout << "\n";
        }
        else {
            std::cout << "Invalid operator. Please enter one of the valid operators." << std::endl;

            std::cin.clear();
            while (std::cin.get() != '\n') {
                continue;
            }
        }
    }

    return op;
}
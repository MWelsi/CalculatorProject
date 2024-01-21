////////////////////////////////////////////////////////////////////
//               KALKULATOR DLA ELEKTRONIKOW MAIN
/////////////////////////////////////////////////////////////////////
//		
//  Jezyki programowania obiektowego
//	
//  Autor projektu: Mikolaj Welsyng 410601		
//  EiT, 3 rok
//		
//		
//  Prowadzący: Prof. dr hab. inz. Boguslaw Cyganek
/////////////////////////////////////////////////////////////////////


#include <iostream>

// Ponizej znajduja sie dyrektywy #include do plikow naglowkowych.
#include "Menu.h"                               // Naglowek z funkcjami obslugujacymi menu.
#include "ConversionValidationCalculation.h"    // Naglowek dla konwersji, walidacji i obliczen.
#include "get_funkcje.h"                        // Z funkcjami pobierajacymi dane od uzytkownika.



// main //

int main() {

    double result = 0;


    // Glowna petla dzieki ktorej program wraca za kazdym razem do menu. (Menu.h)
    while (runCalculatorMenu()) {

        // pobiera wybrany przez uzytkownika system liczbowy (get_funkcje.h)
        int numberSystem = getNumberSystem();

        // pobiera liczbe wartosci ktora uzytkownik uzyje do obliczen
        int quantityofValues = getQuantityOfNumbers();



        // switch ktory na podstawie wybranego systemu trafia do odpowiedniego case'a
        switch (numberSystem) {

        //system binarny
        case 1:

            for (int i = 0; i < quantityofValues; ++i) {

                char op;

                // uzycie funkcji pobierajacej od uzytkownika ciag 0 i 1 (get_funkcje.h)
                int binOperand = getBinaryOperand(i);

                // Funkcja przypisujaca wybrany przez uzytkownika operator
                if (i > 0) {
                    op = getOperator();
                }
                else {
                    op = '+';
                }

                // funkcja obliczajaca oraz przypisanie wyniku do result
                result = performOperation(result, op, binOperand);

                // wyswietlanie wyniku posredniego 
                if (i > 0 && i < quantityofValues - 1) {
                    std::cout << "Intermediate result: " << decimalToBin(result) << std::endl;
                    std::cout << '\n';
                }
            }

            // wynik ostateczny przeksztalcony funkcja decimalToBin (ConversionValidationCalculation.h)
            std::cout << "\n//////////////////////////////\nYour final result: " << decimalToBin(result) << "\n//////////////////////////////\n";
            break;


        

    // Reszta przypadkow odpowiednich systemow jest podobna, rozni sie jedynie nazwami funkcji.


        // system osemkowy
        case 2:

            for (int i = 0; i < quantityofValues; ++i) {

                char op;

                int octOperand = getOctalOperand(i);

                if (i > 0) {
                    op = getOperator();
                }
                else {
                    op = '+';
                }

                result = performOperation(result, op, octOperand);


                if (i > 0 && i < quantityofValues - 1) {
                    std::cout << "Intermediate result: " << decimalToOct(result) << std::endl;
                    std::cout << '\n';
                }
            }
            std::cout << "\n//////////////////////////////\nYour final result: " << decimalToBin(result) << "\n//////////////////////////////\n";

            break;





        // system szesnastkowy
        case 3:

            for (int i = 0; i < quantityofValues; ++i) {

                char op;

                int hexOperand = getHexOperand(i);

                if (i > 0) {
                    op = getOperator();
                }
                else {
                    op = '+';
                }

                result = performOperation(result, op, hexOperand);


                if (i > 0 && i < quantityofValues - 1) {
                    std::cout << "Intermediate result: " << decimalToHex(result) << std::endl;
                    std::cout << '\n';
                }
            }
            std::cout << "\n//////////////////////////////\nYour final result: " << decimalToHex(result) << "\n//////////////////////////////\n";

            break;





        //system dziesiatkowy
        case 4:

            for (int i = 0; i < quantityofValues; ++i) {

                char op;

                double operand = getFloatOperand(i);
                
                if (i > 0) {
                    op = getOperator();
                }
                else {
                    op = '+';
                }

                result = performOperation(result, op, operand);

                if (i > 0 && i < quantityofValues - 1) {
                    std::cout << "Intermediate result: " << result << std::endl;
                    std::cout << '\n';
                }
            }
            std::cout << "\n//////////////////////////////\nYour final result: " << result << "\n//////////////////////////////\n";

            break;

        default:

            std::cout << "Invalid number system." << std::endl;

            break;
        }

    }

    return 0;
}
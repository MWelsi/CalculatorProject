#include <iostream>

#include "Menu.h"



// Funcja wyswietlajaca menu

void displayMenu() {
    std::cout << "\n\n************************************\n"
        << "           CALCULATOR MENU          \n"
        << "************************************\n"
        << "1. Tutorial\n"
        << "2. Launch Calculator\n"
        << "3. Exit Program\n"
        << "************************************\n";
}


// Funkcja wyswietlajaca tutorial

void displayTutorial() {
    std::cout << "************************************\n"
        << "          CALCULATOR TUTORIAL       \n"
        << "************************************\n"
        << "1. Choose the number system (bin, oct, hex, float).\n"
        << "2. Specify the quantity of numbers for the operation.\n"
        << "3. Input each value and then the operator between them.\n"
        << "4. View intermediate results during calculation and final results after you are done.\n"
        << "************************************\n";
}


///////////////////////////////////////////////////////////
// Ta funkcja uruchamia menu kalkulatora i obs�uguje wybory u�ytkownika.
///////////////////////////////////////////////////////////
//		
// WEJ�CIE:
//      -u�ytkownik wewn�trz niej wprowadza informacje wej�ciowe (1-3).
//
// WYJ�CIE:
//    Zwraca warto�� logiczn�:
//      - kontynuuje gdy u�ytkownik wybierze tutorial (opcja 1),
//      - true, je�li u�ytkownik wybierze uruchomienie kalkulatora (opcja 2),
//      - false, je�li u�ytkownik wybierze wyj�cie z programu (opcja 3).
//		
// UWAGI:
//    Funkcja wy�wietla g��wne menu, prosi u�ytkownika o wprowadzenie.
//
//    Dla opcji 1 wy�wietla samouczek kalkulatora, prosi u�ytkownika o wci�ni�cie Enter
//    i ignoruje dodatkowe dane wej�ciowe do momentu naci�ni�cia klawisza Enter.
//    Dla opcji 2 zwraca true, wskazuj�c, �e u�ytkownik chce uruchomi� kalkulator.
//    Dla opcji 3 wy�wietla komunikat o wyj�ciu i zwraca false, aby zako�czy� program.
//    W przypadku nieprawid�owego wyboru wy�wietla komunikat b��du,
//    czy�ci bufor wej�ciowy i ignoruje dodatkowe dane wej�ciowe do momentu naci�ni�cia Enter.
//		

bool runCalculatorMenu() {

    char choice;

    do {

        displayMenu();

        std::cout << "\nEnter your choice (1, 2, or 3): ";
        std::cin >> choice;
        std::cout << '\n';

        switch (choice) {
        case '1':

            displayTutorial();


            std::cout << "Press Enter to continue...";

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            break;
        case '2':

            return true;

        case '3':

            std::cout << "Exiting calculator program. Goodbye!" << std::endl;
            return false;

        default:
            std::cout << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }


        std::cin.clear();
        while (std::cin.get() != '\n') {
            continue;
        }


    } while (choice != '3');

    return true;
}
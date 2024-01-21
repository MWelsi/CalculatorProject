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
// Ta funkcja uruchamia menu kalkulatora i obs³uguje wybory u¿ytkownika.
///////////////////////////////////////////////////////////
//		
// WEJŒCIE:
//      -u¿ytkownik wewn¹trz niej wprowadza informacje wejœciowe (1-3).
//
// WYJŒCIE:
//    Zwraca wartoœæ logiczn¹:
//      - kontynuuje gdy u¿ytkownik wybierze tutorial (opcja 1),
//      - true, jeœli u¿ytkownik wybierze uruchomienie kalkulatora (opcja 2),
//      - false, jeœli u¿ytkownik wybierze wyjœcie z programu (opcja 3).
//		
// UWAGI:
//    Funkcja wyœwietla g³ówne menu, prosi u¿ytkownika o wprowadzenie.
//
//    Dla opcji 1 wyœwietla samouczek kalkulatora, prosi u¿ytkownika o wciœniêcie Enter
//    i ignoruje dodatkowe dane wejœciowe do momentu naciœniêcia klawisza Enter.
//    Dla opcji 2 zwraca true, wskazuj¹c, ¿e u¿ytkownik chce uruchomiæ kalkulator.
//    Dla opcji 3 wyœwietla komunikat o wyjœciu i zwraca false, aby zakoñczyæ program.
//    W przypadku nieprawid³owego wyboru wyœwietla komunikat b³êdu,
//    czyœci bufor wejœciowy i ignoruje dodatkowe dane wejœciowe do momentu naciœniêcia Enter.
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
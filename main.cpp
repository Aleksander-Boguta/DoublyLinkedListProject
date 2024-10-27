#include "DoublyLinkedList.h"
#include <iostream>

void displayMenu() {
    std::cout << "\n--- Menu ---\n";
    std::cout << "1. Dodaj element na końcu\n";
    std::cout << "2. Dodaj element na początku\n";
    std::cout << "3. Dodaj element z zachowaniem porządku\n";
    std::cout << "4. Usuń pierwszy element\n";
    std::cout << "5. Usuń ostatni element\n";
    std::cout << "6. Znajdź element\n";
    std::cout << "7. Usuń element\n";
    std::cout << "8. Wyświetl listę\n";
    std::cout << "9. Wyczyść listę\n";
    std::cout << "10. Wyświetl listę jako tekst\n";
    std::cout << "0. Wyjdź\n";
    std::cout << "Wybierz opcję: ";
}

int main() {
    DoublyLinkedList<int> list;
    int option, value;

    do {
        displayMenu();
        std::cin >> option;

        switch(option) {
            case 1:
                std::cout << "Podaj wartość do dodania na końcu: ";
                std::cin >> value;
                list.addBack(value);
                break;

            case 2:
                std::cout << "Podaj wartość do dodania na początku: ";
                std::cin >> value;
                list.addFront(value);
                break;

            case 3:
                std::cout << "Podaj wartość do dodania z zachowaniem porządku: ";
                std::cin >> value;
                list.addSorted(value);
                break;

            case 4:
                list.removeFront();
                std::cout << "Pierwszy element został usunięty.\n";
                break;

            case 5:
                list.removeBack();
                std::cout << "Ostatni element został usunięty.\n";
                break;

            case 6:
                std::cout << "Podaj wartość do wyszukania: ";
                std::cin >> value;
                if (list.find(value) != nullptr) {
                    std::cout << "Znaleziono element: " << value << std::endl;
                } else {
                    std::cout << "Element nie znaleziony.\n";
                }
                break;

            case 7:
                std::cout << "Podaj wartość do usunięcia: ";
                std::cin >> value;
                if (list.findAndRemove(value)) {
                    std::cout << "Element " << value << " usunięty.\n";
                } else {
                    std::cout << "Element nie znaleziony.\n";
                }
                break;

            case 8:
                list.printList();
                break;

            case 9:
                list.clear();
                std::cout << "Lista została wyczyszczona.\n";
                break;

            case 10:
                std::cout << "Lista jako tekst: " << list.toString() << std::endl;
                break;

            case 0:
                std::cout << "Koniec programu.\n";
                break;

            default:
                std::cout << "Nieprawidłowa opcja. Spróbuj ponownie.\n";
        }
    } while (option != 0);

    return 0;
}
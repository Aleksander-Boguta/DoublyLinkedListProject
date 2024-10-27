#include "PerformanceTester.h"
#include "DoublyLinkedList.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

void measureTime() {
    DoublyLinkedList<int> list;
    const int numElements = 10000; // Liczba elementów do dodania w testach

    // Mierzenie czasu dodawania elementów
    clock_t start = clock();
    for (int i = 0; i < numElements; ++i) {
        list.addSorted(rand() % numElements);
    }
    clock_t end = clock();
    double addTime = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Czas dodawania " << numElements << " elementów: " << addTime << " sekund\n";

    // Mierzenie czasu wyszukiwania elementów
    start = clock();
    for (int i = 0; i < numElements / 10; ++i) { // Wyszukiwanie 10% elementów
        list.find(rand() % numElements);
    }
    end = clock();
    double findTime = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Czas wyszukiwania " << numElements / 10 << " elementów: " << findTime << " sekund\n";

    // Mierzenie czasu usuwania elementów
    start = clock();
    for (int i = 0; i < numElements / 10; ++i) { // Usuwanie 10% elementów
        list.findAndRemove(rand() % numElements);
    }
    end = clock();
    double removeTime = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Czas usuwania " << numElements / 10 << " elementów: " << removeTime << " sekund\n";
}
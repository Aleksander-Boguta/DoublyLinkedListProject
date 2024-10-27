#include "DoublyLinkedList.h"

// Konstruktor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Destruktor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
int DoublyLinkedList<T>::getSize() const { return size; }

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const { return size == 0; }

template <typename T>
void DoublyLinkedList<T>::addBack(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::addFront(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::removeFront() {
    if (isEmpty()) return;
    Node<T>* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::removeBack() {
    if (isEmpty()) return;
    Node<T>* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
T DoublyLinkedList<T>::get(int index) const {
    if (index < 0 || index >= size) throw std::out_of_range("Indeks poza zakresem");
    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
void DoublyLinkedList<T>::set(int index, T value) {
    if (index < 0 || index >= size) throw std::out_of_range("Indeks poza zakresem");
    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    current->data = value;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::find(T value) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == value) return current;
        current = current->next;
    }
    return nullptr;
}

template <typename T>
bool DoublyLinkedList<T>::findAndRemove(T value) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            if (current == head) {
                removeFront();
            } else if (current == tail) {
                removeBack();
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                size--;
            }
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void DoublyLinkedList<T>::printList() const {
    Node<T>* current = head;
    std::cout << "Lista: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Dodawanie elementu z zachowaniem porządku
template <typename T>
void DoublyLinkedList<T>::addSorted(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else if (head->data >= value) { // Dodawanie na początku
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (tail->data <= value) { // Dodawanie na końcu
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } else { // Dodawanie w środku
        Node<T>* current = head;
        while (current != nullptr && current->data < value) {
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    size++;
}

// Czyszczenie listy
template <typename T>
void DoublyLinkedList<T>::clear() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
    size = 0;
}

// Konwersja listy do postaci tekstowej
template <typename T>
std::string DoublyLinkedList<T>::toString() const {
    std::string result = "Lista: ";
    Node<T>* current = head;
    while (current != nullptr) {
        result += std::to_string(current->data) + " ";
        current = current->next;
    }
    return result;
}
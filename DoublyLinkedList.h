#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    int getSize() const;
    bool isEmpty() const;

    void addBack(T value);
    void addFront(T value);
    void removeFront();
    void removeBack();
    T get(int index) const;
    void set(int index, T value);
    Node<T>* find(T value) const;
    bool findAndRemove(T value);
    void printList() const;

    void addSorted(T value);
    void clear();
    std::string toString() const;
};

#include "DoublyLinkedList.cpp"  // Dołączenie implementacji

#endif
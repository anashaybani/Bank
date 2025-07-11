#pragma once


#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};


template <typename T>
class LinkedList
{
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    
    void add(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    
    bool remove(bool (*match)(T, string), string key) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current) {
            if (match(current->data, key)) {
                if (prev)
                    prev->next = current->next;
                else
                    head = current->next;

                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    
    T* search(bool (*match)(T, string), string key) {
        Node<T>* current = head;
        while (current) {
            if (match(current->data, key))
                return &(current->data);
            current = current->next;
        }
        return nullptr;
    }

   
    void display(void (*printFunc)(T)) {
        Node<T>* current = head;
        while (current) {
            printFunc(current->data);
            current = current->next;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }
};


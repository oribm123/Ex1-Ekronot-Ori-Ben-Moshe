#include "Stack.h"
#include <iostream>

// Push an element onto the stack (add to the start of the linked list)
void push(Stack* s, unsigned int element) {
    LinkedList* newNode = new LinkedList;
    newNode->value = element;
    newNode->next = s->first;
    s->first = newNode;
}

// Pop the top element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        std::cout << "Stack is empty, cannot pop!" << std::endl;
        return -1; // Indicating stack is empty
    }
    else {
        LinkedList* temp = s->first;
        int value = temp->value;
        s->first = s->first->next;
        delete temp;
        return value;
    }
}

// Initialize the stack (set the first pointer to nullptr)
void initStack(Stack* s) {
    s->first = nullptr;
}

// Free all elements in the stack
void cleanStack(Stack* s) {
    while (s->first != nullptr) {
        LinkedList* temp = s->first;
        s->first = s->first->next;
        delete temp;
    }
}

// Check if the stack is empty (if the first pointer is nullptr)
bool isEmpty(Stack* s) {
    return s->first == nullptr;
}

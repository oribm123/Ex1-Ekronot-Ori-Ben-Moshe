#include <iostream>
#include "LinkedList.h"

// Add a node at the start of the list
void addAtStart(LinkedList** head, int value) {
    LinkedList* newNode = new LinkedList;
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

// Remove the node at the start of the list
void removeAtStart(LinkedList** head) {
    if (*head == NULL) {
        std::cout << "Can't remove value, list is empty" << std::endl;
    }
    else {
        LinkedList* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}

// Free all nodes in the list
void freeList(LinkedList** head) {
    while (*head != nullptr) {
        LinkedList* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}


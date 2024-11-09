#include "LinkedList.h"
#include <iostream>

void addAtStart(LinkedList** head, int value) {
	LinkedList* newNode = new LinkedList;
	newNode->value = value;
	newNode->next = *head;
	*head = newNode;
}

void removeAtStart(LinkedList** head) {
	if (*head == NULL) {
		std::cout << "cant remove value, list is empty" << std::endl;
	}
	else {
		LinkedList* temp = *head;
		*head = (*head)->next;
		delete temp;
	}
}

void freeList(LinkedList** head) {
	while (*head != NULL) {
		LinkedList* temp = *head;
		*head = (*head)->next;
		delete temp;
	}
}
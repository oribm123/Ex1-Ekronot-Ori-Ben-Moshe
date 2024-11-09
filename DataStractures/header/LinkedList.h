#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList
{
	int value;
	LinkedList* next;

} LinkedList;

void addAtStart(LinkedList** head, int value);
void removeAtStart(LinkedList** head);
void freeList(LinkedList** head);

#endif
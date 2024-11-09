#include "Queue.h"
#include <iostream>

void initQueue(Queue* q, unsigned int size) {
	q->elements = new int[size];
	q->first = 0;
	q->last = -1;
	q->maxSize = size;
	q->size = 0;
}

void cleanQueue(Queue* q) {
	delete q->elements;
	q->elements = NULL;
	q->first = 0;
	q->last = -1;
	q->maxSize = 0;
	q->size = 0;
}

void enqueue(Queue* q, unsigned int newValue) {
	if (isFull(q)) {
		std::cout << "cant add value, queue is full" << std::endl;
	}
	else {
		q->last = (q->last + 1) % q->maxSize; //if at the end of array but not full then put at the start of array
		q->elements[q->last] = newValue;
		q->size++;
	}
}	

int dequeue(Queue* q) {
	if (isEmpty(q)) {
		std::cout << "cant get value, queue is empty" << std::endl;
		return -1;
	}
	else {
		int value = q->elements[q->first];
		q->elements[q->first] = 0;
		q->first = (q->first + 1) % q->maxSize; //if at the end of array but not empty then take from the start of array
		q->size--;
		return value;
	}
}

bool isEmpty(Queue* q) {
	return q->size == 0;
}

bool isFull(Queue* s) {
	return s->size == s->maxSize;
}
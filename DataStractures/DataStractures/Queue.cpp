#include "Queue.h"
#include <iostream>

// Initializes the queue with a given size.
void initQueue(Queue* q, unsigned int size) {
	q->elements = new int[size];
	q->first = 0;
	q->last = -1;
	q->maxSize = size;
	q->size = 0;
}

// Cleans up the queue, deleting the allocated memory.
void cleanQueue(Queue* q) {
	delete[] q->elements;
	q->elements = NULL;
	q->first = 0;
	q->last = -1;
	q->maxSize = 0;
	q->size = 0;
}

// Adds a new value to the queue if it's not full.
void enqueue(Queue* q, unsigned int newValue) {
	if (isFull(q)) {
		std::cout << "Can't add value, queue is full" << std::endl;
	}
	else {
		q->last = (q->last + 1) % q->maxSize; //wraps around the array 
		q->elements[q->last] = newValue;
		q->size++;
	}
}

// Removes and returns the front value of the queue if it's not empty.
int dequeue(Queue* q) {
	if (isEmpty(q)) {
		std::cout << "Can't get value, queue is empty" << std::endl;
		return -1;
	}
	else {
		int value = q->elements[q->first];
		q->elements[q->first] = 0;
		q->first = (q->first + 1) % q->maxSize;  //wraps around the array 
		q->size--;
		return value;
	}
}

// Checks if the queue is empty.
bool isEmpty(Queue* q) {
	return q->size == 0;
}

// Checks if the queue is full.
bool isFull(Queue* q) {
	return q->size == q->maxSize;
}

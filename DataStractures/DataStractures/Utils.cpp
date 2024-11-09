#include "Utils.h"
#include "Stack.h"
#include <iostream>

#define LEN 10

void reverse(int* nums, unsigned int size) {
	Stack s;
	int i = 0;
	initStack(&s);

	for (i = 0; i < size; i++) {
		push(&s, nums[i]);
	}
	for (i = 0; i < size; i++) {
		nums[i] = pop(&s);
	}
	cleanStack(&s);
}

int* reverse10() {
	int i = 0;
	int nums[LEN] = {0};
	for (i = 0; i < LEN; i++) {
		std::cin >> nums[i];
	}
	reverse(nums, LEN);
	return nums;
}
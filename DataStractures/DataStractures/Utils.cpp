#include "Utils.h"
#include "Stack.h"
#include <iostream>

#define LEN 10

// Reverses the elements of the array using a stack
void reverse(int* nums, unsigned int size) {
    Stack s;
    int i = 0;
    initStack(&s);

    // Push each element of the array onto the stack
    for (i = 0; i < size; i++) {
        push(&s, nums[i]);
    }

    // Pop elements from the stack and put them back into the array in reverse order
    for (i = 0; i < size; i++) {
        nums[i] = pop(&s);
    }

    // Clean up the stack after use to free memory
    cleanStack(&s);
}

// This function reverses an array that user enterd
int* reverse10() {
    int i = 0;
    int* nums = new int[LEN];  // Dynamically allocate memory for the array
    for (i = 0; i < LEN; i++) {
        std::cin >> nums[i];
    }

    // Reverse the array using the reverse function
    reverse(nums, LEN);

    // Return the dynamically allocated array
    return nums;
}

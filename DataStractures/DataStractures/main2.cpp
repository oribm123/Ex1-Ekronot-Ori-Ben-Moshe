#include "Stack.h"
#include <iostream>

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    std::cout << "Popped: " << pop(&s) << std::endl;
    std::cout << "Popped: " << pop(&s) << std::endl;

    cleanStack(&s);

    return 0;
}

#ifndef STACK_H
#define STACK_H

#include <string>
#define MAX 100

class Stack {
    int top;
    std::string arr[MAX];
public:
    Stack();
    void push(std::string x);
    void pop();
    void Browsing_history();
    bool isEmpty();
};

#endif#

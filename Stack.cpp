#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    top = -1;
}

void Stack::push(string x) {
    if (top >= MAX - 1) {
        cout << "Stack overflow\n";
        return;
    }
    top++;
    arr[top] = x;
}

void Stack::pop() {
    if (top < 0) {
        cout << "Stack underflow\n";
        return;
    }
    top--;
}

void Stack::Browsing_history() {
    if (top < 0) {
        cout << "Stack underflow\n";
        return;
    }
    cout << "Browsing history: " << endl;
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << endl;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}
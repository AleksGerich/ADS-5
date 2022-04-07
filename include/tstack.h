// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <iostream>

template<class T>
class TStack {
 public:
    TStack() :top(-1) { }
    T get() const {
        return arr[top];
    }
    bool isEmpty() const {
        return top == -1;
    }
    char pop() {
        if (top >= 0) {
            char a = arr[top];
            top--;
            return a;
        }
        return ' ';
    }
    void del() {
        top--;
    }
    void push(T item) {
        if (top < size - 1)
            arr[++top] = item;
    }
    bool tiptop() const {
        return arr[top] == '(';
    }
    int CPT() {
        const int pr = 2, len = 2;
        char priority[pr][len] = { {'+', '-'}, {'*', '/'} };
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (arr[top] == priority[i][j])
                    return i;
            }
        }
        return 0;
    }

 private:
     T arr[100];
     int top;
};
#endif  // INCLUDE_TSTACK_H_

// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <vector>
#include "alg.h"
#include "tstack.h"

int domath(char a, int *arr) {
    int res = 0;
    int p1 = arr[0];
    int p2 = arr[1];
    if (a == '+') {
        res = p1 + p2;
    }
    if (a == '-') {
        res = p2 - p1;
    }
    if (a == '*') {
        res = p1 * p2;
    }
    if (a == '/') {
        res = p2 / p1;
    }
    return res;
}
bool bratik(char a) {
    const int pr = 4;
    char priority[pr] = { '+', '-', '*', '/' };
    for (int i = 0; i < 4; i++) {
        if (a == priority[i])
            return 1;
    }
    return 0;
}
int CP(char a) {
    const int pr = 2, len = 2;
    char priority[pr][len] = { {'+', '-'}, {'*', '/'} };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a == priority[i][j])
                return i;
        }
    }
    return 0;
}
std::string infx2pstfx(std::string inf) {
    TStack<char> cstack;
    std::vector<char> queue;
    for (int i = 0; i < inf.size(); i++) {
        if (bratik(inf[i])) {
            if (cstack.isEmpty() || cstack.tiptop()) {
                cstack.push(inf[i]);
                continue;
            }
            if (CP(inf[i]) > cstack.CPT()) {
                cstack.push(inf[i]);
                continue;
            }
            if (CP(inf[i]) <= cstack.CPT()) {
                bool flag = 0;
                while (flag != 1) {
                    queue.push_back(cstack.pop());
                    if (cstack.isEmpty()) {
                        flag = 1;
                        cstack.push(inf[i]);
                    }
                    if (CP(inf[i]) > cstack.CPT() || cstack.tiptop()) {
                        cstack.push(inf[i]);
                        flag = 1;
                    }
                }
                continue;
            }
        }
        if (inf[i] == '(') {
            cstack.push(inf[i]);
            continue;
        }
        if (inf[i] == ')') {
            while (cstack.tiptop() != 1) {
                queue.push_back(cstack.pop());
            }
            cstack.del();
            continue;
        } else {
            queue.push_back(inf[i]);
        }
    }
    while (cstack.isEmpty() != 1) {
        queue.push_back(cstack.pop());
    }
    std::string end = "";
    for (int i = 0; i < queue.size(); i++) {
        end += queue[i];
        end += " ";
    }
    end.pop_back();
    return end;
}
int eval(std::string post) {
    TStack<int> istack;
    for (int i = 0; i < post.size(); i++) {
        if (post[i] == ' ') {
            continue;
        }
        if (bratik(post[i]) != 1) {
            istack.push(post[i] - 48);
            continue;
        }
        if (bratik(post[i])) {
            int arr[2];
            for (int i = 0; i < 2; i++) {
                arr[i] = istack.pop();
            }
            istack.push(domath(post[i], arr));
            continue;
        }
    }
    return (istack.get());
}

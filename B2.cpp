//
// Created by Lucas Vas on 10/11/2022.
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<string> substrings(string string1);

int main() {

    queue<string> all_subs = substrings("abcd");

    while (!all_subs.empty()) {
        cout << all_subs.front() << " ";
        all_subs.pop();
    }

    return 0;
}

queue<string> substrings(string string1) {
    queue<string> q;
    stack<string> holding;

    if(string1.length() <= 1) {
        q.push(string1);
        return q;
    }

    // constructs the stack
    holding.push(string1);
    while (string1.length() >= 1) {
        if (string1.length() == 1) {
            break;
        } if (string1.length() > 1) {
            string1.erase(0, 1);
            holding.push(string1);
        }
    }

    while (!holding.empty()) {
        string1 = holding.top();
        while(string1.length() >= 1) {
            q.push(string1);
            string1.pop_back();
        }
        holding.pop();
    }

    return q;
}

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int check(stack<string> s, string tmp) {
    int topF = 0, inF = 0;
    if (tmp == "true" || tmp == "false") {
        inF = 1;
    } else {
        inF = 2;
    }
    if (s.empty()) {
        if (inF == 2) {
            return 0;
        }
        return 1;
    }
    if (s.top() == "true" || s.top() == "false") {
        topF = 1;
    } else {
        topF = 2;
    }
    if (topF == inF) {
        return 0;
    } else if (s.top() == "and") {
        if ((s.size() & 1) != 0) {
            return 0;
        } else {
            return 2;
        }
    } else {
        return 1;
    }
    return 0;
}

int main() {
    string tmp = "";
    stack<string> s;
    while (cin.peek() != '\n') { // peek函数获得输入
        cin >> tmp;
        int f = check(s, tmp);
        if (f == 0) {
            cout << "error" << endl;
            return 0;
        } else if (f == 1) {
            s.push(tmp);
        } else if (f == 2) {
            s.pop();
            string tmp2 = s.top();
            s.pop();
            if (tmp2 == "true" && tmp == "true") {
                s.push("true");
            } else {
                s.push("false");
            }
        }
    }
    if ((s.size() & 1) != 1) {
        cout << "error" << endl;
        return 0;
    }
    while (!s.empty()) {
        if (s.top() == "true") {
            cout << "true" << endl;
            return 0;
        }
        s.pop();
    }
    cout << "false" << endl;
    return 0;
}
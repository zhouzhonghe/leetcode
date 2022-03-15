#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
根据 逆波兰表示法，求该后缀表达式的计算结果。
有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
*/
class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        s.push(stoi(tokens[0]));
        for (int i = 1; i < tokens.size(); i++) {
            if (tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-") {
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                if (tokens[i] == "/") {
                    s.push(x / y);
                } else if (tokens[i] == "*") {
                    s.push(x * y);
                } else if (tokens[i] == "+") {
                    s.push(x + y);
                } else if (tokens[i] == "-") {
                    s.push(x - y);
                }
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
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
请根据每日 气温 列表
temperatures ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，
至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0来代替。
*/
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> s;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                temperatures[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            temperatures[s.top()] = 0;
            s.pop();
        }
        return temperatures;
    }
};
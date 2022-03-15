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

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> tmp;
    int idx = 0;
    for (int i = 0; i < pushed.size(); i++) {
        tmp.push(pushed[i]);
        while (!tmp.empty() && tmp.top() == popped[idx]) {
            tmp.pop();
            idx++;
            cout << idx << endl;
        }
    }
    if (idx < popped.size())
        return false;
    else
        return true;
}

int main()
{
    vector<int> pushed{1, 2, 3, 4, 5};
    vector<int> popped{4, 5, 3, 2, 1};
    bool res = validateStackSequences(pushed, popped);
    cout << res << endl;
}
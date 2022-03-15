#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> findBuilding(vector<int> &heights) {
        // write code here
        vector<int> res(heights.size(), 1);
        stack<int> s1;
        for (int i = 0; i < heights.size() - 1; ++i) {
            while (!s1.empty() && heights[i] >= s1.top()) {
                s1.pop();
            }
            s1.push(heights[i]);
            res[i + 1] += s1.size();
        }
        stack<int> s2;
        for (int i = heights.size() - 1; i > 0; --i) {
            while (!s2.empty() && heights[i] >= s2.top()) {
                s2.pop();
            }
            s2.push(heights[i]);
            res[i - 1] += s2.size();
        }
        return res;
    }
};

int main() {
    Solution so;
    vector<int> heights{5, 3, 8, 3, 2, 5};
    vector<int> res = so.findBuilding(heights);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}